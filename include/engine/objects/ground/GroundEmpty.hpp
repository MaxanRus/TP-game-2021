#pragma once

#include <engine/objects/Ground.hpp>

class GroundEmpty : public Ground {
 public:
  ~GroundEmpty() override = default;
  explicit GroundEmpty(const std::string_view& image_name);
  void Tick() override;
};
