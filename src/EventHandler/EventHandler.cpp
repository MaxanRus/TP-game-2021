#include "EventHandler/EventHandler.hpp"
#include "graphics/ResourceManager.hpp"
#include <algorithm>

#include <iostream>

void EventHandler::AddEvent(EventHandler::EventTrigger trigger, std::function<void(EventTrigger, Vector2D)> function) {
  list_events_.emplace_back(trigger, function);
}

void EventHandler::TriggerAllEvents() const {
  auto& window = Graphics::ResourceManager::GetWindow();
  for (auto& i: list_events_) {
    if (window.CheckPressButton(i.first)) {
      i.second(i.first, Vector2D(window.GetCursorPosition()));
    }
  }
}

/*
void EventHandler::EraseEvent(EventHandler::EventTrigger trigger,
                              std::function<void(EventTrigger, Vector2D)> function) {
  list_events_.erase(std::find(list_events_.begin(), list_events_.end(), std::make_pair(trigger, function)));
}
 */
