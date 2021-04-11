#pragma once

#include <engine/objects/ground/GroundEarth.hpp>

class Stone : public GroundEarth {
 public:
  ~Stone() override = default;
  explicit Stone(const std::string_view& image_name);
  void Tick() override;

 private:
};
