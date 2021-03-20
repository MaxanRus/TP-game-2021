class UnitGroup;

#pragma once

#include <engine/Movable.hpp>
#include "Unit.hpp"
#include <list>

class UnitGroup: public Movable {
 public:
  explicit UnitGroup(float power, float x, float y, Field* ptr);
  void Tick() override;
  void Draw(int fromX, int fromY, int toX, int toY) const;

 private:
  float radius_;
  float magnetic_power_;
  std::list<Unit*> units;
};
