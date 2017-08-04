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

  shot.speed = 0.1f;
  shot.sprite = 0;
}

void Player::updateShot() {
  shot.hitbox.x = x;
  shot.hitbox.y = y; 

  shot.y2 -= shot.speed;

  shot.y = shot.y2;
}

Rect Player::getHitbox() {
  return hitbox;
}

void Player::moveLeft() {
  if (x <= 1) {
    return;
  }

  x--;
  //xtest -= 0.1f;
  //x = xtest;
}

void Player::moveRight() {
  if (x >= 127) {
    return;
  }

  x++;
  //xtest += 0.1f;
 // x = xtest;
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
  if (shot.y < 0) {
    shot.onScreen = false;  
  }

//  shot.y2 -= shot.speed;
//
//  shot.y = shot.y2;

  ardu->drawFastVLine(shot.x,shot.y,3);

//  shot.hitbox.x = x;
//  shot.hitbox.y = y;  
  
}


void Player::shoot() {
  shot.onScreen = true;
  shot.x = x;
  shot.y = y;  
}

