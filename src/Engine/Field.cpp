#include <Engine.hpp>
#include <engine/Field.hpp>

const Cell& Field::GetCell(float x, float y) const {
  int X = std::trunc(x / Engine::GetPixelWidth());
  int Y = std::trunc(y / Engine::GetPixelHeight());
  return At(X, Y);
}

std::pair<unsigned int, unsigned int> Field::GetCellPos(float x, float y) {
  return {std::trunc(x / Engine::GetPixelWidth()), std::trunc(y / Engine::GetPixelHeight())};
}

void Field::Draw(float x, float y, float centerX, float centerY) const {
  int cellX = GetCellPos(x, y).first;
  int cellY = GetCellPos(x, y).second;

  float pixelPosX = centerX - x + cellX * Engine::GetPixelWidth();
  float pixelPosY = centerY - y + cellY * Engine::GetPixelHeight();

  int WindowCellWidth = Engine::GetWindow()->GetSizeWindow().first / Engine::GetPixelWidth();
  int WindowCellHeight = Engine::GetWindow()->GetSizeWindow().second / Engine::GetPixelHeight();

  for (int i = cellX - WindowCellWidth / 2 - Engine::GetBiggestObjectWidth() - 3; i < cellX + WindowCellWidth / 2 + 2; ++i) {
    for (int j = cellY - WindowCellHeight / 2 - Engine::GetBiggestObjectHeight() - 3; j < cellY + WindowCellHeight / 2 + 2; ++j) {
      int x = pixelPosX - (cellX - i) * static_cast<int>(Engine::GetPixelWidth());
      int y = pixelPosY - (cellY - j) * static_cast<int>(Engine::GetPixelHeight());
      At(i, j).Draw(x, y);
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

std::vector<Cell>& Field::operator[](unsigned int i) { return field_[i]; }

const std::vector<Cell>& Field::operator[](unsigned int i) const { return field_[i]; }

unsigned int Field::GetWidth() const { return width_; }

unsigned int Field::GetHeight() const { return height_; }

Field::Field(unsigned width, unsigned height, std::string file) :
    width_(width), height_(height),
    field_(width, std::vector<Cell>(height)) {
  int c = 0;
  for (auto& i : field_) {
    for (auto& j : i) {
      c = (c+1) % 3;
      if (c == 0) {
        j.add(Engine::GetDirt());
      }
      if (c == 1) {
        j.add(Engine::GetStone());
      }
      if (c == 2) {
        j.add(Engine::GetWater());
      }
    }
  }
}

void Field::Tick() {
}
