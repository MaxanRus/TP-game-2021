#pragma once

#include "graphics/ResourceManager.hpp"
#include "GUI/GUIWindow.hpp"
#include "Helpers/Vector2D.hpp"
#include "GUI/States.hpp"

namespace GUI {
class Item : public GUIWindow {
 public:
  Item(Vector2Di position, std::string_view name_image) : position_(position), name_image_(name_image) {}
  void Draw() override;
  bool Click(const Vector2Di& position) override {
    if (position.x >= position_.x && position.x <= (position_.x + Graphics::ResourceManager::GetImage(name_image_).GetSize().first) &&
        position.y >= position_.y && position.y <= (position_.y + Graphics::ResourceManager::GetImage(name_image_).GetSize().second)) {
      GUI::current_placed_block = name_image_;
      return true;
    }
    return false;
  }
 private:
  Vector2Di position_;
  std::string_view name_image_;
};
}
