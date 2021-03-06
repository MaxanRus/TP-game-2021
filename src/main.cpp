#include <iostream>

#include "graphics/Window.hpp"
#include "graphics/GShape.hpp"

int main() {
  Graphics::Window window(100, 100, "Game");

  if (!window) {
    std::cout << "Ошибка создания окна" << std::endl;
    return -1;
  }

  Graphics::GShape&& shape = Graphics::Triangle(0.0, 0.0, 1.0, 0.0, 1.0, 1.0);
  Graphics::Shader shader("shaders/shader.vs", "shaders/shader.fs");

  while (window.IsLive()) {
    shape.Draw(window, shader);
    window.Render();
  }

  return 0;
}
