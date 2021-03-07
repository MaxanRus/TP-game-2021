#include <Object.hpp>
#include <objects/ground/GroundEarth.hpp>

#pragma once

class Stone: public GroundEarth {
 public:
  ~Stone() override = default;
  explicit Stone(Graphics::Image* x);
 private:
};
