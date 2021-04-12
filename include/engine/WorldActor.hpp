#pragma once

#include <Helpers/Vector2D.hpp>
#include "Field.hpp"

class WorldActor : Tickable {
 public:
  WorldActor(const Vector2D& position, Field* ptr, bool fly, bool rooted, const Vector2D& speed = Vector2D());
  virtual void Move(const Vector2D& a);
  void Tick() override;
  void IncSpeed(const Vector2D& a);
  void SetSpeed(const Vector2D& a);
  [[nodiscard]] virtual float GetX() const;
  [[nodiscard]] virtual float GetY() const;

  static float Distance(const WorldActor& first, const WorldActor& second);

 protected:
  Vector2D position_;
  Vector2D speed_;
  bool fly_;
  bool rooted_;
  Field* field_;
};
