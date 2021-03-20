#include <Engine.hpp>
#include <engine/Field.hpp>
#include <GlobalClassManager.hpp>
#include <GlobalVariablesManager.hpp>

const Cell& Field::GetCell(float x, float y) const {
  int X = std::trunc(x / GlobalVariablesManager::size_cell);
  int Y = std::trunc(y / GlobalVariablesManager::size_cell);
  return At(X, Y);
}

std::pair<unsigned int, unsigned int> Field::GetCellPos(float x, float y) {
  return {std::trunc(x / GlobalVariablesManager::size_cell), std::trunc(y / GlobalVariablesManager::size_cell)};
}

void Field::Draw(float x, float y, float centerX, float centerY) const {
  int cellX = GetCellPos(x, y).first;
  int cellY = GetCellPos(x, y).second;

  float pixelPosX = centerX - x + cellX * GlobalVariablesManager::size_cell;
  float pixelPosY = centerY - y + cellY * GlobalVariablesManager::size_cell;

  int WindowCellWidth = ResourceManager::GetWindow()->GetSizeWindow().first / GlobalVariablesManager::size_cell;
  int WindowCellHeight = ResourceManager::GetWindow()->GetSizeWindow().second / GlobalVariablesManager::size_cell;

  for (int i = cellX - WindowCellWidth / 2 - GlobalVariablesManager::size_biggest_object - 3; i < cellX + WindowCellWidth / 2 + 2; ++i) {
    for (int j = cellY - WindowCellHeight / 2 - GlobalVariablesManager::size_biggest_object - 3; j < cellY + WindowCellHeight / 2 + 2; ++j) {
      int x = pixelPosX - (cellX - i) * static_cast<int>(GlobalVariablesManager::size_cell);
      int y = pixelPosY - (cellY - j) * static_cast<int>(GlobalVariablesManager::size_cell);
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
    return *GlobalClassManager::GetEmptyCell();
  }
  return field_[X][Y];
}

std::vector<Cell>& Field::operator[](unsigned int i) { return field_[i]; }

const std::vector<Cell>& Field::operator[](unsigned int i) const { return field_[i]; }

unsigned int Field::GetWidth() const { return width_; }

unsigned int Field::GetHeight() const { return height_; }

Field::Field(unsigned width, unsigned height, const std::string& file) :
    width_(width), height_(height),
    field_(width, std::vector<Cell>(height)) {
  int c = 0;
  for (auto& i : field_) {
    for (auto& j : i) {
      c = (c+1) % 3;
      if (c == 0) {
        j.Add(GlobalClassManager::GetDirt());
      }
      if (c == 1) {
        j.Add(GlobalClassManager::GetStone());
      }
      if (c == 2) {
        j.Add(GlobalClassManager::GetWater());
      }
    }
  }
}

void Field::Tick() {
  for (auto& i : field_) {
    for (auto& j : i) {
      if (!j.GetBuilding() && j.GetBuilding()->GetLife() <= 0) {
        delete j.GetBuilding();
        j.SetBuilding(nullptr);
      }
    }
  }
}

Building* Field::GetBuilding(float x, float y) const {
  auto [posX, posY] = GetCellPos(x, y);
  for (size_t i = posX; i > posX - GlobalVariablesManager::size_biggest_object; --i) {
    for (size_t j = posY; j > posY - GlobalVariablesManager::size_biggest_object; --j) {
      if (!field_[i][j].GetBuilding()) {
        return field_[i][j].GetBuilding();
      }
    }
  }
  return nullptr;
}
