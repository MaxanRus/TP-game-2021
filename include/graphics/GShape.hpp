namespace Graphics {
class GShape;
class Triangle;
class Quadrangle;
class Image;
}

#pragma once

#include "graphics/Window.hpp"
#include "graphics/Shader.hpp"
#include "graphics/Transform.hpp"

namespace Graphics {
class GShape {
 public:
  virtual ~GShape() {}
  virtual void Draw(Window&, Shader, const Transform& = Transform()) const = 0;
};

class Triangle : public GShape {
 public:
  ~Triangle() override = default;
  Triangle(float x1, float y1, float x2, float y2, float x3, float y3);
  void Draw(Window&, Shader, const Transform& = Transform()) const override;
 private:
  unsigned int id_vertex_arrays_;
  unsigned int id_vertex_buffer_;
};

class Quadrangle : public GShape {
 public:
  ~Quadrangle() override = default;
  Quadrangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
  void Draw(Window&, Shader, const Transform& = Transform()) const override;
 private:
  unsigned int id_vertex_arrays_;
  unsigned int id_vertex_buffer_;
  unsigned int id_element_buffer_;
};

class Image : public Quadrangle {
 public:
  ~Image() = default;
  Image(const char* path);
  [[nodiscard]] std::pair<unsigned int, unsigned int> GetSize() const { return std::make_pair(width_, height_); }
  [[nodiscard]] unsigned int GetId() const { return id_; }
  void Draw(Window&, Shader, const Transform& = Transform()) const;
 private:
  int nrChannels_;
  int width_, height_;
  unsigned int id_;
};
}
