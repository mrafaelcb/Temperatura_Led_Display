#ifndef PROJECT_LCD_HPP
#define PROJECT_LCD_HPP
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <string.h>

/**
 * Classe - Lcd
*/
class Lcd{
   public:
       Lcd(int pino);
       ~Lcd();
        int opcao();
        void botao(LiquidCrystal lcd);
        void carregar(LiquidCrystal lcd,int tempo);
  private:
    int pino;
    int button;
};

#endif