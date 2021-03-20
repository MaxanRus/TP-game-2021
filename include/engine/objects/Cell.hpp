class Cell;

#pragma once

#include <engine/Drawable.hpp>
#include <vector>
#include <engine/Tickable.hpp>
#include "Ground.hpp"

class Cell: public Drawable, public Tickable {
 public:
  Cell() = default;
  ~Cell() override = default;

  void Add(Ground* x);
  [[nodiscard]] float GetSpeed() const;
  [[nodiscard]] size_t GetSize() const;

  void Draw(int x, int y) const override;
  void Tick() override;

 private:
  float speed_ = 1.0;

  std::vector<Ground*> items_;
};
