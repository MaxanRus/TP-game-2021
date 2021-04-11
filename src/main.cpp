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

    Engine::GetEngine()->Tick();
    Engine::GetEngine()->Draw();

    std::cout << 1 / (glfwGetTime() - t) << "\n";
  }

  return 0;
}

void Initialization() {
  Graphics::ResourceManager::CreateWindow(1280, 720, "Game");

  Graphics::ResourceManager::LoadImage("assets/img/dirt.png", "dirt");
  Graphics::ResourceManager::LoadImage("assets/img/stone.png", "stone");
  Graphics::ResourceManager::LoadImage("assets/img/water.png", "water");
  Graphics::ResourceManager::LoadImage("assets/img/empty.png", "empty");
  Graphics::ResourceManager::LoadImage("assets/img/iron.png", "iron");
  //Graphics::ResourceManager::LoadImage("assets/img/copper.png", "copper");
  Graphics::ResourceManager::LoadImage("assets/img/unit.png", "unit");
  Graphics::ResourceManager::LoadImage("assets/img/dwarf_debug.png", "player");
  Graphics::ResourceManager::LoadShader("assets/shaders/image_shader.vs", "assets/shaders/image_shader.fs", "image");

  Graphics::ResourceManager::GetShader("image").SetProjectorMatrix(Graphics::ResourceManager::GetWindow().GetTransformCoordinates());

  std::cout << "pictures are loaded" << std::endl;

  SpritesManager::Init();

  Engine::GetEngine(100, 100);
}