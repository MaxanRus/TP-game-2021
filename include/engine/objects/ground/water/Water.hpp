class Water;

#pragma once

#include <engine/objects/ground/GroundWater.hpp>

class Water: public GroundWater {
 public:
  ~Water() override = default;
  explicit Water(const std::string& x);
  void Tick() override;

 private:

};
