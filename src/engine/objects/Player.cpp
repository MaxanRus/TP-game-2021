#include "engine/objects/Player.hpp"
#include <iostream>
#include <cmath>

void Player::Stop() {
  speed_.x = 0.0;
  speed_.y = 0.0;
  frame_number_ = 0;
}

void Player::SpeedSet(const Vector2Df& to) {
  speed_ = to;
}

void Player::SpeedInc(const Vector2Df& to) {
  speed_ += to;
}

void Player::Tick() {
  WorldActor::Tick();
  frame_number_ += Vector2Df::dist(speed_, {0, 0});
  speed_ *= 0.99;
}

Player::Player(const Vector2Df& position, Field* field, const std::string_view& img, bool fly, bool rooted) :
    WorldActor(position, field, fly, rooted), Drawable(img) {
}
