#include "engine/WorldActor.hpp"
#include <cmath>

void WorldActor::Move(const Vector2D& a) {
  position_ = a;
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
      speed_coefficient = field_->GetCell(speed_).GetSpeed();
    }
  }
  position_.x += speed_.x * speed_coefficient;
  position_.y += speed_.y * speed_coefficient;
}

void WorldActor::IncSpeed(const Vector2D& a) {
  speed_ += a;
}

WorldActor::WorldActor(const Vector2D& position, Field* ptr, bool fly, bool rooted, const Vector2D& speed) :
    position_(position), field_(ptr), fly_(fly), rooted_(rooted), speed_(speed) {}

float WorldActor::Distance(const WorldActor& first, const WorldActor& second) {
  return sqrtf((first.position_.x - second.position_.x) * (first.position_.x - second.position_.x) +
               (first.position_.y - second.position_.y) * (first.position_.y - second.position_.y));
}

float WorldActor::GetX() const {
  return position_.x;
}

float WorldActor::GetY() const {
  return position_.y;
}

void WorldActor::SetSpeed(const Vector2D& a) {
  speed_ = a;
}
