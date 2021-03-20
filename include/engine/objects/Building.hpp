class Building;

#pragma once

#include <engine/Drawable.hpp>
#include <engine/Tickable.hpp>

class Building: public Drawable, public Tickable {
 public:
  [[nodiscard]] float GetLife() const;
  void DealDamage(float damage);
  void Repare(float to);
  explicit Building(const std::string& img, float life);

 private:
  float life_;
  float max_life_;
};
