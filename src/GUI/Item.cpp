#include "GUI/Item.hpp"

void GUI::Item::Draw() {
  Graphics::ResourceManager::GetImage(name_image_).Draw(Graphics::ResourceManager::GetWindow(),
                                                        Graphics::ResourceManager::GetShader("image"),
                                                        position_);
}
