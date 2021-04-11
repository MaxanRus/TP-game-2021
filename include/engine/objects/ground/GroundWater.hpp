#pragma once

#include <engine/objects/Ground.hpp>

class GroundWater : public Ground {
 public:
  ~GroundWater() override = default;
  explicit GroundWater(const std::string_view& image_name);
 private:
};
