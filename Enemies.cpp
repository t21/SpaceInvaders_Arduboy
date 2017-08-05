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
    byte enemiesPerRow = ENEMIESTOTAL / ENEMYROWS;
    for (int i = 0; i < ENEMIESTOTAL; i++) {
        if (i < enemiesPerRow) {
            EnemiesOS[i].x = ENEMY_WIDTH * (i % (ENEMIESTOTAL / ENEMYROWS)) + 16;
            EnemiesOS[i].y = ENEM_STARTROW1_Y;
            EnemiesOS[i].hitbox.x = EnemiesOS[i].x;
            EnemiesOS[i].hitbox.y = EnemiesOS[i].y;
            EnemiesOS[i].hitbox.width = 11;
            EnemiesOS[i].hitbox.height = 8;
        } else if (i < 2*enemiesPerRow) {
            EnemiesOS[i].x = ENEMY_WIDTH * (i % (ENEMIESTOTAL / ENEMYROWS)) + 17;
            EnemiesOS[i].y = ENEM_STARTROW2_Y; 
            EnemiesOS[i].hitbox.x = EnemiesOS[i].x;
            EnemiesOS[i].hitbox.y = EnemiesOS[i].y;
            EnemiesOS[i].hitbox.width = 11;
            EnemiesOS[i].hitbox.height = 8;
        } else if (i < ENEMIESTOTAL) {
            EnemiesOS[i].x = ENEMY_WIDTH * (i % (ENEMIESTOTAL / ENEMYROWS)) + 18;
            EnemiesOS[i].y = ENEM_STARTROW3_Y; 
            EnemiesOS[i].hitbox.x = EnemiesOS[i].x;
            EnemiesOS[i].hitbox.y = EnemiesOS[i].y;
            EnemiesOS[i].hitbox.width = 11;
            EnemiesOS[i].hitbox.height = 8;
        }

        EnemiesOS[i].alive = true;
      
    //Init Shot
//    EnemiesOS[i].shot.speed = 0.1f;
//    EnemiesOS[i].shot.onScreen = true;
//    EnemiesOS[i].shot.sprite = 1;
    
//    EnemiesOS[i].shot.hitbox.x = EnemiesOS[i].shot.x;
//    EnemiesOS[i].shot.hitbox.y = EnemiesOS[i].shot.y;
//    EnemiesOS[i].shot.hitbox.width = 1;
//    EnemiesOS[i].shot.hitbox.height = 3;
  }  

  enemyDir = 0;
}



//void Enemies::moveDown() {
//  for (int i = 0; i < ENEMIESTOTAL; i++) {
//    EnemiesOS[i].y += 2;  
//  }
//}



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
            EnemiesOS[currentEnemy].hitbox.x += 2;
            break;

        case 1:
            EnemiesOS[currentEnemy].y += 2;
            EnemiesOS[currentEnemy].hitbox.y += 2;
            break;
            
        case 2:
            EnemiesOS[currentEnemy].x -= 2;
            EnemiesOS[currentEnemy].hitbox.x -= 2;
            break;            

        case 3:
            EnemiesOS[currentEnemy].y += 2;
            EnemiesOS[currentEnemy].hitbox.y += 2;
            break;
            
    }

    currentEnemy++;
    if (currentEnemy >= ENEMIESTOTAL) {
        currentEnemy = 0;
    }
}



void Enemies::draw(int frame) {
    byte enemiesPerRow = ENEMIESTOTAL / ENEMYROWS;

    for (int i = 0; i < ENEMIESTOTAL; i++) {
        if (EnemiesOS[i].alive == true) {
            if (i < enemiesPerRow) {
                //Row 1
                if (frame == 0) {
                    ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien11,12,8);  
                } else {
                    ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien12,12,8);  
                }
            } else if (i < 2*enemiesPerRow) {
                //Row 2
                if (frame == 0) {
                    ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien21,12,8);  
                } else {
                    ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien22,12,8);  
                }        
            } else if (i < ENEMIESTOTAL) {
                //Row 3
                if (frame == 0) {
                    ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien31,8,8);  
                } else {
                    ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien32,8,8);  
                }
            }
        }
//    //Row 1
//    if (i <= ENEMIESTOTAL/ENEMYROWS && EnemiesOS[i].alive == true) {
//      if (frame == 0) {
//        ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien11,12,8);  
//      } else {
//        ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien12,12,8);  
//      }
//    }
//    //Row 2
//    else if (i <= (ENEMIESTOTAL/ENEMYROWS)*2 && EnemiesOS[i].alive == true) {
//      if (frame == 0) {
//        ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien21,12,8);  
//      } else {
//        ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien22,12,8);  
//      }        
//    }
//    //Row 3
//    else if (i <= ENEMIESTOTAL && EnemiesOS[i].alive == true) {
//      if (frame == 0) {
//        ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien31,8,8);  
//      } else {
//        ardu->drawBitmap(EnemiesOS[i].x, EnemiesOS[i].y, Alien32,8,8);  
//      }
//    }

    //Outside of screen
//    if (EnemiesOS[randomEnemy1].shot.y > 128) {
//      EnemiesOS[randomEnemy1].shot.onScreen = false;  
//    }
    
//    if (EnemiesOS[randomEnemy2].shot.y > 128) {
//      EnemiesOS[randomEnemy2].shot.onScreen = false;  
//    }
    //Shots
//    if (EnemiesOS[i].shot.onScreen == true) {
//      EnemiesOS[randomEnemy1].shot.y2 += EnemiesOS[randomEnemy1].shot.speed;
//      EnemiesOS[randomEnemy2].shot.y2 += EnemiesOS[randomEnemy2].shot.speed;
//
//      EnemiesOS[randomEnemy1].shot.y = EnemiesOS[randomEnemy1].shot.y2;
//      EnemiesOS[randomEnemy2].shot.y = EnemiesOS[randomEnemy2].shot.y2;
//      
//      ardu->drawFastVLine(EnemiesOS[i].shot.x,EnemiesOS[i].shot.y,3);  
//    }

    
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

bool Enemies::collide(Rect shot) {
    for (int i = 0; i < ENEMIESTOTAL; i++) {
        if (EnemiesOS[i].alive) {
//            if (i == 0) {
//                Serial.print("S:");
//                Serial.print(shot.x);
//                Serial.print(",");
//                Serial.print(shot.y);
//                Serial.print(",");
//                Serial.print(shot.width);
//                Serial.print(",");
//                Serial.println(shot.height);
//                
//                Serial.print("E0:");
//                Serial.print(EnemiesOS[0].hitbox.x);
//                Serial.print(",");
//                Serial.print(EnemiesOS[0].hitbox.y);
//                Serial.print(",");
//                Serial.print(EnemiesOS[0].hitbox.width);
//                Serial.print(",");
//                Serial.println(EnemiesOS[0].hitbox.height);
//            }
            
            if (ardu->collide(shot, EnemiesOS[i].hitbox)) {
                EnemiesOS[i].alive = false;
                return true;
            }
        }
    }
    return false;
}


