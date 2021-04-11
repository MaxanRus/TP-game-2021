#pragma once

#include <string_view>

class Drawable {
 public:
  Drawable() = default;
  explicit Drawable(const std::string_view& image);
  virtual void Draw(int x, int y, float power = 1.0) const;
  virtual ~Drawable() = default;

  [[nodiscard]] const std::string_view& GetImg() const;
  void SetImage(const std::string_view& image);

 private:
  std::string_view image_;
};
