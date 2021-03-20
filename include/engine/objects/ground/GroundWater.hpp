class GroundWater;

#pragma once

#include <engine/objects/Cell.hpp>

class GroundWater: public Ground {
 public:
  ~GroundWater() override = default;
  explicit GroundWater(const std::string& x);
 private:
};
