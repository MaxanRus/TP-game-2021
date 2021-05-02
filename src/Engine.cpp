#include "Engine.hpp"
#include <graphics/ResourceManager.hpp>
#include "GUI/GUIManager.hpp"
#include "GUI/States.hpp"
#include "ConstantsManager.hpp"

Engine* Engine::ptr = nullptr;
Player* Engine::player_ = nullptr;

Engine::Engine(uint32_t width, uint32_t height, const std::string_view& path_file) :
    field_(width, height, path_file) {
  Engine::player_ = new Player({1000, 1000}, &field_, "player", true);
  using Trigger = EventHandler::EventTrigger;
  auto& event_handler = Graphics::ResourceManager::GetEventHandler();
  event_handler.AddEvent(Trigger::A, [](Trigger, Vector2Df) -> void {
    Engine::GetPlayer().SpeedInc(Vector2Df(-1, 0));
  });
  event_handler.AddEvent(Trigger::W, [](Trigger, Vector2Df) -> void {
    Engine::GetPlayer().SpeedInc(Vector2Df(0, 1));
  });
  event_handler.AddEvent(Trigger::S, [](Trigger, Vector2Df) -> void {
    Engine::GetPlayer().SpeedInc(Vector2Df(0, -1));
  });
  event_handler.AddEvent(Trigger::D, [](Trigger, Vector2Df) -> void {
    Engine::GetPlayer().SpeedInc(Vector2Df(1, 0));
  });
  event_handler.AddEvent(Trigger::LEFT_MOUSE, [this](Trigger, const Vector2Df& cursor_position) -> void {
    if (GUI::GUIManager::GetGUIManager().Click(Vector2Di(cursor_position))) {
    } else {
      Vector2Df(Graphics::ResourceManager::GetWindow().GetSizeWindow());
      int x = field_.GetCellPos(cursor_position + Vector2Df(Engine::GetPlayer().GetX(), Engine::GetPlayer().GetY())
                                    - Vector2Df(Graphics::ResourceManager::GetWindow().GetSizeWindow()) / 2).first;
      int y = field_.GetCellPos(cursor_position + Vector2Df(Engine::GetPlayer().GetX(), Engine::GetPlayer().GetY())
                                    - Vector2Df(Graphics::ResourceManager::GetWindow().GetSizeWindow()) / 2).second;
      if (x >= 0 && y >= 0 && x < field_.GetWidth() && y < field_.GetHeight() && field_[x][y].isEarth()) {
        field_[x][y].SetBuilding(new Building(GUI::current_placed_block, 1000, [this, x, y]() {
          delete field_[x][y].GetBuilding();
          field_[x][y].GetBuilding() = nullptr;
        }));
      }
    }
  });
}

void Engine::NewEnemy(float power) {
  Vector2Df pos;
  int c = rand() % 4;
  if (c == 1) {
    pos = {10, rand() % (field_.GetHeight() * ConstantsManager::kSizeCell)};
  }
  if (c == 2) {
    pos = {field_.GetWidth() * ConstantsManager::kSizeCell - 10, rand() % (field_.GetHeight() * ConstantsManager::kSizeCell)};
  }
  if (c == 3) {
    pos = {rand() % (field_.GetWidth() * ConstantsManager::kSizeCell), 10};
  }
  if (c == 4) {
    pos = {rand() % (field_.GetWidth() * ConstantsManager::kSizeCell), field_.GetHeight() * ConstantsManager::kSizeCell - 10};
  }
  enemies.push_back(new UnitGroup(50, pos, &field_));
}

void Engine::Tick() {
  if (rand() % 1000 == 0) {
    NewEnemy(50);
  }
  Engine::GetPlayer().Tick();
  field_.Tick();
  for (auto& it : enemies) {
    it->Tick();
  }
}

void Engine::Draw() const {
  field_.Draw({Engine::GetPlayer().GetX(), Engine::GetPlayer().GetY()},
              {(float) (Graphics::ResourceManager::GetWindow().GetSizeWindow().first / 2),
               (float) (Graphics::ResourceManager::GetWindow().GetSizeWindow().second / 2)});
  Engine::GetPlayer().Draw({(float) (Graphics::ResourceManager::GetWindow().GetSizeWindow().first / 2),
                (float) (Graphics::ResourceManager::GetWindow().GetSizeWindow().second / 2)});
  for (auto& it : enemies) {
    it->Draw({Engine::GetPlayer().GetX(), Engine::GetPlayer().GetY()},
             {(float)(Graphics::ResourceManager::GetWindow().GetSizeWindow().first / 2),
              (float)(Graphics::ResourceManager::GetWindow().GetSizeWindow().second / 2)});
  }
  GUI::GUIManager::GetGUIManager().Draw();
  Graphics::ResourceManager::GetWindow().Render();
}

Engine* Engine::GetEngine(uint32_t width, uint32_t height, const std::string_view& file) {
  if (!ptr)
    ptr = new Engine(width, height, file);
  return ptr;
}
Player& Engine::GetPlayer() {
  return *player_;
}
