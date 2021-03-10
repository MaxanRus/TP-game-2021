class Engine;

#pragma once

#include <graphics/Window.hpp>
#include <engine/Object.hpp>
#include <engine/Field.hpp>
#include <engine/objects/Player.hpp>
#include <engine/objects/ground/GroundEmpty.hpp>
#include <engine/objects/ground/earth/Dirt.hpp>
#include <engine/objects/ground/earth/Stone.hpp>

class Engine {
 public:
  static Engine* GetEngine(Graphics::Window* window = nullptr, unsigned width = 0, unsigned height = 0,
                           unsigned windowWidth = 0, unsigned windowHeight = 0, const std::string& file = "");
  ~Engine();

  void Tick();
  void Draw() const;

  [[nodiscard]] GroundEmpty* GetGroundEmpty() const;
  [[nodiscard]] Dirt* GetDirt() const;
  [[nodiscard]] Stone* GetStone() const;

  [[nodiscard]] static Graphics::Window* GetWindow();
  [[nodiscard]] static Graphics::Shader* GetImageShader();

  static void SetWindow(Graphics::Window* window);
  static void SetImageShader(Graphics::Shader* image_shader);
  static void SetShader(Graphics::Shader* shader);

 private:
  unsigned windowWidth_;

  unsigned windowHeight_;
  Field field_;

  Player player_;

  static Engine* ptr;
  static Graphics::Window* window_;
  static Graphics::Shader* image_shader_;
  static Graphics::Shader* shader_;

  GroundEmpty* _GroundEmpty_;
  Dirt* _Dirt_;
  Stone* _Stone_;

  explicit Engine(Graphics::Window* window, unsigned width, unsigned height,
                  unsigned windowWidth, unsigned windowHeight, const std::string& file = "");
};
