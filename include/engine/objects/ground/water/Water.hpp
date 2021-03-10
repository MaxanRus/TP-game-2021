class Water;

#pragma once

#include <engine/objects/ground/GroundWater.hpp>

class Water: public GroundWater {
 public:
  ~Water() override = default;
  explicit Water(Graphics::Image* x);
  void Tick() override;

 private:

};
