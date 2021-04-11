#pragma once

#include <engine/objects/ground/GroundWater.hpp>

class Water : public GroundWater {
 public:
  Water(const std::string_view& image_name);
  ~Water() override = default;
  void Tick() override;

 private:

};
