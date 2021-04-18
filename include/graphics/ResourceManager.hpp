#pragma once

#include <map>
#include <string>
#include <memory>

#include "graphics/Shader.hpp"
#include "graphics/GShape.hpp"
#include "EventHandler/EventHandler.hpp"


namespace Graphics {
class ResourceManager {
 public:
  static Shader& LoadShader(const std::string& v_path, const std::string& f_path, const std::string& name);
  static Shader& GetShader(const std::string_view& name);
  static Image& LoadImage(const std::string& path, const std::string& name);
  static Image& GetImage(const std::string_view& name);
  static Window& CreateWindow(size_t width, size_t height, std::string title);
  static Window& GetWindow();
  static EventHandler& GetEventHandler();

 private:

  static inline std::map<std::string, Shader> shaders_;
  static inline std::map<std::string, Image> images_;
  static inline std::unique_ptr<Window> window_ = nullptr;
  static inline EventHandler event_handler_;
};

namespace ResourceParser {
void LoadResources(std::string path_to_config);
}
}
