#include "engine/objects/Player.hpp"
#include <iostream>

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

void Player::Tick() {
  x_ += speedX_;
  y_ += speedY_;
  frameNumber_ += sqrtf(x_ * x_ + y_ + y_);
}

Player::Player(float x, float y, Field* field, const std::string& img, bool fly, bool rooted) :
    Movable(x, y, field, fly, rooted, 0, 0), Drawable(img) {
}
