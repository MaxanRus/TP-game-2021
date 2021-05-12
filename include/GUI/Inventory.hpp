#pragma once

#include <memory>
#include "graphics/GShape.hpp"
#include "graphics/ResourceManager.hpp"
#include "GUI/GUIWindow.hpp"
#include "GUI/Item.hpp"
#include "GUI/States.hpp"

namespace GUI {
class Inventory : public GUIWindow {
 public:
  Inventory() : shader_name_("shape") {
    auto window = Graphics::ResourceManager::GetWindow();
    auto[width, height] = window.GetSizeWindow();
    float k = 2 / 8.0;
    position_ = Vector2Di((1 - k) * width, k * height);
    window_ = std::make_unique<Graphics::Quadrangle>(Graphics::Quadrangle((1 - k) * width, k * height, width, k * height, width, 0, (1 - k) * width, 0));

    std::vector<std::string_view> list_blocks = {"drill", "empty", "wall"};
    for (size_t i = 0; i < list_blocks.size(); ++i) {
      auto[height_image, width_image] = Graphics::ResourceManager::GetImage(list_blocks[i]).GetSize();
      content_.push_back(std::make_unique<GUI::Item>(position_ + Vector2Di(5 + (5 + width_image) * i, -5 - height_image), list_blocks[i]));
    }
  }
  void Draw() override {
    window_->Draw(Graphics::ResourceManager::GetWindow(), Graphics::ResourceManager::GetShader(shader_name_), 0, 0);
    for (auto& i: content_) {
      i->Draw();
    }
  }
  bool Click(const Vector2Di& position) override {
    if (position.x > position_.x && position.y < position_.y) {
      for (auto& i: content_) {
        if (i->Click(position)) {
          return true;
        }
      }
      return true;
    }
    return false;
  }
 private:
  Vector2Di position_;
  std::string_view shader_name_;
  std::unique_ptr<Graphics::GShape> window_;
  std::vector<std::unique_ptr<GUI::GUIWindow>> content_;
};
}
