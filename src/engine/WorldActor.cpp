#include "engine/WorldActor.hpp"

void WorldActor::Move(float x, float y) {
  x_ = x;
  y_ = y;
}

void WorldActor::Tick() {
  /// TODO border out
  float speed_coefficient;
  if (rooted_) {
    speed_coefficient = 0.0;
  } else {
    if (fly_) {
      speed_coefficient = 1.0;
    } else {
      speed_coefficient = field_->GetCell(speed_x_, speed_y_).GetSpeed();
    }
  }
  x_ += speed_x_ * speed_coefficient;
  y_ += speed_y_ * speed_coefficient;
}

void WorldActor::IncSpeed(float x, float y) {
  speed_x_ += x;
  speed_y_ += y;
}

WorldActor::WorldActor(float x, float y, Field* ptr, bool fly, bool rooted, float sx, float sy) :
    x_(x), y_(y), field_(ptr), fly_(fly), rooted_(rooted), speed_x_(sx), speed_y_(sy) {}

float WorldActor::Distance(const WorldActor& first, const WorldActor& second) {
  return sqrtf((first.x_ - second.x_) * (first.x_ - second.x_) + (first.y_ - second.y_) * (first.y_ - second.y_));
}

float WorldActor::GetX() const {
  return x_;
}

float WorldActor::GetY() const {
  return y_;
}

void WorldActor::SetSpeed(float x, float y) {
  speed_x_ = x;
  speed_y_ = y;
}
