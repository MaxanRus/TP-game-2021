#pragma once

#include <utility>
#include <vector>
#include <iostream>

#include <string_view>

namespace Console {
const uint32_t kWindowCellWidth = 30;
const uint32_t kWindowCellHeight = 50;

constexpr float kCellWidth = 1;
constexpr float kCellHeight = 1;

const int kImgNull = 0;
const int kImgPlayer = 1;
const int kImgEarth = 2;
const int kImgStone = 3;

static std::vector<std::string_view> pixels;

class Image {
 public:
  void Draw(uint32_t x, uint32_t y);
  Image() = default;
  explicit Image(std::vector<std::string_view> img);

 private:
  std::vector<std::string_view> images_;

};

static std::vector<Image> images;

void BuildImages();;
void Init(uint32_t height, uint32_t m);
void DeInit();
void Redraw();
}