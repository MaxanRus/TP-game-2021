// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>

#include "graphics/Window.hpp"

#pragma once

namespace Graphics {
class GShape {
 public:
  virtual ~GShape() {}
  virtual void Draw(Window&, Shader) = 0;
};

class Triangle : public GShape {
 public:
  ~Triangle() override = default;
  Triangle(float x1, float y1, float x2, float y2, float x3, float y3);
  void Draw(Window&, Shader) override;
 private:
  unsigned int id_vertex_arrays_;
  unsigned int id_vertex_buffers_;
};

class Rectangle : public GShape {
 public:
  ~Rectangle() override = default;
  Rectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
  void Draw(Window&, Shader) override;
 private:
  unsigned int id_vertex_arrays_;
  unsigned int id_vertex_buffers_;
};
}
