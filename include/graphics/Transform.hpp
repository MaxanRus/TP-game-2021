namespace Graphics {
class Transform;
}

#pragma once

#include <glm/gtc/type_ptr.hpp>

namespace Graphics {
class Transform {
 public:
  Transform() = default;
  Transform(const Transform&) = default;
  Transform& Scale(float scale);
  Transform& Scale(float scale_x, float scale_y);
  Transform& Move(float delta_x, float delta_y);
  Transform& Rotate(float degree);
  [[nodiscard]] const float* GetMatrix() const;
 private:
  glm::mat4 transform_ = glm::mat4(1.0f);
};
}
