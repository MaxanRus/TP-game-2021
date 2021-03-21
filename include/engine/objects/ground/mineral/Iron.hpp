class Iron;

#pragma once

#include <engine/objects/ground/Mineral.hpp>

class Iron : public Mineral {
 public:
  ~Iron() override = default;
  explicit Iron(const std::string& image_name);
  void Tick() override;

 private:
};
