class Drawable;

#pragma once

#include <tuple>
#include <cmath>
#include <graphics/GShape.hpp>

class Drawable {
 public:
  explicit Drawable(const std::string& img);
  virtual void Draw(int x, int y) const;
  virtual void Draw(std::pair<unsigned int, unsigned int> p) const;
  virtual ~Drawable() = default;

  [[nodiscard]] const std::string& GetImg() const;
  void SetImage(const std::string& img);

 private:
  std::string image_;
};
