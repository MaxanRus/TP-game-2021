#include "Timer.hpp"

unsigned Timer::GetTime() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void Timer::Sleep(unsigned int x) {
  usleep(x * 1000);
}
