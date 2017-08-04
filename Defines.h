#ifndef Defines_h
#define Defines_h

//#include <Arduboy2.h>

#define FPS 60
#define ENEMIESTOTAL 18
#define ENEMYROWS 3
#define DEFAULTLANG 0

#define ENEM_STARTROW1_Y 4
#define ENEM_STARTROW2_Y 14
#define ENEM_STARTROW3_Y 24
#define ENEM_START_X 10

#define ALIEN1BMP 1
#define ALIEN2BMP 2
#define ALIEN3BMP 3

typedef struct {
  uint8_t x;
  uint8_t y;
  float y2;
  float speed;
  bool onScreen;
  byte sprite; //0 = Line | 1 = Special 
  Rect hitbox;
}Shot_t;

#endif //_Defines_h
