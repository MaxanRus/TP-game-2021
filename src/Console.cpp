#include <Console.hpp>

void Console::Init(unsigned int n, unsigned int m) {
  pixels.resize(n);
  for (auto& i : pixels) {
    i = "";
    for (int q = 0; q < m; ++q) {
      i += " ";
    }
  }
  buildImages();
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

void Console::buildImages() {
  if (!images.empty()) return;
  images.resize(100);
  images[0] = Image({" "});
  images[1] = Image({"@", "@"});
  images[2] = Image({"."});
  images[3] = Image({","});
}

void Console::Image::Draw(unsigned int x, unsigned int y) {
  for (int i = 0; i < img_.size() && i + x < pixels.size(); ++i) {
    for (int j = 0; j < img_[i].size() && j + y < pixels[i + x].size(); ++j) {
      pixels[i + x][j + y] = img_[i][j];
    }
  }
}

Console::Image::Image(std::vector<std::string> img) : img_(std::move(img)) {}
