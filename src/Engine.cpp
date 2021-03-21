#include "Engine.hpp"
#include <iostream>

Engine* Engine::ptr = nullptr;

Engine::Engine(unsigned width, unsigned height, const std::string& path_file) :
    player_(200, 200, &field_, "player"),
    field_(width, height, path_file) {
  enemies.push_back(new UnitGroup(100, 30.0, 30.0, &field_));
}

void Engine::Tick() {
  player_.Tick();
  field_.Tick();
  for (auto& it : enemies) {
    it->Tick();
  }
}

void Engine::Draw() const {
  field_.Draw(player_.GetX(), player_.GetY(),
              Graphics::ResourceManager::GetWindow().GetSizeWindow().first / 2,
              Graphics::ResourceManager::GetWindow().GetSizeWindow().second / 2);
  player_.Draw(Graphics::ResourceManager::GetWindow().GetSizeWindow().first / 2,
               Graphics::ResourceManager::GetWindow().GetSizeWindow().second / 2);
  for (auto& it : enemies) {
    it->Draw(player_.GetX(), player_.GetY(),
             Graphics::ResourceManager::GetWindow().GetSizeWindow().first / 2,
             Graphics::ResourceManager::GetWindow().GetSizeWindow().second / 2);
  }
  Graphics::ResourceManager::GetWindow().Render();
}

Engine* Engine::GetEngine(unsigned width, unsigned height, const std::string& file) {
  if (!ptr)
    ptr = new Engine(width, height, file);
  return ptr;
}
