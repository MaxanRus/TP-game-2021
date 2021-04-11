#pragma once

#include <engine/objects/Player.hpp>
#include <engine/objects/UnitGroup.hpp>

class Engine {
 public:
  static Engine* GetEngine(uint32_t width = 0, uint32_t height = 0,
                           const std::string_view& file = "");
  ~Engine() = default;

  void Tick();
  void Draw() const;

 private:
  Player player_;
  Field field_;
  std::vector<UnitGroup*> enemies;

  static Engine* ptr;

  explicit Engine(uint32_t width, uint32_t height, const std::string_view& path_file = "");
};
