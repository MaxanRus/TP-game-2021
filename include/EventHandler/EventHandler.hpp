#pragma once

#include <functional>
#include "graphics/Window.hpp"
#include "Helpers/Vector2D.hpp"

class EventHandler {
 public:
  using EventTrigger = Graphics::Window::keys;

  EventHandler() = default;

  void AddEvent(EventTrigger trigger, std::function<void(EventTrigger, Vector2D)> function);
  // void EraseEvent(EventTrigger trigger, std::function<void(EventTrigger, Vector2D)> function);
  void TriggerAllEvents() const;
 private:
  std::vector<std::pair<EventTrigger, std::function<void(EventTrigger, Vector2D)>>> list_events_;
};