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
#include "Helpers/Vector2D.hpp"

namespace Graphics {
class GShape {
 public:
  virtual ~GShape() {}
  virtual void Draw(Window&, Shader, const Transform& = Transform()) const = 0;
  virtual void Draw(Window&, Shader, int x, int y, float scale = 1, float rotate = 0) const = 0;
  virtual void Draw(Window& window, Shader shader, const Vector2Di& position, float scale = 1, float rotate = 0) const = 0;
 protected:
  uint32_t id_vertex_arrays_;
  uint32_t id_vertex_buffer_;
};

class Quadrangle : public GShape {
 public:
  ~Quadrangle() override = default;
  Quadrangle() = default;
  Quadrangle(const Quadrangle&) = default;
  Quadrangle& operator=(const Quadrangle&) = default;
  Quadrangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
  void Draw(Window&, Shader, const Transform& = Transform()) const override;
  void Draw(Window&, Shader, int x, int y, float scale = 1, float rotate = 0) const override;
  void Draw(Window& window, Shader shader, const Vector2Di& position, float scale = 1, float rotate = 0) const override;
 protected:
  int x1, y1, x2, y2, x3, y3, x4, y4;
 private:
  uint32_t id_element_buffer_;
};

class Image : public Quadrangle {
 public:
  ~Image() = default;
  Image() = default;
  Image(const Image&) = default;
  Image& operator=(const Image&) = default;
  Image(const std::string_view&);
  [[nodiscard]] std::pair<uint32_t, unsigned int> GetSize() const { return std::make_pair(width_, height_); }
  [[nodiscard]] uint32_t GetId() const { return id_; }
  void Draw(Window&, Shader, const Transform& = Transform()) const override;
  void Draw(Window& window, Shader shader, int x, int y, float scale = 1, float rotate = 0) const;
  void Draw(Window& window, Shader shader, const Vector2Di& position, float scale = 1, float rotate = 0) const;
 private:
  int nr_channels_;
  int width_, height_;
  uint32_t id_;
};
}
