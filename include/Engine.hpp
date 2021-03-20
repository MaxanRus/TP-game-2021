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

class Engine {
 public:
  static Engine* GetEngine(Graphics::Window* window = nullptr, unsigned width = 0, unsigned height = 0,
                           const std::string& file = "");
  ~Engine();

  void Tick();
  void Draw() const;

 private:
  Player player_;
  Field field_;

  static Engine* ptr;

  explicit Engine(Graphics::Window* window, unsigned width, unsigned height,
                  const std::string& file = "");
};
