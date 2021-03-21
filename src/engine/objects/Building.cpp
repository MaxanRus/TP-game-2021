#include "engine/objects/Building.hpp"

float Building::GetLife() const {
  /// TODO life_
  return 0;
}

void Building::DealDamage(float damage) {
  life_ -= damage;
}

Building::Building(const std::string& img, float life) : Drawable(img), life_(life), max_life_(life) {}

void Building::Repair(float to) {
  life_ += to;
  life_ = std::min(life_, max_life_);
}
