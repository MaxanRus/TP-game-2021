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

void Initialization(Graphics::Window *&window);

int main() {
  Graphics::Window *window;
  Initialization(window);

//
//  Engine::GetDirt()->Draw(1, 1);
//  window->Render();
//
//  while (true) ;

  while (window->IsLive()) {
    double t = glfwGetTime();
    Engine::GetEngine()->Tick();
    Engine::GetEngine()->Draw();
    std::cout << 1 / (glfwGetTime() - t) << "\n";
  }

  delete window;

  return 0;
}

void Initialization(Graphics::Window *&window) {
  window = new Graphics::Window(1280, 720, "Game");

  if (!window) {
    std::cout << "Ошибка создания окна" << std::endl;
    exit(-1);
  }

  Engine::GetEngine(window, 100, 100);
}
