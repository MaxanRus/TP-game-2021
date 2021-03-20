class Field;

#pragma once

#include <vector>
#include <engine/objects/Cell.hpp>
#include <cmath>

class Engine;

class Field {
 public:
  [[nodiscard]] unsigned int GetWidth() const;
  [[nodiscard]] unsigned int GetHeight() const;

  Field() = default;
  Field(unsigned int width, unsigned int height, const std::string& file);

  [[nodiscard]] std::vector<Cell>& operator[](unsigned int i);
  [[nodiscard]] const std::vector<Cell>& operator[](unsigned int i) const;

  [[nodiscard]] const Cell& GetCell(float x, float y) const;
  [[nodiscard]] static std::pair<unsigned int, unsigned int> GetCellPos(float x, float y);

  void Draw(float x, float y, float centerX, float centerY) const;

  void Tick();

 private:
  unsigned int width_=0, height_=0;
  std::vector<std::vector<Cell>> field_;

  [[nodiscard]] Cell& At(int x, int y);
  [[nodiscard]] const Cell& At(int x, int y) const;
};