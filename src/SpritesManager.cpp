#include "SpritesManager.hpp"

GroundEarth* SpritesManager::dirt_ = new GroundEarth("dirt");
GroundEarth* SpritesManager::stone_ = new GroundEarth("stone");

GroundWater* SpritesManager::water_ = new GroundWater("water");

GroundEmpty* SpritesManager::ground_empty_ = new GroundEmpty("empty");

Cell* SpritesManager::empty_cell_ = new Cell();

Mineral* SpritesManager::iron_ = new Mineral("iron");
Mineral* SpritesManager::copper_ = new Mineral("copper");

void SpritesManager::Init() {
  empty_cell_->Add(ground_empty_);
}

GroundEarth* SpritesManager::GetDirt() {
  return dirt_;
}

GroundEarth* SpritesManager::GetStone() {
  return stone_;
}

GroundWater* SpritesManager::GetWater() {
  return water_;
}

GroundEmpty* SpritesManager::GetGroundEmpty() {
  return ground_empty_;
}

Cell* SpritesManager::GetEmptyCell() {
  return empty_cell_;
}

Mineral* SpritesManager::GetIron() {
  return iron_;
}

Mineral* SpritesManager::GetCopper() {
  return copper_;
}
