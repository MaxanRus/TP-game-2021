#include "engine/objects/UnitGroup.hpp"

UnitGroup::UnitGroup(float power, float x, float y, Field* ptr):
    Movable(x, y, ptr, false, false, 0, 0) {
  magnetic_power_ = 10;
  magnetic_radius_ = 20;
  while (power > 0) {
    float p = 2.0 * (rand() % 1000) / 1000;
    power -= p;
    /// TODO "enemy.png" to ResourceManager
    units.push_back(new Unit(p, "enemy.png", x, y, ptr));
  }
}

void UnitGroup::Tick() {
  Movable::Tick();
  for (auto& it : units) {
    float d = dist(*this, *it) - magnetic_radius_;
    it->IncSpeedRandomly(d*magnetic_power_*(x_ - it->GetX()), d*magnetic_power_*(y_ - it->GetY()));
    it->Tick();
  }
  for (auto it = units.begin(); it != units.end(); ++it) {
    while (it != units.end() && (*it)->GetLife() <= 0) {
      auto copy = it;
      ++it;
      units.erase(copy);
    }
  }
}

void UnitGroup::Draw(int x, int y) const {
  for (auto it : units) {
    it->Draw(x + (it->GetX() - x_), y + (it->GetY() - y_));
  }
}
