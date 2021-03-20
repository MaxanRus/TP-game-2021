class Cell;

#pragma once

#include <engine/Drawable.hpp>
#include <vector>
#include <engine/Tickable.hpp>
#include "Ground.hpp"
#include "Building.hpp"

class Cell: public Drawable, public Tickable {
 public:
  Cell() = default;
  Cell(const Cell&) = default;
  Cell& operator=(const Cell&) = default;
  ~Cell() override = default;

  void Add(Ground* x);
  void SetBuilding(Building* x);
  [[nodiscard]] float GetSpeed() const;
  [[nodiscard]] size_t GetSize() const;

  [[nodiscard]] Building* GetBuilding() const;

  void Draw(int x, int y) const;
  void Tick() override;

 private:
  float speed_ = 1.0;

  std::vector<Ground*> items_;
  Building* building_ = nullptr;
};
