#include "SpritesManager.hpp"

Dirt* SpritesManager::dirt_ = new Dirt("dirt");
Stone* SpritesManager::stone_ = new Stone("stone");

Water* SpritesManager::water_ = new Water("water");

GroundEmpty* SpritesManager::ground_empty_ = new GroundEmpty("empty");

Cell* SpritesManager::empty_cell_ = new Cell();

Iron* SpritesManager::iron_ = new Iron("iron");
Copper* SpritesManager::copper_ = new Copper("copper");

void SpritesManager::Init() {
  empty_cell_->Add(ground_empty_);
}

Dirt* SpritesManager::GetDirt() {
  return dirt_;
}

Stone* SpritesManager::GetStone() {
  return stone_;
}

Water* SpritesManager::GetWater() {
  return water_;
}

GroundEmpty* SpritesManager::GetGroundEmpty() {
  return ground_empty_;
}

Cell* SpritesManager::GetEmptyCell() {
  return empty_cell_;
}

Iron* SpritesManager::GetIron() {
  return iron_;
}

Copper* SpritesManager::GetCopper() {
  return copper_;
}
