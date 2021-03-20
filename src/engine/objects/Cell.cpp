#include "engine/objects/Cell.hpp"
#include <iostream>

void Cell::Draw(int x, int y) const {
  for (auto& it : items_) {
    it->Draw(x, y);
  }
  if (building_) {
    building_->Draw(x, y);
  }
}

float Cell::GetSpeed() const { return speed_; }

size_t Cell::GetSize() const { return items_.size(); }

void Cell::Add(Ground* x) {
  if (!x) {
    throw std::runtime_error("adding nullptr in Cell");
  }
  items_.emplace_back(x);
}

void Cell::Tick() {
  for (auto& it : items_) {
    it->Tick();
  }
}

Building* Cell::GetBuilding() const {
  return building_;
}

void Cell::SetBuilding(Building* x) {
  building_ = x;
}
