#include "engine/objects/Player.hpp"
#include <iostream>

void Player::MoveOn(float x, float y) {
  /// TODO border out
  float speed;
  if (rooted_) {
    speed = 0.0;
  } else {
    if (fly_) {
      speed = 1.0;
    } else {
      speed = field_->GetCell(x, y).GetSpeed();
    }
  }
  x_ += x * speed;
  y_ += y * speed;
}

void Player::MoveTo(float x, float y) {
  /// TODO border out
  x_ = x;
  y_ = y;
}

void Player::Stop() {
  speedX_ = 0.0;
  speedY_ = 0.0;
  frameNumber_ = 0;
}

void Player::SpeedSet(float x, float y) {
  speedX_ = x;
  speedY_ = y;
}

void Player::SpeedInc(float x, float y) {
  speedX_ += x;
  speedY_ += y;
}

void Player::PrintSpeed() const {
  std::cout << speedX_ << " " << speedY_ << std::endl;
}

void Player::Tick() {
  x_ += speedX_;
  y_ += speedY_;
  frameNumber_ += sqrtf(x_ * x_ + y_ + y_);
}

Player::Player(float x, float y, Field* field, Graphics::Image* img, bool fly, bool rooted) :
    x_(x), y_(y), field_(field), fly_(fly), rooted_(rooted), Object(img),
    speedX_(0), speedY_(0) {
}

float Player::GetX() const {
  return x_;
}

float Player::GetY() const {
  return y_;
}
