#include <iostream>
#include <Console.hpp>
#include <engine/Field.hpp>
#include <engine/objects/Player.hpp>
#include <engine/objects/ground/GroundEarth.hpp>
#include <Engine.hpp>
#include <memory>
#include "graphics/Window.hpp"
#include "graphics/GShape.hpp"
#include "graphics/Transform.hpp"

void Initialization(Graphics::Window*& window, Engine*& engine);

int main() {
  Graphics::Window* window;
  Engine* engine;
  Initialization(window, engine);

  Engine::GetEngine()->GetDirt()->Draw(5, 5);
  window->Render();

  while (true) ;

  //while (window->IsLive()) {
  //  engine->Tick();
  //  engine->Draw();
  //}

  delete window;
  delete engine;

  return 0;
}

void Initialization(Graphics::Window*& window, Engine*& engine) {
  window = new Graphics::Window(1280, 720, "Game");

  if (!window) {
    std::cout << "Ошибка создания окна" << std::endl;
    exit(-1);
  }

  Engine::GetEngine(window,100, 100, 20, 20);
}
