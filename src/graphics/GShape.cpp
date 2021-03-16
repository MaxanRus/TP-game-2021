#include <exception>

#include <stb_image.h>

#include "graphics/GShape.hpp"

using namespace Graphics;

void GShape::Draw(Window& window, Shader shader, int x, int y, float scale, float rotate) const {
  Transform transform;
  transform.Move(x, y).Rotate(rotate).Scale(scale);
  Draw(window, shader, transform);
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : x1(x2), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
  float vertices[] = {static_cast<float>(x1), static_cast<float>(y1), static_cast<float>(x2),
                      static_cast<float>(y2), static_cast<float>(x3), static_cast<float>(y3)};
  // Генерируем
  glGenVertexArrays(1, &id_vertex_arrays_);
  glGenBuffers(1, &id_vertex_buffer_);
  // Начинам редактировать
  glBindVertexArray(id_vertex_arrays_);
  glBindBuffer(GL_ARRAY_BUFFER, id_vertex_buffer_);

  // Запихиваем туда данные
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, vertices, GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

void Triangle::Draw(Window& window, Shader shader, const Transform& transform) const {
  shader.Use();

  glUniformMatrix4fv(glGetUniformLocation(shader.GetId(), "transform"),
                     1, GL_FALSE, transform.GetMatrix());

  glBindVertexArray(id_vertex_arrays_);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Triangle::Draw(Window& window, Shader shader, int x, int y, float scale, float rotate) const {
  GShape::Draw(window, shader, x, y, scale, rotate);
}

Quadrangle::Quadrangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  float vertices[] = {static_cast<float>(x1), static_cast<float>(y1), static_cast<float>(x2), static_cast<float>(y2),
                      static_cast<float>(x3), static_cast<float>(y3), static_cast<float>(x4), static_cast<float>(y4)};
  unsigned int indices[] = {0, 1, 3, 1, 2, 3};

  glGenVertexArrays(1, &id_vertex_arrays_);
  glGenBuffers(1, &id_vertex_buffer_);
  glGenBuffers(1, &id_element_buffer_);

  // Начинам редактировать
  glBindVertexArray(id_vertex_arrays_);
  glBindBuffer(GL_ARRAY_BUFFER, id_vertex_buffer_);

  // Запихиваем туда данные
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_element_buffer_);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

void Quadrangle::Draw(Window& window, Shader shader, const Transform& transform) const {
  shader.Use();

  auto trans = (transform).GetMatrix();
  glUniformMatrix4fv(glGetUniformLocation(shader.GetId(), "transform"),
                     1, GL_FALSE, trans);

  glBindVertexArray(id_vertex_arrays_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_element_buffer_);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Quadrangle::Draw(Window& window, Shader shader, int x, int y, float scale, float rotate) const {
  GShape::Draw(window, shader, x, y, scale, rotate);
}

Image::Image(const char* path) : Quadrangle(0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0) {
  stbi_set_flip_vertically_on_load(true);
  glGenTextures(1, &id_);
  glBindTexture(GL_TEXTURE_2D, id_);

  int width, height, nr_channels;
  unsigned char* data = stbi_load(path, &width, &height, &nr_channels, 0);
  if (data) {
    if (nr_channels == 4)
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    else
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    exit(-1);
    // TODO fail load
  }
  stbi_image_free(data);

  width_ = width;
  height_ = height;
  nr_channels_ = nr_channels;
}

void Image::Draw(Window& window, Shader shader, const Transform& transform) const {
  shader.Set("texture", *this);
  Quadrangle::Draw(window, shader, Transform(transform).Scale(width_, height_));
}

void Image::Draw(Window& window, Shader shader, int x, int y, float scale, float rotate) const {
  if (abs(rotate) < 1e-3)
    Draw(window, shader, Transform().Move(x + scale * width_ / 2.0f, y + scale * height_ / 2.0f).Scale(scale)
                                              .Rotate(rotate).Move(-width_ / 2.0f, -height_ / 2.0f));
  else
    Draw(window, shader, Transform().Move(x, y).Scale(scale));
}
