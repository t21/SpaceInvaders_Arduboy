#ifndef Player_h
#define Player_h

#include <Arduboy2.h>
#include "Defines.h"

class Player {
public:
  Player(Arduboy2 &arduboy);
  void draw();
  void shoot();//Only 1 bullet until hit enemy or outside of screen

  void moveLeft();
  void moveRight();

  void collision();//enemy shots

  void setState( int newstate);

  int getScore();

  void die(); //Run animation and respawn or go to Game over

  Rect getHitbox();

  void updateShot();
private:
  Arduboy2 *ardu;
  byte x;
  const byte y = 56;

  float xtest;

  uint16_t score;
  byte timeleft;

  byte lives;

  byte state; //0 = Menu | 1 = Alive | 2 = Dead | 3 = Game Over

  Shot_t shot;

  Rect hitbox;
};

#endif //_Player_h
