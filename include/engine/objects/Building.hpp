#pragma once

#include <engine/Drawable.hpp>
#include <engine/Tickable.hpp>

class Building : public Drawable, public Tickable {
 public:
  [[nodiscard]] float GetLife() const;
  void DealDamage(float damage);
  void Repair(float to);
  explicit Building(const std::string_view& img, float life);

 private:
  float life_;
  float max_life_;
};
