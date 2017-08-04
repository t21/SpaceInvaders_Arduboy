#include "Enemies.h"

Enemies::Enemies(Arduboy2 &arduboy) {
  this->ardu = &arduboy;
  currentEnemy = 0;
  enemyStep = 2;
}



int Enemies::getRandomEnemy1() {
  return randomEnemy1;  
}



int Enemies::getRandomEnemy2() {
  return randomEnemy2;
}



void Enemies::init() {
  for (int i = 0; i < ENEMIESTOTAL; i++) {
    if (i <= ENEMIESTOTAL/ENEMYROWS) {
      EnemiesOS[i].y = ENEM_STARTROW1_Y; 
      EnemiesOS[i].bitmap = ALIEN1BMP;
      EnemiesOS[i].alive = true;
    } else if (i <= (ENEMIESTOTAL/ENEMYROWS)*2) {
      EnemiesOS[i].y = ENEM_STARTROW2_Y; 
      EnemiesOS[i].bitmap = ALIEN2BMP;
      EnemiesOS[i].alive = true;        
    } else if (i <= ENEMIESTOTAL) {
      EnemiesOS[i].y = ENEM_STARTROW3_Y; 
      EnemiesOS[i].bitmap = ALIEN3BMP;
      EnemiesOS[i].alive = true;
    }

    //Set X
    if (i == 0 || i == ENEMIESTOTAL/ENEMYROWS | i == (ENEMIESTOTAL/ENEMYROWS)*2) {
      EnemiesOS[i].x = ENEM_START_X;
    } else {
      EnemiesOS[i].x = EnemiesOS[i-1].x + 16;
    }

    //Init Shot
    EnemiesOS[i].shot.speed = 0.1f;
    EnemiesOS[i].shot.onScreen = true;
    EnemiesOS[i].shot.sprite = 1;
    
    EnemiesOS[i].shot.hitbox.x = EnemiesOS[i].shot.x;
    EnemiesOS[i].shot.hitbox.y = EnemiesOS[i].shot.y;
    EnemiesOS[i].shot.hitbox.width = 1;
    EnemiesOS[i].shot.hitbox.height = 3;
  }  
}



void Enemies::moveDown() {
  for (int i = 0; i < ENEMIESTOTAL; i++) {
    EnemiesOS[i].y += 2;  
  }
}



void Enemies::update() {
//  for (int i = 0; i < ENEMIESTOTAL; i++) {
//    EnemiesOS[i].hitbox.x = EnemiesOS[i].x;
//    EnemiesOS[i].hitbox.y = EnemiesOS[i].y;
//    EnemiesOS[i].hitbox.width = 12;
//    EnemiesOS[i].hitbox.height = 8;   
//
//    EnemiesOS[i].shot.hitbox.x = EnemiesOS[i].shot.x;
//    EnemiesOS[i].shot.hitbox.y = EnemiesOS[i].shot.y;
//  }

  Serial.print("E:");
  Serial.print(currentEnemy);
  Serial.print(" ");
  Serial.println(EnemiesOS[currentEnemy].x);


  if (EnemiesOS[currentEnemy].x > 0 && EnemiesOS[currentEnemy].x < (127-12)) {
    EnemiesOS[currentEnemy].x += enemyStep;
  } else {
    enemyStep = -enemyStep;
  }
  
  currentEnemy++;
  if (currentEnemy > (ENEMIESTOTAL-1)) {
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



