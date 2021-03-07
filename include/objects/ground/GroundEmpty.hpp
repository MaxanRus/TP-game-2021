#include <Console.hpp>
#include <objects/Ground.hpp>

#pragma once

class GroundEmpty: public Ground {
 public:
  ~GroundEmpty() override = default;
};
