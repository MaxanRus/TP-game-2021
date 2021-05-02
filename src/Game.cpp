#include "Game.h"
#include <iostream>
#include <Engine.hpp>
#include <SpritesManager.hpp>
#include "graphics/ResourceManager.hpp"
#include "GUI/GUIManager.hpp"
#include "GUI/Inventory.hpp"

void Game::Start() {
  Graphics::ResourceParser::LoadResources("assets/configs/resources.cfg");
  std::cout << "pictures are loaded" << std::endl;
  SpritesManager::Init();
  Engine::GetEngine(100, 100);

  GUI::GUIManager::GetGUIManager().AddWindow(std::make_unique<GUI::Inventory>());
  try {
    while (Graphics::ResourceManager::GetWindow().IsAlive()) {
      double t = glfwGetTime();

      /// events

      Graphics::ResourceManager::GetEventHandler().TriggerAllEvents();
      Engine::GetEngine()->Tick();
      Engine::GetEngine()->Draw();

      std::cout << 1 / (glfwGetTime() - t) << "\n";
    }
  } catch (char const* s) {
    while (true) ;
  } catch (...) {
    throw;
  }
}
