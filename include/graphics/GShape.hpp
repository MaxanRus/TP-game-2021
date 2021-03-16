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
  virtual void Draw(Window&, Shader, int x, int y, float scale = 1, float rotate = 0) const = 0;
 protected:
  unsigned int id_vertex_arrays_;
  unsigned int id_vertex_buffer_;
};

class Triangle : public GShape {
 public:
  ~Triangle() override = default;
  Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
  void Draw(Window&, Shader, const Transform& = Transform()) const override;
  virtual void Draw(Window&, Shader, int x, int y, float scale = 1, float rotate = 0) const;
 protected:
  int x1, y1, x2, y2, x3, y3;
};

class Quadrangle : public GShape {
 public:
  ~Quadrangle() override = default;
  Quadrangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
  void Draw(Window&, Shader, const Transform& = Transform()) const override;
  virtual void Draw(Window&, Shader, int x, int y, float scale = 1, float rotate = 0) const;
 protected:
  int x1, y1, x2, y2, x3, y3, x4, y4;
 private:
  unsigned int id_element_buffer_;
};

class Image : public Quadrangle {
 public:
  ~Image() = default;
  Image(const char* path);
  [[nodiscard]] std::pair<unsigned int, unsigned int> GetSize() const { return std::make_pair(width_, height_); }
  [[nodiscard]] unsigned int GetId() const { return id_; }
  void Draw(Window&, Shader, const Transform& = Transform()) const override;
  void Draw(Window& window, Shader shader, int x, int y, float scale = 1, float rotate = 0) const;
 private:
  int nr_channels_;
  int width_, height_;
  unsigned int id_;
};
}
