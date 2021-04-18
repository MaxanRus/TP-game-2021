#pragma once

#include <engine/WorldActor.hpp>

class Unit: public Drawable, public WorldActor {
 public:
  explicit Unit(float power, const std::string_view& img, const Vector2Df& a, Field* ptr,
                bool fly = true, bool rooted = false, const Vector2Df& speed = Vector2Df());
  void Tick() override;
  void IncSpeedRandomly();

  [[nodiscard]] float GetRandomize() const;
  [[nodiscard]] float GetPower() const;

  [[nodiscard]] float GetLife() const;

 private:
  float power_;
  float damage_;
  float move_speed_;
  unsigned attack_speed_;
  unsigned last_attack_;
  float life_;
  float randomize_;
};
