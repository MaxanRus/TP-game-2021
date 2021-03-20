#include "engine/Movable.hpp"

void Movable::Move(float x, float y) {
  x_ = x;
  y_ = y;
}

void Movable::Tick() {
  /// TODO border out
  float speed_coefficient;
  if (rooted_) {
    speed_coefficient = 0.0;
  } else {
    if (fly_) {
      speed_coefficient = 1.0;
    } else {
      speed_coefficient = field_->GetCell(speedX_, speedY_).GetSpeed();
    }
  }
  x_ += speedX_ * speed_coefficient;
  y_ += speedY_ * speed_coefficient;
}

void Movable::IncSpeed(float x, float y) {
  speedX_ += x;
  speedY_ += y;
}

Movable::Movable(float x, float y, Field* ptr, bool fly, bool rooted, float sx, float sy):
    x_(x), y_(y), field_(ptr), fly_(fly), rooted_(rooted), speedX_(sx), speedY_(sy) {
}
