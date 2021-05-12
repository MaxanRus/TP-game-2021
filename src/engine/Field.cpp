#include <engine/Field.hpp>
#include <SpritesManager.hpp>
#include <ConstantsManager.hpp>
#include <cmath>
#include <graphics/ResourceManager.hpp>

const Cell& Field::GetCell(const Vector2Df& a) const {
  int X = std::trunc(a.x / ConstantsManager::kSizeCell);
  int Y = std::trunc(a.y / ConstantsManager::kSizeCell);
  return At(X, Y);
}

std::pair<uint32_t, uint32_t> Field::GetCellPos(const Vector2Df& a) {
  return {std::trunc(a.x / ConstantsManager::kSizeCell), std::trunc(a.y / ConstantsManager::kSizeCell)};
}

void Field::Draw(const Vector2Df& a, const Vector2Df& center) const {
  int cell_x = GetCellPos(a).first;
  int cell_y = GetCellPos(a).second;

  Vector2Df pixelPos = Vector2Df(center.x - a.x + cell_x * ConstantsManager::kSizeCell,
                               center.y - a.y + cell_y * ConstantsManager::kSizeCell);

  int WindowCellWidth =
      Graphics::ResourceManager::GetWindow().GetSizeWindow().first / ConstantsManager::kSizeCell;
  int WindowCellHeight =
      Graphics::ResourceManager::GetWindow().GetSizeWindow().second / ConstantsManager::kSizeCell;

  for (int i = cell_x - WindowCellWidth / 2 - ConstantsManager::kSizeBiggestObject - 3;
       i < cell_x + WindowCellWidth / 2 + 2; ++i) {
    for (int j = cell_y - WindowCellHeight / 2 - ConstantsManager::kSizeBiggestObject - 3;
         j < cell_y + WindowCellHeight / 2 + 2; ++j) {
      Vector2Df a = {pixelPos.x - (cell_x - i) * static_cast<int>(ConstantsManager::kSizeCell),
                    pixelPos.y - (cell_y - j) * static_cast<int>(ConstantsManager::kSizeCell)};
      At(i, j).Draw(a);
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

std::vector<Cell>& Field::operator[](uint32_t i) { return field_[i]; }

const std::vector<Cell>& Field::operator[](uint32_t i) const { return field_[i]; }

uint32_t Field::GetWidth() const { return width_; }

uint32_t Field::GetHeight() const { return height_; }

Field::Field(uint32_t width, uint32_t height, const std::string_view& path_file) :
    width_(width), height_(height),
    field_(width, std::vector<Cell>(height)) {
  int c = 0;
  for (auto& i : field_) {
    for (auto& j : i) {
      c = rand() % 5;
      if (c == 0 || c == 1) {
        j.Add(SpritesManager::GetDirt());
      }
      if (c == 2 || c == 3) {
        j.Add(SpritesManager::GetStone());
      }
      if (c == 4) {
        j.Add(SpritesManager::GetWater());
      }
    }
  }
}

void Field::Tick() {
  for (auto& i : field_) {
    for (auto& j : i) {
      if (j.GetBuilding()) {
        j.GetBuilding()->Tick();
      }
      /*
      if (j.GetBuilding() && j.GetBuilding()->GetLife() <= 0) {
        delete j.GetBuilding();
        j.SetBuilding(nullptr);
      }
       */
    }
  }
}

Building* Field::GetBuilding(const Vector2Df& a) {
  auto[i, j] = GetCellPos(a);
  if (i < 0 || j < 0 || i >= field_.size() || j >= field_[0].size()) {
    return nullptr;
  }
  if (field_[i][j].GetBuilding() != nullptr) {
    return field_[i][j].GetBuilding();
  }
  return nullptr;
}
Building* Field::SetBuilding(const Vector2Df& a, Building* x) {
  auto[pos_x, pos_y] = GetCellPos(a);
  for (size_t i = std::min(size_t(pos_x), field_.size() - 1);
       i > std::max(-1U, pos_x - ConstantsManager::kSizeBiggestObject); --i) {
    for (size_t j = std::min(size_t(pos_y), field_[i].size() - 1);
         j > std::max(-1U, pos_y - ConstantsManager::kSizeBiggestObject); --j) {
      if (i < 0 || j < 0 || i >= field_.size() || j >= field_[0].size()) {
        continue;
      }
      if (field_[i][j].GetBuilding() != nullptr) {
        field_[i][j].GetBuilding() = x;
      }
    }
  }
}
