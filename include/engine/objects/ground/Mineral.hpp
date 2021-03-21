class Mineral;

#pragma once

#include <engine/objects/Cell.hpp>

class Mineral : public Ground {
 public:
  ~Mineral() override = default;
  explicit Mineral(const std::string& image_name);
 private:
};
