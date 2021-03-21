class Drawable;

#pragma once

#include <tuple>
#include <cmath>
#include <graphics/GShape.hpp>
#include "../graphics/ResourceManager.hpp"

class Drawable {
 public:
  Drawable() = default;
  explicit Drawable(const std::string& image);
  virtual void Draw(int x, int y, float power = 1.0) const;
  virtual ~Drawable() = default;

  [[nodiscard]] const std::string& GetImg() const;
  void SetImage(const std::string& image);

 private:
  std::string image_;
};
