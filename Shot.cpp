#include "Shot.h"

Shot::Shot(Arduboy2 &arduboy) {
  this->ardu = &arduboy;
  isFired = false;
}


void Shot::update() {
    if (isFired == false) {
        return;
    }
    
    pos.y--;
  
    if (pos.y < 1) {
        isFired = false;  
    }
}


void Shot::draw() {
    if (isFired == true) {
        ardu->drawFastVLine(pos.x, pos.y, 3);
    }
}


void Shot::fire(Point playerPos) {
    if (isFired == true) {
        return;
    }
    
    isFired = true;
    pos.x = playerPos.x + 6;
    pos.y = playerPos.y - 3;
    pos.width = 1;
    pos.height = 1;
}

  
Rect Shot::getHitBox() {
    return pos;
}


void Shot::clear() {
    isFired = false;
}


