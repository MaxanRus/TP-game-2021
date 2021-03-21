class Water;

#pragma once

#include <engine/objects/ground/GroundWater.hpp>

class Water : public GroundWater {
 public:
  ~Water() override = default;
  explicit Water(const std::string& image_name);
  void Tick() override;

 private:

};
