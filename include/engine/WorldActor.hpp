#pragma once

#include "Field.hpp"

class WorldActor : Tickable {
 public:
  WorldActor(float x, float y, Field* ptr, bool fly, bool rooted, float sx = 0.0, float sy = 0.0);
  virtual void Move(float x, float y);
  void Tick() override;
  void IncSpeed(float x, float y);
  void SetSpeed(float x, float y);
  [[nodiscard]] virtual float GetX() const;
  [[nodiscard]] virtual float GetY() const;

  static float Distance(const WorldActor& first, const WorldActor& second);

 protected:
  float x_;
  float y_;
  float speed_x_ = 0.0;
  float speed_y_ = 0.0;
  bool fly_;
  bool rooted_;
  Field* field_;
};
