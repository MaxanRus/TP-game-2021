#pragma once

#include <engine/objects/ground/GroundEmpty.hpp>
#include <engine/objects/Cell.hpp>
#include <engine/objects/ground/GroundEarth.hpp>
#include <engine/objects/ground/GroundWater.hpp>
#include <engine/objects/ground/Mineral.hpp>

class SpritesManager {
 public:
  static void Init();

  static GroundEarth* GetDirt();
  static GroundEarth* GetStone();
  static GroundWater* GetWater();
  static GroundEmpty* GetGroundEmpty();
  static Cell* GetEmptyCell();
  static Mineral* GetIron();
  static Mineral* GetCopper();

 private:
  static GroundEarth* dirt_;
  static GroundEarth* stone_;

  static GroundWater* water_;

  static GroundEmpty* ground_empty_;

  static Cell* empty_cell_;

  static Mineral* iron_;
  static Mineral* copper_;
};
