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
    double t = glfwGetTime();
    Graphics::Transform transform;
    auto[wi, hi] = img.GetSize();

    glm::mat4 projection = glm::ortho(0.0f, 1280.0f, 720.0f, 0.0f, -1.0f, 1.0f);
    image_shader.Use();
    glUniformMatrix4fv(glGetUniformLocation(image_shader.GetId(), "projection"),
                       1, GL_FALSE, window.GetTransformCoordinates().GetMatrix());

    transform.Move(300, 300);
    transform.Scale(10);
    transform.Rotate(glfwGetTime() * 100);
    transform.Move(-(float)wi / 2, -(float)hi / 2);

    // img.Draw(window, image_shader, transform);
    img.Draw(window, image_shader, 0.0, 0.0, 3.0, glfwGetTime() * 100);
    img.Draw(window, image_shader, 100, 100);
    Graphics::GShape& test = img;
    // test.Draw(window, image_shader, 10.0, 10.0, 3.0, 0.0);

    for (int i = 0; i < 50; ++i) {
      for (int j = 0; j < 22; ++j) {
        // img.Draw(window, image_shader, Graphics::Transform().Move(i * 32, j * 32).Rotate(glfwGetTime() * 100));
      }
    }

    window.Render();
    std::cout << 1 / (glfwGetTime() - t) << std::endl;
  }
  return 0;
}
