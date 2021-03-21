class Timer;

#pragma once

#include <chrono>
#include <unistd.h>

class Timer {
 public:
  static unsigned GetTime();
  static void Sleep(unsigned seconds);
};
