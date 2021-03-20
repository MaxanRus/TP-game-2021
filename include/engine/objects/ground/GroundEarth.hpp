class GroundEarth;

#pragma once

#include <engine/objects/Cell.hpp>

class GroundEarth: public Ground {
 public:
  ~GroundEarth() override = default;
  explicit GroundEarth(const std::string& x);
 private:
};
