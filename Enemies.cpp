#include "Enemies.h"

Enemies::Enemies(Arduboy2 &arduboy) {
  this->ardu = &arduboy;
  currentEnemy = 0;
}



int Enemies::getRandomEnemy1() {
  return randomEnemy1;  
}



int Enemies::getRandomEnemy2() {
  return randomEnemy2;
}



void Enemies::init() {
  for (int i = 0; i < ENEMIESTOTAL; i++) {
    // Set Y
    if (i <= ENEMIESTOTAL/ENEMYROWS) {
//      EnemiesOS[i].y = ENEM_STARTROW1_Y; 
      EnemiesOS[i].bitmap = ALIEN1BMP;
      EnemiesOS[i].alive = true;
    } else if (i <= (ENEMIESTOTAL/ENEMYROWS)*2) {
//      EnemiesOS[i].y = ENEM_STARTROW2_Y; 
      EnemiesOS[i].bitmap = ALIEN2BMP;
      EnemiesOS[i].alive = true;        
    } else if (i <= ENEMIESTOTAL) {
//      EnemiesOS[i].y = ENEM_STARTROW3_Y; 
      EnemiesOS[i].bitmap = ALIEN3BMP;
      EnemiesOS[i].alive = true;
    }

    //Set X
//    if (i == 0 || i == ENEMIESTOTAL/ENEMYROWS | i == (ENEMIESTOTAL/ENEMYROWS)*2) {
//      EnemiesOS[i].x = ENEM_START_X;
//    } else {
//      EnemiesOS[i].x = EnemiesOS[i-1].x + 16;
//    }

    byte enemiesPerRow = ENEMIESTOTAL / ENEMYROWS;
    
    EnemiesOS[i].x = ENEMY_WIDTH * (i % (ENEMIESTOTAL / ENEMYROWS)) + 16;
    EnemiesOS[i].y = i / enemiesPerRow * ENEMY_HEIGHT + ENEM_STARTROW1_Y;

    //Init Shot
    EnemiesOS[i].shot.speed = 0.1f;
    EnemiesOS[i].shot.onScreen = true;
    EnemiesOS[i].shot.sprite = 1;
    
    EnemiesOS[i].shot.hitbox.x = EnemiesOS[i].shot.x;
    EnemiesOS[i].shot.hitbox.y = EnemiesOS[i].shot.y;
    EnemiesOS[i].shot.hitbox.width = 1;
    EnemiesOS[i].shot.hitbox.height = 3;
  }  

  enemyDir = 0;
}



void Enemies::moveDown() {
  for (int i = 0; i < ENEMIESTOTAL; i++) {
    EnemiesOS[i].y += 2;  
  }
}



void Enemies::update() {
    if (currentEnemy == 0) {
        switch (enemyDir) {
            case 0:
                if (EnemiesOS[0].x > 40) {
                    enemyDir = 1;
                }
                break;
            case 1:
                enemyDir = 2;
                break;
                
            case 2:
                if (EnemiesOS[0].x < 10) {
                    enemyDir = 3;
                }
                break;

            case 3:
                enemyDir = 0;
                break;
        }
    }

    switch (enemyDir) {
        case 0:
            EnemiesOS[currentEnemy].x += 2;
            break;

        case 1:
            EnemiesOS[currentEnemy].y += 2;
            break;
            
        case 2:
            EnemiesOS[currentEnemy].x -= 2;
            break;            

        case 3:
            EnemiesOS[currentEnemy].y += 2;
            break;
            
    }

    currentEnemy++;
    if (currentEnemy >= ENEMIESTOTAL) {
        currentEnemy = 0;
    }
}



void Enemies::draw(int frame) {
  for (int i = 0; i < ENEMIESTOTAL; i++) {
    //Row 1
    if (i <= ENEMIESTOTAL/ENEMYROWS && EnemiesOS[i].alive == true) {
      if (frame == 0) {
        ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien11,12,8);  
      } else {
        ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien12,12,8);  
      }
    }
    //Row 2
    else if (i <= (ENEMIESTOTAL/ENEMYROWS)*2 && EnemiesOS[i].alive == true) {
      if (frame == 0) {
        ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien21,12,8);  
      } else {
        ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien22,12,8);  
      }        
    }
    //Row 3
    else if (i <= ENEMIESTOTAL && EnemiesOS[i].alive == true) {
      if (frame == 0) {
        ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien31,8,8);  
      } else {
        ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien32,8,8);  
      }
    }

    //Outside of screen
    if (EnemiesOS[randomEnemy1].shot.y > 128) {
      EnemiesOS[randomEnemy1].shot.onScreen = false;  
    }
    
    if (EnemiesOS[randomEnemy2].shot.y > 128) {
      EnemiesOS[randomEnemy2].shot.onScreen = false;  
    }
    //Shots
    if (EnemiesOS[i].shot.onScreen == true) {
      EnemiesOS[randomEnemy1].shot.y2 += EnemiesOS[randomEnemy1].shot.speed;
      EnemiesOS[randomEnemy2].shot.y2 += EnemiesOS[randomEnemy2].shot.speed;

      EnemiesOS[randomEnemy1].shot.y = EnemiesOS[randomEnemy1].shot.y2;
      EnemiesOS[randomEnemy2].shot.y = EnemiesOS[randomEnemy2].shot.y2;
      
      ardu->drawFastVLine(EnemiesOS[i].shot.x,EnemiesOS[i].shot.y,3);  
    }

    
  }  
}



void Enemies::shoot() {
  if (ardu->everyXFrames(90)) {
    //Serial.print("Shoot");
    //Which enemy
    int rand1 = random(0,ENEMIESTOTAL);
    int rand2 = random(0,ENEMIESTOTAL);  

    //Serial.println(rand1);
    //Serial.println(rand2);
    
    //Shoot
    if (EnemiesOS[rand1].alive == false || EnemiesOS[rand2].alive == false) {
      return;  
    }

    EnemiesOS[rand1].shot.x = EnemiesOS[rand1].x;
    EnemiesOS[rand1].shot.y = EnemiesOS[rand1].y;
    EnemiesOS[rand1].shot.onScreen = true;
    //EnemiesOS[rand1].shot.y += EnemiesOS[rand1].shot.speed;
    randomEnemy1 = rand1;
    

    EnemiesOS[rand2].shot.x = EnemiesOS[rand2].x;
    EnemiesOS[rand2].shot.y = EnemiesOS[rand2].y;
    EnemiesOS[rand2].shot.onScreen = true;
    //EnemiesOS[rand2].shot.y += EnemiesOS[rand2].shot.speed;
    randomEnemy2 = rand2;

    //Outside of screen
    if (EnemiesOS[rand1].shot.y > 132) {
      EnemiesOS[rand1].shot.onScreen = false;  
    }
    
    if (EnemiesOS[rand2].shot.y > 132) {
      EnemiesOS[rand2].shot.onScreen = false;  
    }
  }
}



Rect Enemies::getHitbox(int enemy) {
  return EnemiesOS[enemy].hitbox;  
}

Rect Enemies::getShotHitbox(int enemy) {
  return EnemiesOS[enemy].shot.hitbox;
}



