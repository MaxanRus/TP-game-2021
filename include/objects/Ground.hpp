#include <Object.hpp>

#pragma once

class Ground: public Object {
 public:
  ~Ground() override = default;
  Ground(Graphics::Image* x);

 private:

};
