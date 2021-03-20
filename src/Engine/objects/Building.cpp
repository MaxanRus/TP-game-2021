#include "engine/objects/Building.hpp"

float Building::GetLife() const {
  return life_;
}

void Building::DealDamage(float damage) {
  life_ -= damage;
}

Building::Building(const std::string& img, float life) : Drawable(img), life_(life), max_life_(life) {
}

void Building::Repare(float to) {
  life_ += to;
  life_ = std::min(life_, max_life_);
}
