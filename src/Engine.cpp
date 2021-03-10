#include "Engine.hpp"

Engine* Engine::ptr;
Graphics::Window* Engine::window_;
Graphics::Shader* Engine::image_shader_;
Graphics::Shader* Engine::shader_;

Engine::Engine(Graphics::Window* window, unsigned width, unsigned height,
               unsigned windowWidth, unsigned windowHeight, const std::string& file):
    windowWidth_(windowWidth),
    windowHeight_(windowHeight),
    player_(width/2, height/2, &field_, new Graphics::Image("assets/img/dwarf.png")) {

  Engine::SetWindow(window);
  Engine::SetImageShader(new Graphics::Shader("assets/shaders/image_shader.vs", "assets/shaders/image_shader.fs"));
  Engine::SetShader(new Graphics::Shader("assets/shaders/shader.vs", "assets/shaders/shader.fs"));

  _Dirt_ = new Dirt(new Graphics::Image("assets/img/dwarf.png"));
  _Stone_ = new Stone(new Graphics::Image("assets/img/stone.png"));
  _GroundEmpty_ = new GroundEmpty(new Graphics::Image("assets/img/empty.png"));


  field_ = Field(this, width, height, file);
}

void Engine::Tick() {
  player_.Tick();
  field_.Tick();
}
GroundEmpty* Engine::GetGroundEmpty() const {
  return _GroundEmpty_;
}
Dirt* Engine::GetDirt() const {
  return _Dirt_;
}
Stone* Engine::GetStone() const {
  return _Stone_;
}

void Engine::Draw() const {
  field_.Draw(windowWidth_, windowHeight_, player_.GetX(), player_.GetY(),
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
