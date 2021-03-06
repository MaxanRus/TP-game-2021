#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>

#include "graphics/Shader.hpp"

Shader::Shader(const std::string& vertex_path, const std::string& fragment_path) {
  auto[vertex_code_shader, fragment_code_shader] = LoadFromFile(vertex_path, fragment_path);
  Compile(vertex_code_shader, fragment_code_shader);
}

unsigned int Shader::GetId() {
  return this->id_;
}

void Shader::Use() {
  glUseProgram(this->id_);
}

std::pair<std::string, std::string> Shader::LoadFromFile(const std::string& vertex_path,
                                                         const std::string& fragment_path) {
  std::string buffer;

  std::ifstream vertex_shader_file(vertex_path);
  std::string vertex_code_shader;

  while (getline(vertex_shader_file, buffer)) {
    vertex_code_shader += buffer;
    vertex_code_shader += "\n";
  }
  vertex_shader_file.close();

  std::ifstream fragment_shader_file(fragment_path);

  std::string fragment_code_shader;
  while (getline(fragment_shader_file, buffer)) {
    fragment_code_shader += buffer;
    fragment_code_shader += "\n";
  }
  fragment_shader_file.close();

  return make_pair(vertex_code_shader, fragment_code_shader);
}

void Shader::Compile(const std::string& vertex_code_shader, const std::string& fragment_code_shader) {
  unsigned int vertex, fragment;

  // Вершинный шейдер
  vertex = glCreateShader(GL_VERTEX_SHADER);
  const char* c_vertex_code_shader = vertex_code_shader.c_str();
  glShaderSource(vertex, 1, &c_vertex_code_shader, NULL);
  glCompileShader(vertex);
  // TODO check compile shader

  // Фрагментный шейдер
  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  const char* c_fragment_code_shader = fragment_code_shader.c_str();
  glShaderSource(fragment, 1, &c_fragment_code_shader, NULL);
  glCompileShader(fragment);
  // TODO check compile shader

  // Шейдерная программа
  id_ = glCreateProgram();
  glAttachShader(id_, vertex);
  glAttachShader(id_, fragment);
  glLinkProgram(id_);
  // TODO check compile shader

  // После того, как мы связали шейдеры с нашей программой, удаляем их, так как они нам больше не нужны
  glDeleteShader(vertex);
  glDeleteShader(fragment);
}
