#include <graphics/Window.hpp>
#include <functional>

using namespace Graphics;

Window::Window(int width, int height, const char* title_window) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window_ = glfwCreateWindow(width, height, title_window, NULL, NULL);

  if (!window_)
    return;

  glfwMakeContextCurrent(window_);
  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glfwMakeContextCurrent(window_);
  glfwSetFramebufferSizeCallback(window_, [](GLFWwindow* window, int width, int height) -> void {
    glfwMakeContextCurrent(window);
    glViewport(0, 0, width, height);
  });

  Clear();
}

bool Window::IsLive() const {
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
  return std::make_pair(int(mouse_x + 0.5), int(mouse_y) + 0.5);
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

Window::operator bool() const {
  return window_;
}
