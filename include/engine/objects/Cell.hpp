class Cell;

#pragma once

#include <engine/Object.hpp>
#include <vector>

#include "Ground.hpp"

class Cell: public Object {
 public:
  [[nodiscard]] float GetSpeed() const;

  Cell() = default;
  Cell(const Cell&) = default;
  Cell& operator=(const Cell&) = default;

  ~Cell() override = default;

  [[nodiscard]] static float GetPixelWidth();
  [[nodiscard]] static float GetPixelHeight();

  void add(Ground* x);
  [[nodiscard]] size_t GetSize() const;

  void Draw(unsigned x, unsigned y) const override;
  void Tick() override;

 private:
  /// may be bad
  constexpr static float pixelWidth_ = 32;
  constexpr static float pixelHeight_ = 32;

  float speed_ = 1.0;

  std::vector<Ground*> items_;
};
