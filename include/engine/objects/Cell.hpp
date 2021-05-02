#pragma once

#include <engine/Drawable.hpp>
#include <engine/Tickable.hpp>
#include <vector>
#include "Ground.hpp"
#include "Building.hpp"

class Cell : public Drawable, public Tickable {
 public:
  Cell() = default;
  Cell(const Cell&) = default;
  Cell& operator=(const Cell&) = default;
  ~Cell() override = default;

  void Add(Ground* x);
  void SetBuilding(Building* x);
  [[nodiscard]] float GetSpeed() const;
  [[nodiscard]] size_t GetSize() const;

  [[nodiscard]] Building*& GetBuilding();

  void Draw(const Vector2Df& position, float scale = 1.0) const override;
  void Tick() override;

  bool isEarth();

 private:
  float speed_coefficient_ = 1.0;

  std::vector<Ground*> items_;
  Building* building_ = nullptr;
};
