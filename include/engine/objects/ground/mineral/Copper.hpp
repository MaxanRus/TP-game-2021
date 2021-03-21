class Copper;

#pragma once

#include <engine/objects/ground/Mineral.hpp>

class Copper : public Mineral {
 public:
  ~Copper() override = default;
  explicit Copper(const std::string& image_name);
  void Tick() override;

 private:
};
