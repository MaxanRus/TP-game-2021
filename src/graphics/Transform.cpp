#include "graphics/Transform.hpp"

using namespace Graphics;

Transform& Transform::Scale(float scale) {
  transform_ = glm::scale(transform_, glm::vec3(scale, scale, 1.0));
  return *this;
}

Transform& Transform::Scale(float scale_x, float scale_y) {
  transform_ = glm::scale(transform_, glm::vec3(scale_x, scale_y, 1.0));
  return *this;
}

Transform& Transform::Move(float delta_x, float delta_y) {
  transform_ = glm::translate(transform_, glm::vec3(delta_x, delta_y, 0));
  return *this;
}

Transform& Transform::Rotate(float degree) {
  transform_ = glm::rotate(transform_, glm::radians(degree), glm::vec3(0.0, 0.0, 1.0));
  return *this;
}

const float* Transform::GetMatrix() const {
  return glm::value_ptr(transform_);
}
