#pragma once

#include <map>
#include <string>
#include <memory>

#include "graphics/Shader.hpp"
#include "graphics/GShape.hpp"


namespace Graphics {
class ResourceManager {
 public:
  ResourceManager* GetResourceManager() {
    if (!me) me = new ResourceManager;
    return me;
  }
  static Shader& LoadShader(const std::string& v_path, const std::string& f_path, const std::string& name) {
    return shaders_[name] = Shader(v_path, f_path);
  }
  static Shader& GetShader(std::string name) {
    return shaders_[name];
  }
  static Image& LoadImage(const std::string& path, const std::string& name) {
    return images_[name] = Image(path.c_str());
  }
  static Image& GetImage(const std::string_view& name) {
    return images_[name];
  }
  static Window& CreateWindow(size_t width, size_t height, std::string_view title) {
    window_ = std::make_unique<Window>(width, height, title);
    return *window_;
  }
  static Window& GetWindow() { return *window_; }

 private:
  ResourceManager() = default;
  ResourceManager* me = nullptr;

  static inline std::map<std::string_view, Shader> shaders_;
  static inline std::map<std::string_view, Image> images_;
  static inline std::unique_ptr<Window> window_ = nullptr;
};
}
