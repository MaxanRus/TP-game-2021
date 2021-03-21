class Unit;

#pragma once

#include <engine/WorldActor.hpp>

class Unit: public Drawable, public WorldActor {
 public:
  explicit Unit(float power, const std::string& img, float x, float y, Field* ptr,
                bool fly = true, bool rooted = false, float sx = 0.0, float sy = 0.0);
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
