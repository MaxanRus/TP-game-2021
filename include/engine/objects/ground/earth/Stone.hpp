class Stone;

#pragma once

#include <engine/Object.hpp>
#include <engine/objects/ground/GroundEarth.hpp>

class Stone: public GroundEarth {
 public:
  ~Stone() override = default;
  explicit Stone(Graphics::Image* x);
  void Tick() override;

 private:
};
