#include <glm/gtc/type_ptr.hpp>

#include "graphics/GShape.hpp"

using namespace Graphics;

Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3) {
  float vertices[] = {x1, y1, x2, y2, x3, y3};
  // Генерируем
  glGenVertexArrays(1, &id_vertex_arrays_);
  glGenBuffers(1, &id_vertex_buffers_);
  // Начинам редактировать
  glBindVertexArray(id_vertex_arrays_);
  glBindBuffer(GL_ARRAY_BUFFER, id_vertex_buffers_);

  // Запихиваем туда данные
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, vertices, GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

void Triangle::Draw(Window& window, Shader shader) {
  window.Use(shader);

  glm::mat4 transform = glm::mat4(1.0f);

//  Example transforms
//  transform = glm::scale(transform, glm::vec3(1.0, 1.0, 1.0));
//  transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
//  transform = glm::scale(transform, glm::vec3(0.5, 1.0, 1.0));

  glUniformMatrix4fv(glGetUniformLocation(shader.GetId(), "transform"),
                     1, GL_FALSE, glm::value_ptr(transform));

  glBindVertexArray(id_vertex_arrays_);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

Rectangle::Rectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
  float vertices[] = {x1, y1, x2, y2, x3, y3, x4, y4};
  // TODO
}

void Rectangle::Draw(Window&, Shader) {
  // TODO
}
