#include "GlobalClassManager.hpp"

Dirt* GlobalClassManager::dirt_ = new Dirt("dirt");
Stone* GlobalClassManager::stone_ = new Stone("stone");

Water* GlobalClassManager::water_ = new Water("water");

GroundEmpty* GlobalClassManager::ground_empty_ = new GroundEmpty("empty");

Cell* GlobalClassManager::empty_cell_ = new Cell();

Iron* GlobalClassManager::iron_ = new Iron("iron");
Copper* GlobalClassManager::copper_ = new Copper("copper");

void GlobalClassManager::Init() {
  empty_cell_->Add(ground_empty_);
}

Dirt* GlobalClassManager::GetDirt() {
  return dirt_;
}

Stone* GlobalClassManager::GetStone() {
  return stone_;
}

Water* GlobalClassManager::GetWater() {
  return water_;
}

GroundEmpty* GlobalClassManager::GetGroundEmpty() {
  return ground_empty_;
}

Cell* GlobalClassManager::GetEmptyCell() {
  return empty_cell_;
}

Iron* GlobalClassManager::GetIron() {
  return iron_;
}

Copper* GlobalClassManager::GetCopper() {
  return copper_;
}
