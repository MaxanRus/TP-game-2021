#include "Engine.hpp"
#include "GlobalClassManager.hpp"

Engine* Engine::ptr = nullptr;

Engine::Engine(Graphics::Window* window, unsigned width, unsigned height,
               const std::string& file): player_(width / 2, height / 2, &field_, "assets/img/dwarf.png") {
  field_ = Field(width, height, file);
}

void Engine::Tick() {
  player_.Tick();
  field_.Tick();
}

void Engine::Draw() const {
  field_.Draw(player_.GetX(), player_.GetY(),
              ResourceManager::GetWindow()->GetSizeWindow().first / 2, ResourceManager::GetWindow()->GetSizeWindow().second / 2);
  player_.Draw(ResourceManager::GetWindow()->GetSizeWindow().first / 2, ResourceManager::GetWindow()->GetSizeWindow().second / 2);

  ResourceManager::GetWindow()->Render();
}

Engine::~Engine() {
}

Engine* Engine::GetEngine(Graphics::Window* window, unsigned width, unsigned height,
                          const std::string& file) {
  if (!ptr) {
    ptr = new Engine(window, width, height, file);
  }
  return ptr;
}
