#include "Field.hpp"

const Cell& Field::GetCell(float x, float y) const {
  int X = std::trunc(x/Cell::GetPixelWidth());
  int Y = std::trunc(y/Cell::GetPixelHeight());
  return At(X, Y);
}

std::pair<unsigned int, unsigned int> Field::GetCellPos(float x, float y) {
  return {std::trunc(x/Cell::GetPixelWidth()), std::trunc(y/Cell::GetPixelHeight())};
}

void Field::Draw(float x, float y, float centerX, float centerY) const {
  int px, py;
  std::tie(px, py) = GetCellPos(x, y);
  px -= Console::WindowCellWidth/2;
  py -= Console::WindowCellHeight/2;
  centerX -= (Console::WindowCellWidth/2) * Console::CellWidth;
  centerY -= (Console::WindowCellHeight/2) * Console::CellHeight;
  for (int i = px; i < px + Console::WindowCellWidth; ++i) {
    for (int j = py; j < py + Console::WindowCellHeight; ++i) {
      GetCell(i, j).Draw(round(centerX + (i-px) * Console::CellWidth),
                         round(centerY + (j-py) * Console::CellHeight));
    }
  }
}

Cell& Field::At(int X, int Y) {
  if (X < 0 || Y < 0 || X >= field_.size() || Y >= field_[X].size()) {
    assert(true);
  }
  return field_[X][Y];
}
const Cell& Field::At(int X, int Y) const {
  if (X < 0 || Y < 0 || X >= field_.size() || Y >= field_[X].size()) {
    assert(true);
  }
  return field_[X][Y];
}

std::vector<Cell> &Field::operator[](unsigned int i) { return field_[i]; }
const std::vector<Cell> &Field::operator[](unsigned int i) const { return field_[i]; }
unsigned int Field::GetWidth() const { return width_; }
unsigned int Field::GetHeight() const { return height_; }

Field::Field(unsigned width, unsigned height):
    width_(width), height_(height),
    field_(width, std::vector<Cell>(height)) {
}

void Field::Draw(std::pair<float, float> position, std::pair<float, float> center) const {
  Draw(position.first, position.second, center.first, center.second);
}
