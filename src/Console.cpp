#include <Console.hpp>

void Console::Init(uint32_t height, uint32_t m) {
  pixels.resize(height);
  for (auto& i : pixels) {
    i = "";
    for (int q = 0; q < m; ++q) {
      //i += " ";
    }
  }
  BuildImages();
}

void Clear() {
  for (int i = 0; i < 100; ++i) {
    std::cout << '\n';
  }
  std::cout << std::endl;
}

void Console::Redraw() {
  Clear();
  for (auto& it : pixels) {
    std::cout << (it.data());
    std::cout << std::endl;
  }
}

void Console::BuildImages() {
  if (!images.empty()) return;
  images.resize(100);
  images[0] = Image({" "});
  images[1] = Image({"@", "@"});
  images[2] = Image({"."});
  images[3] = Image({","});
}

void Console::Image::Draw(uint32_t x, uint32_t y) {
  for (int i = 0; i < images_.size() && i + x < pixels.size(); ++i) {
    for (int j = 0; j < images_[i].size() && j + y < pixels[i + x].size(); ++j) {
      //pixels[i + x][j + y] = images_[i][j];
    }
  }
}

Console::Image::Image(std::vector<std::string_view> img) : images_(std::move(img)) {}
