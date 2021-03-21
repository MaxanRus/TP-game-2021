#include <Timer.hpp>
#include "engine/objects/Unit.hpp"
#include <iostream>

Unit::Unit(float power, const std::string& img, float x, float y,
           Field* ptr, bool fly, bool rooted, float sx, float sy) :
    Movable(x, y, ptr, fly, rooted, sx, sy),
    Drawable(img), power_(power), last_attack_(0) {
  damage_ = power;
  move_speed_ = 1.0;
  attack_speed_ = 100;
  last_attack_ = 0.0;
  life_ = power;
  randomize_ = 15.0;
}

void Unit::Tick() {
  Movable::Tick();
  auto time = Timer::GetTime();
  if (last_attack_ <= time) {
    last_attack_ = time + attack_speed_;
    auto ptr = field_->GetBuilding(x_, y_);
    if (ptr != nullptr) {
      ptr->DealDamage(damage_);
    }
  }
}

void Unit::IncSpeedRandomly() {
  if (speedX_ * speedX_ + speedY_ * speedY_ >= 2 * randomize_) {
    if (speedX_ > 0) {
      speedX_ = std::min(0.f, speedX_ - randomize_ * (rand() % 1000) / 1000);
    } else {
      speedX_ = std::max(0.f, speedX_ + randomize_ * (rand() % 1000) / 1000);
    }
    if (speedY_ > 0) {
      speedY_ = std::min(0.f, speedY_ - randomize_ * (rand() % 1000) / 1000);
    } else {
      speedY_ = std::max(0.f, speedY_ + randomize_ * (rand() % 1000) / 1000);
    }
  } else {
    speedX_ += randomize_ * (rand() % 2000 - 1000) / 1000;
    speedY_ += randomize_ * (rand() % 2000 - 1000) / 1000;
  }
}

float Unit::GetRandomize() const {
  return randomize_;
}

float Unit::GetLife() const {
  return life_;
}

float Unit::GetPower() const {
  return power_;
}
