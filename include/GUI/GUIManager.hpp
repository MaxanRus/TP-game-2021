#pragma once

#include <memory>
#include <vector>
#include "GUI/GUIWindow.hpp"
#include "Helpers/Vector2D.hpp"
#include "engine/Drawable.hpp"

namespace GUI {
class GUIManager {
 public:
  static GUIManager& GetGUIManager();
  void AddWindow(std::unique_ptr<GUIWindow>&&);
  bool Click(const Vector2Di& position);
  void Draw() const;
 private:
  GUIManager() = default;
  static inline std::unique_ptr<GUIManager> GUI_manager = nullptr;
  std::vector<std::unique_ptr<GUIWindow>> list_windows_;
};
}
