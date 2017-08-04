#include <Arduboy2.h>

#include "Defines.h"
#include "Enemies.h"
#include "Player.h"
#include "Bitmaps.h"
#include "Menu.h"
#include "Timer.h"
#include "Game.h"


Arduboy2 ardu;

Player player(ardu);
Enemies enemies(ardu);
Menu menu(ardu);
Timer timer(ardu);
Game game(ardu,player,enemies,timer);

byte gamestate; // 0 = Menu | 1 = Playing | 2 = High scores

void setup() {
  // put your setup code here, to run once:
  ardu.begin();
  ardu.setFrameRate(FPS);
  gamestate = 1;
  ardu.initRandomSeed();

  menu.setLang(DEFAULTLANG);
  Serial.begin(115200);

  enemies.init();
  
  ardu.clear();
}

void loop() {
  if (!ardu.nextFrame()) {
    return; 
  }
  ardu.pollButtons();
  // put your main code here, to run repeatedly:
  if (gamestate == 0) {
    menu.draw();     
  } else if (gamestate == 1) {
    game.update();
    game.draw(); 
    ardu.setCursor(1,58); 
    ardu.print(ardu.cpuLoad());
  } else if (gamestate == 2) {
    
  }
  
  ardu.display(CLEAR_BUFFER);
}
