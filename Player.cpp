#include "Player.h"
#include "Bitmaps.h"

Player::Player(Arduboy2 &arduboy) {
  this->ardu = &arduboy;

  lives = 3;
  x = 64;

  score = 0;
  timeleft = 120;

  hitbox.x = x;
  hitbox.y = y;
  hitbox.width = 13;
  hitbox.height = 8;

  shot.hitbox.x = x;
  shot.hitbox.y = y;
  shot.hitbox.width = 1;
  shot.hitbox.height = 3;

//  shot.speed = 0.1f;
//  shot.sprite = 0;

  shot.x = 0;
  shot.y = 0;
  shot.onScreen = false;
}

void Player::updateShot() {
    if (shot.onScreen == false) {
        return;
    }
    
    shot.hitbox.x = x;
    shot.hitbox.y = y; 

//  shot.y2 -= shot.speed;

//  shot.y = shot.y2;

    shot.y--;
  
  if (shot.y < 1) {
    shot.onScreen = false;  
  }

}

Rect Player::getHitbox() {
  return hitbox;
}

void Player::moveLeft() {
  if (x <= 1) {
    return;
  }

  x--;
}

void Player::moveRight() {
  if (x >= (127 - PLAYER_WIDTH)) {
    return;
  }

  x++;
}

void Player::setState(int newstate) {
  state = newstate;  
}

int Player::getScore() {
  return score;
}

void Player::draw() {
    ardu->drawBitmap(x,y,PlayerBMP,13,8);  

    //Shot
    if (shot.onScreen == true) {
        ardu->drawFastVLine(shot.x,shot.y,3);
    }
  
//  shot.y2 -= shot.speed;
//
//  shot.y = shot.y2;


//  shot.hitbox.x = x;
//  shot.hitbox.y = y;  
  
}


void Player::shoot() {
    if (shot.onScreen == true) {
        return;
    }
    
    shot.onScreen = true;
    shot.x = x + 6;
    shot.y = y - 3;  
}


Rect Player::getShotPos() {
    Rect shotPos;
    shotPos.x = shot.x;
    shotPos.y = shot.y;
    shotPos.width = 1;
    shotPos.height = 1;
    return shotPos;    
}

Shot_t Player::getShot() {
    return shot;
}

byte Player::getX() {
    return x;
}

byte Player::getY() {
    return y;
}

Point Player::getPos() {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

