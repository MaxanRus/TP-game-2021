#include "Timer.hpp"
#include <chrono>
#include <unistd.h>

uint32_t Timer::GetTime() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void Timer::Sleep(uint32_t seconds) {
  usleep(seconds * 1000);
}
