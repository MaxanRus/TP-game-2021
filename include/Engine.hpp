class Engine;

#pragma once

#include <graphics/Window.hpp>
#include <engine/Drawable.hpp>
#include <engine/Field.hpp>
#include <engine/objects/Player.hpp>
#include <engine/objects/ground/GroundEmpty.hpp>
#include <engine/objects/ground/earth/Dirt.hpp>
#include <engine/objects/ground/earth/Stone.hpp>
#include <engine/objects/ground/water/Water.hpp>
#include <engine/objects/ground/mineral/Iron.hpp>
#include <engine/objects/UnitGroup.hpp>

class Engine {
 public:
  static Engine* GetEngine(unsigned width = 0, unsigned height = 0,
                           const std::string& file = "");
  ~Engine() = default;

  void Tick();
  void Draw() const;

 private:
  Player player_;
  Field field_;
  std::vector<UnitGroup*> enemies;

  static Engine* ptr;

  explicit Engine(unsigned width, unsigned height, const std::string& file = "");
};
