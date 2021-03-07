#include <Object.hpp>
#include <Field.hpp>

#pragma once

class Player: public Object {
 public:
  Player(float x, float y, Field* field, Graphics::Image* img, bool fly = false, bool rooted = false);
  ~Player() override = default;

  void MoveOn(float x, float y);
  void MoveTo(float x, float y);

  void Stop();
  void SpeedSet(float x, float y);
  void SpeedInc(float x, float y);

  void Tick() override;

 private:
  const static int img_ = Console::imgPlayer;

  float x_, y_;
  float speedX_ = 0.0, speedY_ = 0.0;
  Field* field_;
  bool fly_;
  bool rooted_;
  float frameNumber_ = 0;
};
