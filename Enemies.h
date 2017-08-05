#ifndef Enemies_h
#define Enemies_h

#include <Arduboy2.h>
#include "Defines.h"
#include "Bitmaps.h"
#include "Player.h"

typedef struct {
  uint8_t x;
  uint8_t y;
  bool alive;
  uint8_t bitmap; //Bitmap in number
  Shot_t shot;
  Rect hitbox;
} Enemy_t;

class Enemies {
public:
  Enemies(Arduboy2 &arduboy);
  void init();
  void update();
  void shoot();
  void draw(int frame);

  Rect getHitbox(int enemy);
  Rect getShotHitbox(int enemy);

  int getRandomEnemy1();
  int getRandomEnemy2();

//  void moveDown(); //y += spritesize

  bool collide(Rect shot);

  
  
private:
  Arduboy2 *ardu;
  
  Enemy_t EnemiesOS[ENEMIESTOTAL]; //OS = Onscreen
  
  byte aliveEnemies; // If 0, spawn new

  int randomEnemy1; //Number in array
  int randomEnemy2;
  int currentEnemy;
  byte enemyDir;
};

#endif //_Enemies_h
