namespace Graphics {
class Window;
}

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <utility>

#include "graphics/Shader.hpp"

namespace Graphics {
class Window {
 public:
  Window(int width, int height, const char* title_window);

  bool IsLive() const;
  std::pair<int, int> GetSizeWindow() const;
  std::pair<int, int> GetCursorPosition() const;
  void Use(Shader);
  void Clear();
  void Render();

  operator bool() const;

 private:
  GLFWwindow* window_ = nullptr;
};
}
