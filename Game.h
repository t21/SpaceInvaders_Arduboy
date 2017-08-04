#ifndef Game_h
#define Game_h

#include <Arduboy2.h>
#include "Enemies.h"
#include "Player.h"
#include "Timer.h"

class Game {
public:
  Game(Arduboy2 &arduboy, Enemies &enemies, Timer &timer);
  void update();  
  void draw(); //Draws everything

  void setPause(bool state);

  bool collisionEnem(int num);

  bool collisionAllEnem();

  bool collisionPlayer(); //Player collide with bullet
  
private:
  Arduboy2 *ardu;
  Player *player;
  Enemies *enemies;
  Timer *timer;

  int animframe;

  bool paused;
  
};



#endif //_Game_h
