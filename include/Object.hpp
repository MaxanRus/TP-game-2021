#include <tuple>
#include <cmath>
#include <graphics/GShape.hpp>

#pragma once

class Object {
 public:
  Object() = default;
  explicit Object(Graphics::Image* img);
  virtual void Draw(unsigned int x, unsigned int y) const;
  virtual void Draw(std::pair<unsigned int, unsigned int> p) const;
  virtual ~Object() = default;
  virtual void Tick() = 0;

 private:
  Graphics::Image* img_;
};
