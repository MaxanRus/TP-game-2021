class Ground;

#pragma once

#include <engine/Drawable.hpp>
#include <engine/Tickable.hpp>

class Ground: public Drawable, public Tickable {
 public:
  ~Ground() override = default;
  explicit Ground(const std::string& x);

 private:

};
