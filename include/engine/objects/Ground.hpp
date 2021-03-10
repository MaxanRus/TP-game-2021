class Ground;

#pragma once

#include <engine/Object.hpp>

class Ground: public Object {
 public:
  ~Ground() override = default;
  Ground();
  explicit Ground(Graphics::Image* x);

 private:

};
