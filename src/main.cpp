#include <iostream>

#include "graphics/Window.hpp"
#include "graphics/GShape.hpp"
#include "graphics/Transform.hpp"
#include "graphics/ResourceManager.hpp"

int main() {
  Graphics::Window window(1280, 720, "Game");

  if (!window) {
    std::cout << "Ошибка создания окна" << std::endl;
    return -1;
  }

  Graphics::ResourceManager::LoadImage("assets/img/dwarf_debug.png", "dwarf_d");
  Graphics::ResourceManager::LoadShader("assets/shaders/image_shader.vs", "assets/shaders/image_shader.fs", "image");

  while (window.IsLive()) {
    double t = glfwGetTime();
    Graphics::Transform transform;
    auto img = Graphics::ResourceManager::GetImage("dwarf_d");
    auto sh = Graphics::ResourceManager::GetShader("image");
    sh.SetProjectorMatrix(window.GetTransformCoordinates());
    auto[wi, hi] = img.GetSize();

    transform.Move(300, 300);
    transform.Scale(10);
    transform.Rotate(glfwGetTime() * 100);
    transform.Move(-(float)wi / 2, -(float)hi / 2);

    // img.Draw(window, image_shader, transform);
    img.Draw(window, sh, 0.0, 0.0, 3.0, glfwGetTime() * 100);
    img.Draw(window, sh, 100, 100);
    Graphics::GShape& test = img;
    // test.Draw(window, image_shader, 10.0, 10.0, 3.0, 0.0);

    for (int i = 0; i < 50; ++i) {
      for (int j = 0; j < 22; ++j) {
         img.Draw(window, sh, i * 32, j * 32, 1, 100 * glfwGetTime());
      }
    }

    window.Render();
    std::cout << 1 / (glfwGetTime() - t) << std::endl;
  }
  return 0;
}
