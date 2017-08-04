#include "Game.h"

Game::Game(Arduboy2 &arduboy, Player &player, Enemies &enemies, Timer &timer) {
  this->ardu = &arduboy;
  this->player = &player;
  this->enemies = &enemies;
  this->timer = &timer;
}

void Game::setPause(bool state) {
  paused = state;  
}

bool Game::collisionPlayer() {
  if (ardu->collide(player->getHitbox(),enemies->getShotHitbox(enemies->getRandomEnemy1())) || ardu->collide(player->getHitbox(),enemies->getShotHitbox(enemies->getRandomEnemy2())) ) {
    //player->die();
    Serial.println("HIT");
    return true;      
  } else {
    return false;
  }
}


void Game::update() {
  //if (paused) {
  //  return;  
  //}

  //Timer
  timer->incTimer();
  
  //Keys
  if (ardu->pressed(LEFT_BUTTON)) {
    player->moveLeft();
  } else if (ardu->pressed(RIGHT_BUTTON)) {
    player->moveRight();  
  } else if (ardu->pressed(B_BUTTON)) {
    player->shoot();  
  } else if (ardu->pressed(A_BUTTON)) {
    player->shoot();  
  } else if (ardu->justPressed(UP_BUTTON)) {
    //setPause(!paused); 
    paused = !paused;   
  } else if (ardu->justPressed(DOWN_BUTTON)) {
    //setPause(!paused);
    paused = !paused;
  }
  
  //Player
  player->updateShot();

  //AI
  enemies->update();
  enemies->shoot();

  //Collision
  collisionPlayer();
  
}

void Game::draw() {
  if (timer->getTimer() % 2 && ardu->everyXFrames(90)) {
    animframe = 0;  
  } else if (timer->getTimer() % 2 && ardu->everyXFrames(60)) {
    animframe = 1;
  }
  
  enemies->draw(animframe);
  player->draw();  
}



