#include <exception>

#include <stb_image.h>
#include <array>
#include <stdexcept>

#include "graphics/GShape.hpp"

using namespace Graphics;

void GShape::Draw(Window& window, Shader shader, int x, int y, float scale, float rotate) const {
  Transform transform;
  transform.Move(x, y).Rotate(rotate).Scale(scale);
  Draw(window, shader, transform);
}

Quadrangle::Quadrangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  std::array<float, 8> vertices = {static_cast<float>(x1), static_cast<float>(y1), static_cast<float>(x2), static_cast<float>(y2),
                      static_cast<float>(x3), static_cast<float>(y3), static_cast<float>(x4), static_cast<float>(y4)};
  uint32_t indices[] = {0, 1, 3, 1, 2, 3};

  glGenVertexArrays(1, &id_vertex_arrays_);
  glGenBuffers(1, &id_vertex_buffer_);
  glGenBuffers(1, &id_element_buffer_);

  // Начинам редактировать
  glBindVertexArray(id_vertex_arrays_);
  glBindBuffer(GL_ARRAY_BUFFER, id_vertex_buffer_);

  // Запихиваем туда данные
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, &vertices[0], GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_element_buffer_);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * 6, indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*) 0);
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

Image::Image(const std::string_view& path) : Quadrangle(0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0) {
  stbi_set_flip_vertically_on_load(true);
  glGenTextures(1, &id_);
  glBindTexture(GL_TEXTURE_2D, id_);

  int width, height, nr_channels;
  unsigned char* data = stbi_load(std::string(path).c_str(), &width, &height, &nr_channels, 0);
  if (data) {
    if (nr_channels == 4)
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    else
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    throw std::runtime_error("fail load image");
  }
  stbi_image_free(data);

  width_ = width;
  height_ = height;
  nr_channels_ = nr_channels;
}

void Image::Draw(Window& window, Shader shader, const Transform& transform) const {
  shader.Set("our_texture", *this);
  Quadrangle::Draw(window, shader, Transform(transform).Scale(width_, height_));
}

void Image::Draw(Window& window, Shader shader, int x, int y, float scale, float rotate) const {
  if (abs(rotate) > 1e-3)
    Draw(window, shader, Transform().Move(x + scale * width_ / 2.0f, y + scale * height_ / 2.0f).Scale(scale)
        .Rotate(rotate).Move(-width_ / 2.0f, -height_ / 2.0f));
  else
    Draw(window, shader, Transform().Move(x, y).Scale(scale));
}
