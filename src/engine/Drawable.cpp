#include "engine/Drawable.hpp"
#include <Engine.hpp>

void Drawable::Draw(int x, int y, float size) const {
  Graphics::ResourceManager::GetImage(image_).Draw(Graphics::ResourceManager::GetWindow(),
                                                   Graphics::ResourceManager::GetShader("image"),
                                                   x, y, size);
}

const std::string& Drawable::GetImg() const {
  return image_;
}

void Drawable::SetImage(const std::string& img) {
  image_ = img;
}

Drawable::Drawable(const std::string& img) : image_(img) {
}

