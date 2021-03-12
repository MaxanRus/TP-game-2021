namespace Graphics {
class Window;
}

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <utility>

#include "graphics/Shader.hpp"
#include "graphics/Transform.hpp"

namespace Graphics {
class Window {
 public:
  enum keys {LEFT_MOUSE, RIGHT_MOUSE, ESC, SPACE, ENTER, W, A, S, D, UP, LEFT, DOWN, RIGHT, SHIFT, CTRL};

  Window(int width, int height, const char* title_window);

  bool IsLive() const;
  std::pair<int, int> GetSizeWindow() const;
  std::pair<int, int> GetCursorPosition() const;
  void Use(Shader);
  void Clear();
  void Render();

  Transform GetTransformCoordinates() const {
    auto[w, h] = GetSizeWindow();
    return Transform().Move(-1, -1).Scale(2.0 / w, 2.0 / h);
  }

  bool CheckPressButton(keys);

  operator bool() const;

 private:
  GLFWwindow* window_ = nullptr;
};
}
