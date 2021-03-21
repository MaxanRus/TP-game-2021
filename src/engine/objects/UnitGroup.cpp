#include "engine/objects/UnitGroup.hpp"
#include <iostream>

UnitGroup::UnitGroup(float power, float x, float y, Field* ptr) :
    WorldActor(x, y, ptr, false, false, 1, 1) {
  radius_ = 100.0;
  magnetic_power_ = 3.0;
  while (power > 0) {
    float p = 6.0 * (rand() % 1000) / 1000;
    power -= 1;
    units_.push_back(new Unit(p, "unit", x, y, ptr));
  }
}

void UnitGroup::Tick() {
  WorldActor::Tick();
  for (auto& it : units_) {
    if (Distance(*this, *it) <= radius_) {
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
  for (auto it = units_.begin(); it != units_.end(); ++it) {
    while (it != units_.end() && (*it)->GetLife() <= 0) {
      auto copy = it;
      ++it;
      units_.erase(copy);
    }
  }
}

void UnitGroup::Draw(int from_x, int from_y, int to_x, int to_y) const {
  for (auto it : units_) {
    it->Draw(to_x - from_x + it->GetX(), to_y - from_y + it->GetY(), it->GetPower());
  }
}
