#pragma once

#include "Unit.hpp"
#include <list>

class UnitGroup : public WorldActor {
 public:
  explicit UnitGroup(float power, const Vector2Df& position, Field* ptr);
  void Tick() override;
  void Draw(const Vector2Df& from, const Vector2Df& to) const;

 private:
  float radius_;
  float magnetic_power_;
  std::list<Unit*> units_;
};
