#include "GUI/GUIManager.hpp"

GUI::GUIManager& GUI::GUIManager::GetGUIManager() {
  if (!GUI_manager) GUI_manager = std::make_unique<GUIManager>(GUIManager());
  return *GUI_manager;
}

void GUI::GUIManager::AddWindow(std::unique_ptr<GUIWindow>&& something) {
  list_windows_.push_back(std::move(something));
}

bool GUI::GUIManager::Click(const Vector2Di& position) {
  for (auto& i: list_windows_) {
    if (i->Click(position))
      return true;
  }
  return false;
}

void GUI::GUIManager::Draw() const {
  for (auto& i: list_windows_) {
    i->Draw();
  }
}
