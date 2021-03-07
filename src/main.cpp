#include <iostream>

#include "graphics/Window.hpp"
#include "graphics/GShape.hpp"

int main() {
  Graphics::Window window(1280, 720, "Game");

  if (!window) {
    std::cout << "Ошибка создания окна" << std::endl;
    return -1;
  }

  Graphics::GShape&& shape = Graphics::Triangle(10.0, 10.0, 1280.0, 10.0, 1280.0, 720.0);
  Graphics::Shader shader("assets/shaders/shader.vs", "assets/shaders/shader.fs");

  Graphics::Image img("assets/img/dwarf.png");
  Graphics::Quadrangle quadrangle(0.0, 0.0, 50.0, 0.0, 75.0, 100.0, 0.0, 50.0);
  Graphics::Shader image_shader("assets/shaders/image_shader.vs", "assets/shaders/image_shader.fs");

  while (window.IsLive()) {
    glm::mat4 transform(1.0f);
    transform = glm::translate(transform, glm::vec3(0 * std::abs(sin(glfwGetTime())) * 720.0, 0.0, 0.0));
    transform = glm::scale(transform, glm::vec3(10.0, 10.0, 1.0));

    img.Draw(window, image_shader, transform);
    quadrangle.Draw(window, shader);

    window.Render();
  }

  return 0;
}
