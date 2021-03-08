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
  const float* GetMatrix() const;
  friend Transform operator*(const Transform& a, const Transform& b) {
    return Transform(a.transform_ * b.transform_);
  }
 private:
  Transform(const glm::mat4& transfrom);

  glm::mat4 transform_ = glm::mat4(1.0f);
};
}
