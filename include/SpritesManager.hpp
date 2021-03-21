#include <engine/objects/ground/earth/Dirt.hpp>
#include <engine/objects/ground/earth/Stone.hpp>
#include <engine/objects/ground/GroundEmpty.hpp>
#include <engine/objects/ground/water/Water.hpp>
#include <engine/objects/ground/mineral/Iron.hpp>
#include <engine/objects/ground/mineral/Copper.hpp>

class SpritesManager;

#pragma once

class SpritesManager {
 public:
  static void Init();

  static Dirt* GetDirt();
  static Stone* GetStone();
  static Water* GetWater();
  static GroundEmpty* GetGroundEmpty();
  static Cell* GetEmptyCell();
  static Iron* GetIron();
  static Copper* GetCopper();

 private:
  static Dirt* dirt_;
  static Stone* stone_;

  static Water* water_;

  static GroundEmpty* ground_empty_;

  static Cell* empty_cell_;

  static Iron* iron_;
  static Copper* copper_;
};
