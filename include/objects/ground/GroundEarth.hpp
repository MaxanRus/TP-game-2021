#include <objects/Cell.hpp>
#include <graphics/GShape.hpp>

#pragma once

class GroundEarth: public Ground {
 public:
  ~GroundEarth() override = default;
  explicit GroundEarth(Graphics::Image* x);
 private:
};
