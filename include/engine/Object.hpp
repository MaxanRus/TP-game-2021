class Object;

#pragma once

#include <tuple>
#include <cmath>
#include <graphics/GShape.hpp>

class Object {
 public:
  Object() = default;
  explicit Object(Graphics::Image* img);
  virtual void Draw(unsigned int x, unsigned int y) const;
  virtual void Draw(std::pair<unsigned int, unsigned int> p) const;
  virtual ~Object() = default;
  virtual void Tick() = 0;

  [[nodiscard]] const Graphics::Image* GetImg() const;
  void SetImage(Graphics::Image* img);

 private:
  Graphics::Image* img_;
};
