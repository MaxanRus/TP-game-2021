#include "engine/objects/Player.hpp"
#include <iostream>
#include <cmath>

void Player::Stop() {
  speed_x_ = 0.0;
  speed_y_ = 0.0;
  frame_number_ = 0;
}

void Player::SpeedSet(float x, float y) {
  speed_x_ = x;
  speed_y_ = y;
}

void Player::SpeedInc(float x, float y) {
  speed_x_ += x;
  speed_y_ += y;
}

void Player::Tick() {
  x_ += speed_x_;
  y_ += speed_y_;
  frame_number_ += sqrt(x_ * x_ + y_ + y_);
}

Player::Player(float x, float y, Field* field, const std::string_view& img, bool fly, bool rooted) :
    WorldActor(x, y, field, fly, rooted), Drawable(img) {
}
