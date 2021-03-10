#include <Engine.hpp>
#include <engine/Field.hpp>

const Cell& Field::GetCell(float x, float y) const {
  int X = std::trunc(x/Engine::GetPixelWidth());
  int Y = std::trunc(y/Engine::GetPixelHeight());
  return At(X, Y);
}

std::pair<unsigned int, unsigned int> Field::GetCellPos(float x, float y) {
  return {std::trunc(x/Engine::GetPixelWidth()), std::trunc(y/Engine::GetPixelHeight())};
}

void Field::Draw(float x, float y, float centerX, float centerY) const {
  int WindowCellWidth = Engine::GetWindow()->GetSizeWindow().first / Engine::GetPixelWidth() + Engine::GetBiggestObjectWidth() + 5;
  int WindowCellHeight = Engine::GetWindow()->GetSizeWindow().second / Engine::GetPixelHeight() + Engine::GetBiggestObjectHeight() + 5;
  int px = GetCellPos(x, y).first;
  int py = GetCellPos(x, y).second;
  px -= WindowCellWidth/2;
  py -= WindowCellHeight/2;
  centerX -= (Engine::GetWindow()->GetSizeWindow().first / Engine::GetPixelWidth() / 2) * Engine::GetPixelWidth();
  centerY -= (Engine::GetWindow()->GetSizeWindow().second / Engine::GetPixelHeight() / 2) * Engine::GetPixelHeight();
  for (int i = px - static_cast<int>(Engine::GetBiggestObjectWidth()) - 10; i < px + WindowCellWidth + 5; ++i) {
    for (int j = py - static_cast<int>(Engine::GetBiggestObjectHeight()) - 10; j < py + WindowCellHeight + 5; ++j) {
      int X = round(centerX + (i-px) * static_cast<int>(Engine::GetPixelWidth()));
      int Y = round(centerY + (j-py) * static_cast<int>(Engine::GetPixelHeight()));
      GetCell(i, j).Draw(X, Y);
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
    return *Engine::GetCellGroundEmpty();
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
      j.add(Engine::GetStone());
    }
  }
}

void Field::Tick() {
}
