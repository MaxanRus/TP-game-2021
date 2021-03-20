#include "GlobalClassManager.hpp"

Dirt* GlobalClassManager::dirt_ = new Dirt("assets/img/dirt.png");
Stone* GlobalClassManager::stone_ = new Stone("assets/img/stone.png");

Water* GlobalClassManager::water_ = new Water("assets/img/water.png");

GroundEmpty* GlobalClassManager::ground_empty_ = new GroundEmpty("assets/img/empty.png");

Cell* GlobalClassManager::empty_cell_ = new Cell(ground_empty_);

Iron* GlobalClassManager::iron_ = new Iron("assets/img/iron.png");

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
