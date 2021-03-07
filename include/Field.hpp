#include <vector>
#include <objects/Cell.hpp>
#include <cmath>
#include <objects/ground/GroundEmpty.hpp>

#pragma once

class Field {
 public:
  [[nodiscard]] unsigned int GetWidth() const;
  [[nodiscard]] unsigned int GetHeight() const;

  Field(unsigned int width, unsigned int height);

  virtual ~Field() = default;

  [[nodiscard]] std::vector<Cell>& operator[](unsigned int i);
  [[nodiscard]] const std::vector<Cell>& operator[](unsigned int i) const;

  [[nodiscard]] const Cell& GetCell(float x, float y) const;
  [[nodiscard]] static std::pair<unsigned int, unsigned int> GetCellPos(float x, float y);

  void Draw(float x, float y, float centerX, float centerY) const;
  void Draw(std::pair<float, float> position, std::pair<float, float> center) const;

 private:
  unsigned int width_{}, height_{};
  std::vector<std::vector<Cell>> field_;

  [[nodiscard]] Cell& At(int x, int y);
  [[nodiscard]] const Cell& At(int x, int y) const;
};