#include "engine/objects/Building.hpp"

float Building::GetLife() const {
  return life_;
}

void Building::DealDamage(float damage) {
  life_ -= damage;
}

Building::Building(const std::string_view& img, float life) : Drawable(img), life_(life), max_life_(life) {}

void Building::Repair(float to) {
  life_ += to;
  life_ = std::min(life_, max_life_);
}

void Building::Tick() {
  DealDamage(0.3);
}
