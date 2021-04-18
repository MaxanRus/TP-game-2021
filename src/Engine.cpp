#include "Engine.hpp"
#include <iostream>
#include <graphics/ResourceManager.hpp>

Engine* Engine::ptr = nullptr;

Engine::Engine(uint32_t width, uint32_t height, const std::string_view& path_file) :
    player_({200, 200}, &field_, "player"),
    field_(width, height, path_file) {
  enemies.push_back(new UnitGroup(100, Vector2Df{30.0, 30.0}, &field_));
  using Trigger = EventHandler::EventTrigger;
  auto& event_handler = Graphics::ResourceManager::GetEventHandler();
  event_handler.AddEvent(Trigger::A, [this](Trigger, Vector2Df) -> void {
    player_.SpeedInc(Vector2Df(-1, 0));
  });
  event_handler.AddEvent(Trigger::W, [this](Trigger, Vector2Df) -> void {
    player_.SpeedInc(Vector2Df(0, 1));
  });
  event_handler.AddEvent(Trigger::S, [this](Trigger, Vector2Df) -> void {
    player_.SpeedInc(Vector2Df(0, -1));
  });
  event_handler.AddEvent(Trigger::D, [this](Trigger, Vector2Df) -> void {
    player_.SpeedInc(Vector2Df(1, 0));
  });
  event_handler.AddEvent(Trigger::LEFT_MOUSE, [this](Trigger, Vector2Df cursor_position) -> void {
    Vector2Df(Graphics::ResourceManager::GetWindow().GetSizeWindow());
    int x = field_.GetCellPos(cursor_position + Vector2Df(player_.GetX(), player_.GetY()) - Vector2Df(Graphics::ResourceManager::GetWindow().GetSizeWindow()) / 2).first;
    int y = field_.GetCellPos(-cursor_position + Vector2Df(player_.GetX(), player_.GetY()) + Vector2Df(Graphics::ResourceManager::GetWindow().GetSizeWindow()) / 2).second;
    field_[x][y].SetBuilding(new Building("wall", 200, [this, x, y]() {
      delete field_[x][y].GetBuilding();
      field_[x][y].GetBuilding() = nullptr;
    }));
  });
}

void Engine::Tick() {
  player_.Tick();
  field_.Tick();
  for (auto& it : enemies) {
    it->Tick();
  }
}

void Engine::Draw() const {
  field_.Draw({player_.GetX(), player_.GetY()},
              {(float) (Graphics::ResourceManager::GetWindow().GetSizeWindow().first / 2),
               (float) (Graphics::ResourceManager::GetWindow().GetSizeWindow().second / 2)});
  player_.Draw({(float) (Graphics::ResourceManager::GetWindow().GetSizeWindow().first / 2),
                (float) (Graphics::ResourceManager::GetWindow().GetSizeWindow().second / 2)});
  for (auto& it : enemies) {
    it->Draw({player_.GetX(), player_.GetY()},
             {(float)(Graphics::ResourceManager::GetWindow().GetSizeWindow().first / 2),
              (float)(Graphics::ResourceManager::GetWindow().GetSizeWindow().second / 2)});
  }
  Graphics::ResourceManager::GetWindow().Render();
}

Engine* Engine::GetEngine(uint32_t width, uint32_t height, const std::string_view& file) {
  if (!ptr)
    ptr = new Engine(width, height, file);
  return ptr;
}
