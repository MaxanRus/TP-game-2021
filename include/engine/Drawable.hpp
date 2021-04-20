#pragma once

#include <string_view>
#include <Helpers/Vector2D.hpp>

class Drawable {
 public:
  Drawable() = default;
  explicit Drawable(const std::string_view& image);
  virtual void Draw(const Vector2Df& position, float power = 1.0) const;
  virtual ~Drawable() = default;

  [[nodiscard]] const std::string_view& GetImg() const;
  void SetImage(const std::string_view& image);

 private:
  std::string_view image_name_;
};
