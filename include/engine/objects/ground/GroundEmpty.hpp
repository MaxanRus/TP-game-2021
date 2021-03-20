class GroundEmpty;

#pragma once

#include <Console.hpp>

#include <engine/objects/Ground.hpp>

class GroundEmpty: public Ground {
 public:
  ~GroundEmpty() override = default;
  explicit GroundEmpty(const std::string& x);
  void Tick() override;
};
