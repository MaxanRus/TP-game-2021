#pragma once

#include <utility>
#include <vector>
#include <iostream>

#include <string>

namespace Console {
const unsigned int kWindowCellWidth = 30;
const unsigned int kWindowCellHeight = 50;

constexpr float kCellWidth = 1;
constexpr float kCellHeight = 1;

const int kImgNull = 0;
const int kImgPlayer = 1;
const int kImgEarth = 2;
const int kImgStone = 3;

static std::vector<std::string> pixels;

class Image {
 public:
  void Draw(unsigned int x, unsigned int y);
  Image() = default;
  explicit Image(std::vector<std::string> img);

 private:
  std::vector<std::string> images_;

};

static std::vector<Image> images;

void BuildImages();;
void Init(unsigned int height, unsigned int m);
void DeInit();
void Redraw();
}