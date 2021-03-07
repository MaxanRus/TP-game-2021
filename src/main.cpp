#include <iostream>

#include "graphics/Window.hpp"
#include "graphics/GShape.hpp"

int main() {
  Graphics::Window window(1280, 720, "Game");

  if (!window) {
    std::cout << "Ошибка создания окна" << std::endl;
    return -1;
  }

  Graphics::GShape&& shape = Graphics::Triangle(0.0, 0.0, -1.0, 0.0, -1.0, 1.0);
  Graphics::Shader shader("shaders/shader.vs", "shaders/shader.fs");

  Graphics::Image img("img/dwarf.png");
  Graphics::Quadrangle quadrangle(-1.0, -1.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0);
  Graphics::Shader image_shader("shaders/image_shader.vs", "shaders/image_shader.fs");

  while (window.IsLive()) {
    shape.Draw(window, shader);
    quadrangle.Draw(window, shader);
    img.Draw(window, image_shader);
    window.Render();
  }

  return 0;
}
