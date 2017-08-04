#ifndef Timer_h
#define Timer_h

#include <Arduboy2.h>

class Timer {
public:
  Timer(Arduboy2 &arduboy);
  void incTimer();
  int getTimer();
  
private:
  Arduboy2 *ardu; 

  int timer;
  
};

#endif //_Timer_h
