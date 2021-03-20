class Player;

#pragma once

#include <engine/Drawable.hpp>
#include <engine/Field.hpp>
#include <engine/Movable.hpp>

class Player: public Drawable, public Movable {
 public:
  Player() = default;
  Player(float x, float y, Field* field, const std::string& img, bool fly = false, bool rooted = false);
  ~Player() override = default;

  void Stop();
  void SpeedSet(float x, float y);
  void SpeedInc(float x, float y);

  void Tick() override;

 private:
  float frameNumber_ = 0;
};
