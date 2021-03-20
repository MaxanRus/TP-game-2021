class Mineral;

#pragma once

#include <engine/objects/Ground.hpp>

class Mineral: public Ground {
 public:
  ~Mineral() override = default;
  explicit Mineral(const std::string& x);
 private:
};
