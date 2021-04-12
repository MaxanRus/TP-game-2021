#include "engine/Drawable.hpp"
#include <Engine.hpp>
#include <graphics/ResourceManager.hpp>

void Drawable::Draw(const Vector2D& position, float size) const {
  Graphics::ResourceManager::GetImage(image_name_).Draw(Graphics::ResourceManager::GetWindow(),
                                                        Graphics::ResourceManager::GetShader("image"),
                                                        position.x, position.y, size);
}

const std::string_view& Drawable::GetImg() const { return image_name_; }

void Drawable::SetImage(const std::string_view& image) { image_name_ = image; }

Drawable::Drawable(const std::string_view& image) : image_name_(image) {}

