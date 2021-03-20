class Dirt;

#pragma once

#include <engine/objects/ground/GroundEarth.hpp>

class Dirt: public GroundEarth {
 public:
  ~Dirt() override = default;
  explicit Dirt(const std::string& x);
  void Tick() override;

 private:
};
