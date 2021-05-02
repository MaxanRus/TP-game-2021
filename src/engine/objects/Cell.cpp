#include "engine/objects/Cell.hpp"
#include <iostream>
#include <engine/objects/ground/GroundEarth.hpp>

void Cell::Draw(const Vector2Df& position, float scale) const {
  for (auto& it : items_) {
    it->Draw(position);
  }
  if (building_) {
    building_->Draw(position);
  }
}

float Cell::GetSpeed() const { return speed_coefficient_; }

size_t Cell::GetSize() const { return items_.size(); }

void Cell::Add(Ground* x) {
  if (!x) {
    throw std::invalid_argument("adding nullptr in Cell");
  }
  items_.emplace_back(x);
}

void Cell::Tick() {
  for (auto& it : items_) {
    it->Tick();
  }
  if (building_) {
    building_->Tick();
  }
}

Building*& Cell::GetBuilding() {
  return building_;
}

void Cell::SetBuilding(Building* x) {
  building_ = x;
}

bool Cell::isEarth() {
  for (auto i : items_) {
    if (!dynamic_cast<GroundEarth*>(i)) {
      return false;
    }
  }
  return true;
}