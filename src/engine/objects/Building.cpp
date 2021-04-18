#include "engine/objects/Building.hpp"

#include <utility>

float Building::GetLife() const {
  return life_;
}

void Building::DealDamage(float damage) {
  life_ -= damage;
  if (life_ <= 0) {
    deleter_();
  }
}

Building::Building(const std::string_view& img, float life) : Drawable(img), life_(life), max_life_(life) {}

void Building::Repair(float to) {
  life_ += to;
  life_ = std::min(life_, max_life_);
}

#include <iostream>

void Building::Tick() {
  DealDamage(0.3);
}

Building::Building(const std::string_view& img, float life, std::function<void()> deleter) : Drawable(img), life_(life), deleter_(std::move(deleter)) {}
