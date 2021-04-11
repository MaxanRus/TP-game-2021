#include "engine/Drawable.hpp"
#include <Engine.hpp>
#include <graphics/ResourceManager.hpp>

void Drawable::Draw(int x, int y, float size) const {
  Graphics::ResourceManager::GetImage(image_).Draw(Graphics::ResourceManager::GetWindow(),
                                                   Graphics::ResourceManager::GetShader("image"),
                                                   x, y, size);
}

const std::string_view& Drawable::GetImg() const { return image_; }

void Drawable::SetImage(const std::string_view& image) { image_ = image; }

Drawable::Drawable(const std::string_view& image) : image_(image) {}

