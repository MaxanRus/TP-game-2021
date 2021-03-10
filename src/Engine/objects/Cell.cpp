#include "engine/objects/Cell.hpp"
#include <iostream>

void Cell::Draw(unsigned int x, unsigned int y) const {
  for (auto& it : items_) {
    it->Draw(x, y);
  }
}

float Cell::GetSpeed() const { return speed_; }
float Cell::GetPixelWidth() { return pixelWidth_; }
float Cell::GetPixelHeight() { return pixelHeight_; }
size_t Cell::GetSize() const { return items_.size(); }

void Cell::add(Ground* x) {
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
