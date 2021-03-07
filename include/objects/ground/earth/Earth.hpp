#include <objects/ground/GroundEarth.hpp>

#pragma once

class Earth: public GroundEarth {
 public:
  ~Earth() override = default;
  explicit Earth(Graphics::Image* x);

 private:

};
