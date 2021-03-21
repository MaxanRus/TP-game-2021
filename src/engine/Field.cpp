#include <Engine.hpp>
#include <engine/Field.hpp>
#include <SpritesManager.hpp>
#include <ConstantsManager.hpp>

const Cell& Field::GetCell(float x, float y) const {
  int X = std::trunc(x / ConstantsManager::kSizeCell);
  int Y = std::trunc(y / ConstantsManager::kSizeCell);
  return At(X, Y);
}

std::pair<unsigned int, unsigned int> Field::GetCellPos(float x, float y) {
  return {std::trunc(x / ConstantsManager::kSizeCell), std::trunc(y / ConstantsManager::kSizeCell)};
}

void Field::Draw(float x, float y, float center_x, float center_y) const {
  int cell_x = GetCellPos(x, y).first;
  int cell_y = GetCellPos(x, y).second;

  float pixelPosX = center_x - x + cell_x * ConstantsManager::kSizeCell;
  float pixelPosY = center_y - y + cell_y * ConstantsManager::kSizeCell;

  int WindowCellWidth =
      Graphics::ResourceManager::GetWindow().GetSizeWindow().first / ConstantsManager::kSizeCell;
  int WindowCellHeight =
      Graphics::ResourceManager::GetWindow().GetSizeWindow().second / ConstantsManager::kSizeCell;

  for (int i = cell_x - WindowCellWidth / 2 - ConstantsManager::kSizeBiggestObject - 3;
       i < cell_x + WindowCellWidth / 2 + 2; ++i) {
    for (int j = cell_y - WindowCellHeight / 2 - ConstantsManager::kSizeBiggestObject - 3;
         j < cell_y + WindowCellHeight / 2 + 2; ++j) {
      int x = pixelPosX - (cell_x - i) * static_cast<int>(ConstantsManager::kSizeCell);
      int y = pixelPosY - (cell_y - j) * static_cast<int>(ConstantsManager::kSizeCell);
      At(i, j).Draw(x, y);
    }
  }
}

Cell& Field::At(int x, int y) {
  if (x < 0 || y < 0 || x >= field_.size() || y >= field_[x].size()) {
    assert(true);
  }
  return field_[x][y];
}

const Cell& Field::At(int x, int y) const {
  if (x < 0 || y < 0 || x >= field_.size() || y >= field_[x].size()) {
    return *SpritesManager::GetEmptyCell();
  }
  return field_[x][y];
}

std::vector<Cell>& Field::operator[](unsigned int i) { return field_[i]; }

const std::vector<Cell>& Field::operator[](unsigned int i) const { return field_[i]; }

unsigned int Field::GetWidth() const { return width_; }

unsigned int Field::GetHeight() const { return height_; }

Field::Field(unsigned width, unsigned height, const std::string& path_file) :
    width_(width), height_(height),
    field_(width, std::vector<Cell>(height)) {
  int c = 0;
  for (auto& i : field_) {
    for (auto& j : i) {
      c = (c + 1) % 3;
      if (c == 0) {
        j.Add(SpritesManager::GetDirt());
      }
      if (c == 1) {
        j.Add(SpritesManager::GetStone());
      }
      if (c == 2) {
        j.Add(SpritesManager::GetWater());
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
  auto[pos_x, pos_y] = GetCellPos(x, y);
  for (size_t i = std::min(size_t(pos_x), field_.size() - 1);
       i > std::max(-1U, pos_x - ConstantsManager::kSizeBiggestObject); --i) {
    for (size_t j = std::min(size_t(pos_y), field_[i].size() - 1);
         j > std::max(-1U, pos_y - ConstantsManager::kSizeBiggestObject); --j) {
      if (field_[i][j].GetBuilding() != nullptr) {
        return field_[i][j].GetBuilding();
      }
    }
  }
  return nullptr;
}
