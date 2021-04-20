#pragma once

#include "Helpers/Vector2D.hpp"

namespace GUI {
class GUIWindow {
 public:
  virtual bool Click(const Vector2Di& position) = 0;
  virtual void Draw() = 0;
 private:
};
}
