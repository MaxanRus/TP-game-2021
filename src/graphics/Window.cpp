#include <graphics/Window.hpp>
#include <functional>

using namespace Graphics;

Window::Window(int width, int height, std::string_view title_window) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window_ = glfwCreateWindow(width, height, std::string(title_window).c_str(), NULL, NULL);

  if (!window_)
    return;

  glfwMakeContextCurrent(window_);
  gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glfwMakeContextCurrent(window_);
  glfwSetFramebufferSizeCallback(window_, [](GLFWwindow* window, int width, int height) -> void {
    glfwMakeContextCurrent(window);
    glViewport(0, 0, width, height);
  });

  Clear();
}

bool Window::IsAlive() const {
  return !glfwWindowShouldClose(window_);
}

std::pair<int, int> Window::GetSizeWindow() const {
  int window_width, window_height;
  glfwGetWindowSize(window_, &window_width, &window_height);
  return std::make_pair(window_width, window_height);
}

std::pair<int, int> Window::GetCursorPosition() const {
  double mouse_x, mouse_y;
  glfwGetCursorPos(window_, &mouse_x, &mouse_y);
  return std::make_pair(int(mouse_x + 0.5), GetSizeWindow().second - int(mouse_y) + 0.5);
}

void Window::Use(Shader shader) {
  glUseProgram(shader.GetId());
}

void Window::Clear() {
  glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

void Window::Render() {
  glfwSwapBuffers(window_);
  glfwPollEvents();
  Clear();
}

bool Window::CheckPressButton(keys key) {
  switch (key) {
    case keys::LEFT_MOUSE: return glfwGetMouseButton(window_, GLFW_MOUSE_BUTTON_1);
    case keys::RIGHT_MOUSE: return glfwGetMouseButton(window_, GLFW_MOUSE_BUTTON_2);
    case keys::ESC: return glfwGetKey(window_, GLFW_KEY_ESCAPE) == GLFW_PRESS;
    case keys::SPACE: return glfwGetKey(window_, GLFW_KEY_SPACE) == GLFW_PRESS;
    case keys::ENTER: return glfwGetKey(window_, GLFW_KEY_ENTER) == GLFW_PRESS;
    case keys::W: return glfwGetKey(window_, GLFW_KEY_W) == GLFW_PRESS;
    case keys::A: return glfwGetKey(window_, GLFW_KEY_A) == GLFW_PRESS;
    case keys::S: return glfwGetKey(window_, GLFW_KEY_S) == GLFW_PRESS;
    case keys::D: return glfwGetKey(window_, GLFW_KEY_D) == GLFW_PRESS;
    case keys::UP: return glfwGetKey(window_, GLFW_KEY_UP) == GLFW_PRESS;
    case keys::LEFT: return glfwGetKey(window_, GLFW_KEY_LEFT) == GLFW_PRESS;
    case keys::DOWN: return glfwGetKey(window_, GLFW_KEY_DOWN) == GLFW_PRESS;
    case keys::RIGHT: return glfwGetKey(window_, GLFW_KEY_RIGHT) == GLFW_PRESS;
    case keys::SHIFT:
      return glfwGetKey(window_, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS
          || glfwGetKey(window_, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS;
    case keys::CTRL:
      return glfwGetKey(window_, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS
          || glfwGetKey(window_, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS;
    default: return false;
  }
}
