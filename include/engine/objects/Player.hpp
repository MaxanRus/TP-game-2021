class Player;

#pragma once

#include <engine/Object.hpp>
#include <engine/Field.hpp>

class Player: public Object {
 public:
  Player() = default;
  Player(float x, float y, Field* field, Graphics::Image* img, bool fly = false, bool rooted = false);
  ~Player() override = default;

  void MoveOn(float x, float y);
  void MoveTo(float x, float y);

  float GetX() const;
  float GetY() const;

  void Stop();
  void SpeedSet(float x, float y);
  void SpeedInc(float x, float y);

  void Tick() override;
  void PrintSpeed() const;

 private:
  float x_, y_;
  float speedX_ = 0.0, speedY_ = 0.0;
  Field* field_;
  bool fly_;
  bool rooted_;
  float frameNumber_ = 0;
};
