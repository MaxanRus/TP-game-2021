#include "engine/Object.hpp"
#include <Engine.hpp>

void Object::Draw(unsigned int x, unsigned int y) const {
  Graphics::Transform transform;
  auto[wi, hi] = img_->GetSize();
  transform.Move(x, y);
  transform.Scale(10);
  transform.Rotate(glfwGetTime() * 100);
  transform.Move(-(float) wi / 2, -(float) hi / 2);
  img_->Draw(*Engine::GetWindow(), *Engine::GetImageShader(), transform);
}
void Object::Draw(std::pair<unsigned int, unsigned int> p) const {
  Draw(p.first, p.second);
}
Object::Object(Graphics::Image* img): img_(img) {
}
const Graphics::Image *Object::GetImg() const {
  return img_;
}
void Object::SetImage(Graphics::Image *img) {
  img_ = img;
}
