#pragma once

#include <engine/objects/Ground.hpp>

class GroundEarth : public Ground {
 public:
  ~GroundEarth() override = default;
  explicit GroundEarth(const std::string_view& image_name);
 private:
};
