#include <Engine.hpp>
#include <engine/Field.hpp>

const Cell& Field::GetCell(float x, float y) const {
  int X = std::trunc(x/Cell::GetPixelWidth());
  int Y = std::trunc(y/Cell::GetPixelHeight());
  return At(X, Y);
}

std::pair<unsigned int, unsigned int> Field::GetCellPos(float x, float y) {
  return {std::trunc(x/Cell::GetPixelWidth()), std::trunc(y/Cell::GetPixelHeight())};
}

void Field::Draw(int WindowCellWidth, int WindowCellHeight,
                 float x, float y, float centerX, float centerY) const {
  int px, py;
  std::tie(px, py) = GetCellPos(x, y);
  px -= WindowCellWidth/2;
  py -= WindowCellHeight/2;
  centerX -= (WindowCellWidth/2) * Cell::GetPixelWidth();
  centerY -= (WindowCellHeight/2) * Cell::GetPixelHeight();
  for (int i = px; i < px + WindowCellWidth; ++i) {
    for (int j = py; j < py + WindowCellHeight; ++j) {
      GetCell(i, j).Draw(round(centerX + (i-px) * Cell::GetPixelWidth()),
                         round(centerY + (j-py) * Cell::GetPixelHeight()));
      break; /// TODO
    }
    break; /// TODO
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

Field::Field(unsigned width, unsigned height, std::string file):
    width_(width), height_(height),
    field_(width, std::vector<Cell>(height)) {
  for (auto& i : field_) {
    for (auto& j : i) {
      j.add(Engine::GetDirt());
    }
  }
}

void Field::Tick() {
}
