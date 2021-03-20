#include "engine/Drawable.hpp"
#include <Engine.hpp>

void Drawable::Draw(int x, int y) const {
  ResourceManager::GetImage(image_)->Draw(ResourceManager::GetWindow(), ResourceManager::GetShader(), x, y);
}

void Drawable::Draw(std::pair<unsigned int, unsigned int> p) const {
  Draw(p.first, p.second);
}

const std::string& Drawable::GetImg() const {
  return image_;
}

void Drawable::SetImage(const std::string& img) {
  image_ = img;
}

Drawable::Drawable(const std::string& img): image_(img) {
}

