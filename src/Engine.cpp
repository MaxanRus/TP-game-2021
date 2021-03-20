#include "Engine.hpp"
#include "GlobalClassManager.hpp"

Engine* Engine::ptr = nullptr;

Engine::Engine(unsigned width, unsigned height, const std::string& file):
    player_(width / 2, height / 2, &field_, "player") {
  field_ = Field(width, height, file);
}

void Engine::Tick() {
  player_.Tick();
  field_.Tick();
}

void Engine::Draw() const {
  field_.Draw(player_.GetX(), player_.GetY(),
              Graphics::ResourceManager::GetWindow().GetSizeWindow().first / 2, Graphics::ResourceManager::GetWindow().GetSizeWindow().second / 2);
  player_.Draw(Graphics::ResourceManager::GetWindow().GetSizeWindow().first / 2, Graphics::ResourceManager::GetWindow().GetSizeWindow().second / 2);

  Graphics::ResourceManager::GetWindow().Render();
}

Engine::~Engine() {
}

Engine* Engine::GetEngine(unsigned width, unsigned height,
                          const std::string& file) {
  if (!ptr) {
    ptr = new Engine(width, height, file);
  }
  return ptr;
}
