#pragma once

#include <engine/Drawable.hpp>
#include <engine/Tickable.hpp>

class Ground : public Drawable, public Tickable {
 public:
  ~Ground() override = default;
  explicit Ground(const std::string_view& image_name);

 private:

};
