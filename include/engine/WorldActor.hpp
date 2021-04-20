#pragma once

#include <Helpers/Vector2D.hpp>
#include "Field.hpp"

class WorldActor : Tickable {
 public:
  WorldActor(const Vector2Df& position, Field* ptr, bool fly, bool rooted, const Vector2Df& speed = Vector2Df());
  virtual void Move(const Vector2Df& a);
  void Tick() override;
  void IncSpeed(const Vector2Df& a);
  void SetSpeed(const Vector2Df& a);
  [[nodiscard]] virtual float GetX() const;
  [[nodiscard]] virtual float GetY() const;

  static float Distance(const WorldActor& first, const WorldActor& second);

 protected:
  Vector2Df position_;
  Vector2Df speed_;
  bool fly_;
  bool rooted_;
  Field* field_;
};
