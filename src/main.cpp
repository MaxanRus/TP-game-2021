#include <iostream>
#include <Engine.hpp>
#include <SpritesManager.hpp>
#include "graphics/ResourceManager.hpp"
#include "Timer.hpp"

void Initialization();

int main() {
  Initialization();

  while (Graphics::ResourceManager::GetWindow().IsAlive()) {
    double t = glfwGetTime();

    /// events

    Graphics::ResourceManager::GetEventHandler().TriggerAllEvents();
    Engine::GetEngine()->Tick();
    Engine::GetEngine()->Draw();

    std::cout << 1 / (glfwGetTime() - t) << "\n";
  }

  return 0;
}

void Initialization() {
  Graphics::ResourceParser::LoadResources("assets/configs/resources.cfg");

  std::cout << "pictures are loaded" << std::endl;

  SpritesManager::Init();

  Engine::GetEngine(100, 100);
}