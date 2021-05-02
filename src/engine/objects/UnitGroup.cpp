#include "engine/objects/UnitGroup.hpp"
#include <iostream>
#include <cmath>
#include "Engine.hpp"

UnitGroup::UnitGroup(float power, const Vector2Df& position, Field* ptr) :
    WorldActor(position, ptr, false, false, {1, 1}) {
  radius_ = 40.0;
  magnetic_power_ = 9.0;
  while (power > 0) {
    float p = 4.0 * (rand() % 1000) / 1000;
    power -= 1;
    units_.push_back(new Unit(p, "unit", position, ptr));
  }
}

void UnitGroup::Tick() {
  WorldActor::Tick();
  Vector2Df newSpeed = Engine::GetPlayer().GetPosition() - position_;
  newSpeed /= Vector2Df::dist({0, 0}, newSpeed);
  SetSpeed(newSpeed);
  for (auto& it : units_) {
    if (Distance(*this, *it) <= radius_) {
      it->IncSpeedRandomly();
      it->Tick();
    } else {
      float sx = it->GetX() - position_.x;
      float sy = it->GetY() - position_.y;
      float d = sqrtf(magnetic_power_ / sqrtf(sx * sx + sy * sy));
      sx *= d, sy *= d;
      it->SetSpeed(-Vector2Df(sx, sy));
      it->Tick();
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

void UnitGroup::Draw(const Vector2Df& from, const Vector2Df& to) const {
  for (auto it : units_) {
    it->Draw({to.x - from.x + it->GetX(), to.y - from.y + it->GetY()}, it->GetPower());
  }
}
