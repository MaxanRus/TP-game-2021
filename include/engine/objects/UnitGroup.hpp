class UnitGroup;

#pragma once

#include <engine/WorldActor.hpp>
#include "Unit.hpp"
#include <list>

class UnitGroup : public WorldActor {
 public:
  explicit UnitGroup(float power, float x, float y, Field* ptr);
  void Tick() override;
  void Draw(int from_x, int from_y, int to_x, int to_y) const;

 private:
  float radius_;
  float magnetic_power_;
  std::list<Unit*> units_;
};
