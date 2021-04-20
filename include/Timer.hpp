#pragma once

#include <cstdint>

class Timer {
 public:
  static uint32_t GetTime();
  static void Sleep(uint32_t seconds);
};
