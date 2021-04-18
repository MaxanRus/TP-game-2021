#pragma once

#include <engine/Drawable.hpp>
#include <engine/WorldActor.hpp>

class Player : public Drawable, public WorldActor {
 public:
  Player() = default;
  Player(const Vector2Df& position, Field* field, const std::string_view& img, bool fly = false, bool rooted = false);
  ~Player() override = default;

  void Stop();
  void SpeedSet(const Vector2Df& to);
  void SpeedInc(const Vector2Df& to);

  void Tick() override;

 private:
  float frame_number_ = 0;
};
