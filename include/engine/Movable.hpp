class Movable;

#pragma once

#include "Tickable.hpp"
#include "Field.hpp"

class Movable: Tickable {
 public:
  Movable(float x, float y, Field* ptr, bool fly, bool rooted, float sx, float sy);
  virtual void Move(float x, float y);
  void Tick() override;
  void IncSpeed(float x, float y);
  [[nodiscard]] virtual float GetX() const;
  [[nodiscard]] virtual float GetY() const;

  static float dist(const Movable& a, const Movable& b);

 protected:
  float x_;
  float y_;
  float speedX_ = 0.0;
  float speedY_ = 0.0;
  bool fly_;
  bool rooted_;
  Field* field_;
};
