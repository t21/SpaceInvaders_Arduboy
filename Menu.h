#ifndef Menu_h
#define Menu_h

#include <Arduboy2.h>
//#include "Defines.h"


class Menu {
public:
  Menu(Arduboy2 &arduboy);
  void draw();

  void setLang(byte lang);

private:
  Arduboy2 *ardu;
  byte page; // 1 = Main | 2 = Options | 3 = Highscores

  String str_gameover;
  String str_start;
  String str_options;
  String str_lang;
  String str_back;
  String str_highscores;
  String str_new_highscore;

};

#endif //_Menu_h
