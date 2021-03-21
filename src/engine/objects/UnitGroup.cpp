#include "engine/objects/UnitGroup.hpp"
#include <iostream>

UnitGroup::UnitGroup(float power, float x, float y, Field* ptr) :
    Movable(x, y, ptr, false, false, 1, 1) {
  radius_ = 100.0;
  magnetic_power_ = 3.0;
  while (power > 0) {
    float p = 4.0 * (rand() % 1000) / 1000;
    power -= 1;
    units.push_back(new Unit(p, "unit", x, y, ptr));
  }
}

void UnitGroup::Tick() {
  Movable::Tick();
  for (auto& it : units) {
    if (dist(*this, *it) <= radius_) {
      it->IncSpeedRandomly();
      it->Tick();
    } else {
      float sx = it->GetX() - x_;
      float sy = it->GetY() - y_;
      float d = sqrtf(magnetic_power_ / sqrtf(sx * sx + sy * sy));
      sx *= d, sy *= d;
      it->IncSpeed(-sx, -sy);
      it->Tick();
      it->IncSpeed(0, 0);
    }
  }
  for (auto it = units.begin(); it != units.end(); ++it) {
    while (it != units.end() && (*it)->GetLife() <= 0) {
      auto copy = it;
      ++it;
      units.erase(copy);
    }
  }
}

void UnitGroup::Draw(int fromX, int fromY, int toX, int toY) const {
  for (auto it : units) {
    it->Draw(toX - fromX + it->GetX(), toY - fromY + it->GetY(), it->GetPower());
  }
}
