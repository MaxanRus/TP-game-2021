#pragma once

#include <engine/Drawable.hpp>
#include <engine/Tickable.hpp>
#include <functional>

class Building : public Drawable, public Tickable {
 public:
  [[nodiscard]] float GetLife() const;
  void DealDamage(float damage);
  void Repair(float to);
  explicit Building(const std::string_view& img, float life, std::function<void()> deleter);
  void Tick() override;

 private:
  float life_;
  float max_life_;
  std::function<void()> deleter_;
};
