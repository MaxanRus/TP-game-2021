#include "Engine.hpp"

unsigned Engine::pixelWidth_ = 32;
unsigned Engine::pixelHeight_ = 32;
unsigned Engine::biggestObjectWidth_ = 1;
unsigned Engine::biggestObjectHeight_ = 1;

Engine* Engine::ptr = nullptr;
Graphics::Window* Engine::window_;
Graphics::Shader* Engine::image_shader_;
Graphics::Shader* Engine::shader_;

Dirt* Engine::_Dirt_;
Stone* Engine::_Stone_;
GroundEmpty* Engine::_GroundEmpty_;
Cell* Engine::_CellGroundEmpty_;

Engine::Engine(Graphics::Window* window, unsigned width, unsigned height,
               unsigned windowWidth, unsigned windowHeight, const std::string& file):
    windowWidth_(windowWidth),
    windowHeight_(windowHeight),
    player_(width/2, height/2, &field_, new Graphics::Image("assets/img/dwarf.png")) {

  Engine::SetWindow(window);
  Engine::SetImageShader(new Graphics::Shader("assets/shaders/image_shader.vs", "assets/shaders/image_shader.fs"));
  Engine::SetShader(new Graphics::Shader("assets/shaders/shader.vs", "assets/shaders/shader.fs"));

  _Dirt_ = new Dirt(new Graphics::Image("assets/img/dirt.png"));
  _Stone_ = new Stone(new Graphics::Image("assets/img/stone.png"));
  _GroundEmpty_ = new GroundEmpty(new Graphics::Image("assets/img/empty.png"));
  _CellGroundEmpty_ = new Cell();
  _CellGroundEmpty_->add(_GroundEmpty_);

  field_ = Field(width, height, file);

}

void Engine::Tick() {
  player_.Tick();
  field_.Tick();
}
GroundEmpty* Engine::GetGroundEmpty() {
  return _GroundEmpty_;
}
Dirt* Engine::GetDirt() {
  return _Dirt_;
}
Stone* Engine::GetStone() {
  return _Stone_;
}

void Engine::Draw() const {
  field_.Draw(player_.GetX(), player_.GetY(),
              window_->GetSizeWindow().first/2, window_->GetSizeWindow().second/2);
  player_.Draw(window_->GetSizeWindow().first/2, window_->GetSizeWindow().second/2);

  window_->Render();
}
Engine::~Engine() {
  delete _GroundEmpty_;
  delete _Dirt_;
  delete _Stone_;

  delete image_shader_;
  delete shader_;
}
Graphics::Window *Engine::GetWindow() {
  return window_;
}
Engine *Engine::GetEngine(Graphics::Window* window, unsigned width, unsigned height,
                          unsigned windowWidth, unsigned windowHeight, const std::string& file) {
  if (!ptr) {
    ptr = new Engine(window, width, height, windowWidth, windowHeight, file);
  }
  return ptr;
}
Graphics::Shader *Engine::GetImageShader() {
  return image_shader_;
}
void Engine::SetWindow(Graphics::Window* window) {
  window_ = window;
}
void Engine::SetImageShader(Graphics::Shader *image_shader) {
  image_shader_ = image_shader;
}
void Engine::SetShader(Graphics::Shader *shader) {
  shader_ = shader;
}
unsigned Engine::GetPixelWidth() {
  return Engine::pixelWidth_;
}
unsigned Engine::GetPixelHeight() {
  return Engine::pixelHeight_;
}
unsigned Engine::GetBiggestObjectWidth() {
  return biggestObjectWidth_;
}
unsigned Engine::GetBiggestObjectHeight() {
  return biggestObjectHeight_;
}
Cell *Engine::GetCellGroundEmpty() {
  return _CellGroundEmpty_;
}
