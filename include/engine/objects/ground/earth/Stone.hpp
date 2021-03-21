class Stone;

#pragma once

#include <engine/objects/ground/GroundEarth.hpp>

class Stone : public GroundEarth {
 public:
  ~Stone() override = default;
  explicit Stone(const std::string& image_name);
  void Tick() override;

 private:
};
