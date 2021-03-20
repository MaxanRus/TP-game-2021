namespace Graphics {
class ResourceManager;
}

#pragma once

#include <map>
#include <string>

#include "graphics/Shader.hpp"
#include "graphics/GShape.hpp"

namespace Graphics {
class ResourceManager {
 public:
  ResourceManager* GetResourceManager() { if (!me) me = new ResourceManager; return me; }
  static Shader& LoadShader(const std::string& v_path, const std::string& f_path, const std::string& name) {
    return shaders_[name] = Shader(v_path, f_path);
  }
  static Shader& GetShader(std::string name) {
    return shaders_[name];
  }
  static Image& LoadImage(const std::string& path, const std::string& name) {
    return images_[name] = Image(path.c_str());
  }
  static Image& GetImage(const std::string& name) {
    return images_[name];
  }
  static Window& CreateWindow(size_t width, size_t height, std::string title) {
    if (!window_) {
      delete[] window_;
    }
    window_ = new Window(width, height, title.c_str());
    return *window_;
  }
  static Window& GetWindow() { return *window_; }

 private:
  ResourceManager() = default;
  ResourceManager* me = nullptr;

  static inline std::map<std::string, Shader> shaders_;
  static inline std::map<std::string, Image> images_;
  static inline Window* window_ = nullptr;
};
}
