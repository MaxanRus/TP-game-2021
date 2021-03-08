#include <iostream>

#include "graphics/Window.hpp"
#include "graphics/GShape.hpp"
#include "graphics/Transform.hpp"

int main() {
  Graphics::Window window(1280, 720, "Game");

  if (!window) {
    std::cout << "Ошибка создания окна" << std::endl;
    return -1;
  }

  Graphics::GShape&& shape = Graphics::Triangle(10.0, 10.0, 1280.0, 10.0, 1280.0, 720.0);
  Graphics::Shader shader("assets/shaders/shader.vs", "assets/shaders/shader.fs");

  Graphics::Image img("assets/img/dwarf_debug.png");
  Graphics::Quadrangle quadrangle(0.0, 0.0, 50.0, 0.0, 75.0, 100.0, 0.0, 50.0);
  Graphics::Shader image_shader("assets/shaders/image_shader.vs", "assets/shaders/image_shader.fs");

  while (window.IsLive()) {
    Graphics::Transform transform;
    auto[wi, hi] = img.GetSize();
    transform.Move(300, 300);
    transform.Scale(10);
    transform.Rotate(glfwGetTime() * 100);
    transform.Move(-(float)wi / 2, -(float)hi / 2);

    img.Draw(window, image_shader, transform);

    window.Render();
  }

  return 0;
}
