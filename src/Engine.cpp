#include "Engine.hpp"
#include <iostream>
#include <graphics/ResourceManager.hpp>

Engine* Engine::ptr = nullptr;

Engine::Engine(uint32_t width, uint32_t height, const std::string_view& path_file) :
    player_({200, 200}, &field_, "player"),
    field_(width, height, path_file) {
  enemies.push_back(new UnitGroup(100, Vector2D{30.0, 30.0}, &field_));
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
