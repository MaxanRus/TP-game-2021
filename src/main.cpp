#include <iostream>

#include "graphics/Window.hpp"

int main() {
  Graphics::Window window(100, 100, "Game");

  if (!window) {
    std::cout << "Ошибка создания окна" << std::endl;
    return -1;
  }

  while (window.IsLive()) {
    window.Render();
  }

  return 0;
}
