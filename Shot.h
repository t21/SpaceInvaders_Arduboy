#ifndef _Shot_h_
#define _Shot_h_

#include <Arduboy2.h>
#include "Defines.h"

class Shot {
public:
  Shot(Arduboy2 &arduboy);
  void update();
  void draw();
  void fire(Point playerPos);
  Rect getHitBox();
  void clear();

private:
  Arduboy2 *ardu;
//  byte x;
//  byte y;
  bool isFired;
  Rect pos;

//  float xtest;
//
//  uint16_t score;
//  byte timeleft;
//
//  byte lives;
//
//  byte state; //0 = Menu | 1 = Alive | 2 = Dead | 3 = Game Over
//
//  Shot_t shot;
//
//  Rect hitbox;
};

#endif // _Shot_h_
