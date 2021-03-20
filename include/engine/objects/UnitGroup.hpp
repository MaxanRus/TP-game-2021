class UnitGroup;

#pragma once

#include <engine/Movable.hpp>
#include "Unit.hpp"
#include <list>

class UnitGroup: Movable {
 public:
  explicit UnitGroup(float power, float x, float y, Field* ptr);
  void Tick() override;
  void Draw(int x, int y) const;

 private:
  float magnetic_radius_;
  float magnetic_power_;
  std::list<Unit*> units;
};
