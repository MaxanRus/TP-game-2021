namespace Graphics {
class Window;
}

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <utility>
#include <vector>

#include "graphics/Shader.hpp"
#include "graphics/Transform.hpp"

namespace Graphics {
class Window {
 public:
  enum class keys { LEFT_MOUSE, RIGHT_MOUSE, ESC, SPACE, ENTER, W, A, S, D, UP, LEFT, DOWN, RIGHT, SHIFT, CTRL };

  Window(int width, int height, std::string_view title_window);

  bool IsAlive() const;
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

 private:
  GLFWwindow* window_ = nullptr;
};

}
