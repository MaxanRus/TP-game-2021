#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <utility>

#include "graphics/Shader.hpp"

#pragma once

namespace Graphics {
class Window {
 public:
  Window(int width, int height, const char* title_window);

  bool IsLive();
  std::pair<int, int> GetSizeWindow();
  std::pair<int, int> GetCursorPosition();
  void Use(Shader);
  void Clear();
  void Render();

  operator bool();

 private:
  GLFWwindow* window_ = nullptr;
};
}
