#include <Timer.hpp>
#include "engine/objects/Unit.hpp"

Unit::Unit(float power, const std::string& img, float x, float y,
           Field* ptr, bool fly, bool rooted, float sx, float sy):
    Movable(x, y, ptr, fly, rooted, sx, sy),
    Drawable(img), power_(power), last_attack_(0) {
  damage_ = power;
  move_speed_ = 1.0;
  attack_speed_ = 100;
  last_attack_ = 0.0;
  life_ = power;
  randomize_ = 1.0;
}

void Unit::Tick() {
  Movable::Tick();
  /// TODO deal damage on place
  auto time = Timer::GetTime();
  if (last_attack_ <= time) {
    last_attack_ = time + attack_speed_;
    auto ptr = field_->GetBuilding(x_, y_);
    if (!ptr) {
      ptr->DealDamage(damage_);
    }
  }
}

void Unit::IncSpeedRandomly(float x, float y) {
  speedX_ += x;
  speedY_ += y;

  speedX_ += randomize_ * 5.0 * ((rand() % 2000 - 1000) / 1000);
  speedY_ += randomize_ * 5.0 * ((rand() % 2000 - 1000) / 1000);
}

float Unit::GetLife() const {
  return life_;
}
