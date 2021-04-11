#pragma once

#include <engine/objects/ground/GroundEarth.hpp>

class Dirt : public GroundEarth {
 public:
  ~Dirt() override = default;
  explicit Dirt(const std::string_view& image_name);
  void Tick() override;

 private:
};
