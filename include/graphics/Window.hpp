namespace Graphics {
class Window;
}

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>

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

  glm::mat4 GetTransformCoordinates() const {
    glm::mat4 transform = glm::mat4(1.0f);
    auto[w, h] = GetSizeWindow();
    transform = glm::translate(transform, glm::vec3(-1.0f, -1.0f, 0.0f));
    transform = glm::scale(transform, glm::vec3(2.0 / w, 2.0 / h, 1.0));
    return transform;
  }

  operator bool() const;

 private:
  GLFWwindow* window_ = nullptr;
};
}
