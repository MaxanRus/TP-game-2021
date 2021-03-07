#include <utility>
#include <vector>
#include <iostream>
#include <string>

#pragma once

namespace Console {
  const unsigned int WindowCellWidth = 30;
  const unsigned int WindowCellHeight = 50;

  constexpr float CellWidth = 1;
  constexpr float CellHeight = 1;

  const int imgNull = 0;
  const int imgPlayer = 1;
  const int imgEarth = 2;
  const int imgStone = 3;

  static std::vector<std::string> pixels;

  class Image{
   public:
    void Draw(unsigned int x, unsigned int y);
    Image() = default;
    explicit Image(std::vector<std::string> img);

   private:
    std::vector<std::string> img_;

  };

  static std::vector<Image> images;

  void buildImages();;
  void Init(unsigned int n, unsigned int m);
  void DeInit();
  void Redraw();
}