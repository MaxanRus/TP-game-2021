#include "engine/WorldActor.hpp"
#include <cmath>

void WorldActor::Move(const Vector2Df& a) {
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
  auto newPos = position_ + speed_ * speed_coefficient;
  if (newPos.x < 0) {
    newPos.x = 0;
  }
  if (newPos.y < 0) {
    newPos.y = 0;
  }
  if (field_->GetBuilding(newPos) == nullptr || fly_) {
    position_ = newPos;
  }
}

void WorldActor::IncSpeed(const Vector2Df& a) {
  speed_ += a;
}

WorldActor::WorldActor(const Vector2Df& position, Field* ptr, bool fly, bool rooted, const Vector2Df& speed) :
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

void WorldActor::SetSpeed(const Vector2Df& a) {
  speed_ = a;
}
Vector2Df WorldActor::GetPosition() const {
  return position_;
}
