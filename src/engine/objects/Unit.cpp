#include <Timer.hpp>
#include "engine/objects/Unit.hpp"
#include <iostream>

Unit::Unit(float power, const std::string_view& img, const Vector2Df& a,
           Field* ptr, bool fly, bool rooted, const Vector2Df& speed) :
    WorldActor(a, ptr, fly, rooted, speed),
    Drawable(img), power_(power), last_attack_(0) {
  damage_ = power;
  move_speed_ = 1.0;
  attack_speed_ = 100;
  last_attack_ = 0.0;
  life_ = power;
  randomize_ = 15.0;
}

void Unit::Tick() {
  WorldActor::Tick();
  auto time = Timer::GetTime();
  if (last_attack_ <= time) {
    last_attack_ = time + attack_speed_;
    auto ptr = field_->GetBuilding(position_);
    if (ptr != nullptr) {
      ptr->DealDamage(damage_);
    }
  }
}

void Unit::IncSpeedRandomly() {
  if (speed_.x * speed_.x + speed_.y * speed_.y >= 2 * randomize_) {
    if (speed_.x > 0) {
      speed_.x = std::min(0.f, speed_.x - randomize_ * (rand() % 1000) / 1000);
    } else {
      speed_.x = std::max(0.f, speed_.x + randomize_ * (rand() % 1000) / 1000);
    }
    if (speed_.y > 0) {
      speed_.y = std::min(0.f, speed_.y - randomize_ * (rand() % 1000) / 1000);
    } else {
      speed_.y = std::max(0.f, speed_.y + randomize_ * (rand() % 1000) / 1000);
    }
  } else {
    speed_.x += randomize_ * (rand() % 2000 - 1000) / 1000;
    speed_.y += randomize_ * (rand() % 2000 - 1000) / 1000;
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
