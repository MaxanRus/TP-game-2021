class Drawable;

#pragma once

#include <tuple>
#include <cmath>
#include <graphics/GShape.hpp>
#include "../graphics/ResourceManager.hpp"

class Drawable {
 public:
  Drawable() = default;
  explicit Drawable(const std::string& img);
  virtual void Draw(int x, int y, float power = 1.0) const;
  virtual ~Drawable() = default;

  [[nodiscard]] const std::string& GetImg() const;
  void SetImage(const std::string& img);

 private:
  std::string image_;
};
