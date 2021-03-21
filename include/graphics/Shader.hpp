namespace Graphics {
class Shader;
}

#pragma once

#include <string>
#include "graphics/GShape.hpp"
#include "graphics/Transform.hpp"

namespace Graphics {
class Shader {
 public:
  Shader() = default;
  Shader(const Shader&) = default;
  Shader& operator=(const Shader&) = default;
  Shader(const std::string& vertex_path, const std::string& fragment_path);
  unsigned int GetId() const { return id_; }
  void Use() const;
  void Set(const char* name, const Image&);
  void SetProjectorMatrix(const Transform&) const;
 private:
  static std::pair<std::string, std::string> LoadFromFile(const std::string& vertex_path,
                                                          const std::string& fragment_path);
  void Compile(const std::string& vertex_code_shader, const std::string& fragment_code_shader);
  static void CheckCompileErrors();

  unsigned int id_;
};
}

