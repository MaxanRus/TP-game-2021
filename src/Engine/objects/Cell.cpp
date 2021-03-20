#include "engine/objects/Cell.hpp"
#include <iostream>

void Cell::Draw(int x, int y) const {
  for (auto& it : items_) {
    it->Draw(x, y);
  }
}

float Cell::GetSpeed() const { return speed_; }

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

void add_all() {}
template<typename T, typename... Args>
void add_all(T t, Args... args) {
  add(t);
  add_all(args...);
}

template<typename... Args>
Cell::Cell(Args... args) {
  add_all(args...);
}
