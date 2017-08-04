#include "Menu.h"
#include "Data.h"

Menu::Menu(Arduboy2 &arduboy) {
  this->ardu = &arduboy;  
}

void Menu::draw() {
  ardu->setCursor(32,10);
  ardu->print("Space Invaders");

  ardu->setCursor(32,32);
  ardu->print(str_start);

  ardu->setCursor(32,40);
  ardu->print(str_options);

  ardu->setCursor(32,48);
  ardu->print(str_highscores);
}

void Menu::setLang(byte lang) { 
  if (lang == 0) { //English 
    str_gameover = F("Game Over!");
    str_start = F("Start");
    str_options = F("Options");
    str_lang = F("Lanugages");
    str_back = F("Back");      
  } else if (lang == 1) { //German
    str_gameover = "Game Over!";
    str_start = "Anfang!";
    str_options = "Option";
    str_lang = "Sprache";
    str_back = "Zuruck";     
  } else if (lang == 2) { //French
    str_gameover = "Jeu termine!";
    str_start = "Commencer!";
    str_options = "Options";
    str_lang = "Lanuge";
    str_back = "Arriere";     
  } else if (lang == 3) { //Spanish
    str_gameover = "Partida Terminada!";
    str_start = "Empezar!";
    str_options = "Opciones";
    str_lang = "Idioma";
    str_back = "Espalda";     
  } else if (lang == 4) { //Japaneese
    str_gameover = "Gemu oba!";
    str_start = "Sutato!";
    str_options = "Opushon";
    str_lang = "Hanasu";
    str_back = "Bakku";     
  } else if (lang == 5) { //Swedish
    str_gameover = "Game Over!";
    str_start = "Start";
    str_options = "Instaellningar";
    str_lang = "Sprak";
    str_back = "Tillbaka";     
  }
}

