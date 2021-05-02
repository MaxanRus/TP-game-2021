#pragma once

#include <engine/objects/Cell.hpp>
#include <Helpers/Vector2D.hpp>

class Engine;

class Field {
 public:
  [[nodiscard]] uint32_t GetWidth() const;
  [[nodiscard]] uint32_t GetHeight() const;

  Field() = default;
  Field(uint32_t width, uint32_t height, const std::string_view& path_file);

  [[nodiscard]] std::vector<Cell>& operator[](uint32_t i);
  [[nodiscard]] const std::vector<Cell>& operator[](uint32_t i) const;

  [[nodiscard]] const Cell& GetCell(const Vector2Df& a) const;
  [[nodiscard]] static std::pair<uint32_t, uint32_t> GetCellPos(const Vector2Df& a);

  [[nodiscard]] Building* GetBuilding(const Vector2Df& a);
  [[nodiscard]] Building* SetBuilding(const Vector2Df& a, Building* x);

  void Draw(const Vector2Df& a, const Vector2Df& center) const;

  void Tick();

 private:
  uint32_t width_ = 0, height_ = 0;
  std::vector<std::vector<Cell>> field_;

  [[nodiscard]] Cell& At(int x, int y);
  [[nodiscard]] const Cell& At(int x, int y) const;
};