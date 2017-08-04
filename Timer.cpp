#include "Timer.h"

Timer::Timer(Arduboy2 &arduboy) {
  this->ardu = &arduboy;  
}

void Timer::incTimer() {
  timer++;
}

int Timer::getTimer() {
  return timer;
}

