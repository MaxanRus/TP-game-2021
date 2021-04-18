#include "graphics/ResourceManager.hpp"

#include <map>
#include <string>
#include <memory>
#include <fstream>

namespace Graphics {
Shader& ResourceManager::LoadShader(const std::string& v_path, const std::string& f_path, const std::string& name) {
  return shaders_[name] = Shader(v_path, f_path);
}

Shader& ResourceManager::GetShader(const std::string_view& name) {
  return shaders_[static_cast<std::string>(name)];
}

Image& ResourceManager::LoadImage(const std::string& path, const std::string& name) {
  return images_[name] = Image(path);
}

Image& ResourceManager::GetImage(const std::string_view& name) {
  return images_[static_cast<std::string>(name)];
}

Window& ResourceManager::CreateWindow(size_t width, size_t height, std::string title) {
  window_ = std::make_unique<Window>(width, height, title);
  return *window_;
}

Window& ResourceManager::GetWindow() { return *window_; }

EventHandler& ResourceManager::GetEventHandler() {
  return event_handler_;
}

namespace ResourceParser {
void LoadResources(std::string path_to_config) {
  std::ifstream config(path_to_config);
  std::string buffer;

  std::vector<std::string> states = {"images:", "shaders:", "window:"};

  std::string prefix_assets = "assets/";
  std::string prefix_image = "img/";
  std::string prefix_shader = "shaders/";

  int current_state = -1;

  while (std::getline(config, buffer)) {
    bool is_change_state = false;
    for (int i = 0; i < states.size(); ++i) {
      if (states[i] == buffer) {
        current_state = i;
        is_change_state = true;
      }
    }

    if (is_change_state)
      continue;

    if (current_state == 0) {
      int separator = buffer.find(" ");
      std::string path_to_item = buffer.substr(0, separator);
      std::string name_item = buffer.substr(separator + 1, buffer.size() - separator - 1);

      ResourceManager::LoadImage(prefix_assets + prefix_image + path_to_item, name_item);
    } else if (current_state == 1) {
      int separator = buffer.find(" ");
      std::string path_to_item = buffer.substr(0, separator);
      std::string name_item = buffer.substr(separator + 1, buffer.size() - separator - 1);

      ResourceManager::LoadShader(prefix_assets + prefix_shader + path_to_item + ".vs", prefix_assets + prefix_shader + path_to_item + ".fs", name_item);
      Graphics::ResourceManager::GetShader(name_item).SetProjectorMatrix(Graphics::ResourceManager::GetWindow().GetTransformCoordinates());
    } else if (current_state == 2) {
      int first_separator = buffer.find(" ");
      int second_separator = buffer.find(" ", first_separator + 1);
      std::string width = buffer.substr(0, first_separator);
      std::string height = buffer.substr(first_separator + 1, second_separator - first_separator - 1);
      std::string name = buffer.substr(second_separator + 1, buffer.size() - second_separator - 1);

      Graphics::ResourceManager::CreateWindow(std::stoi(width), std::stoi(height), name);
    }
  }
}
}
}
