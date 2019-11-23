#ifndef PROJECT_LED_HPP
#define PROJECT_LED_HPP
#include <Arduino.h>

/**
 * Classe - Led
*/
class Led{
  private:
      int pin;
      int intervalo;
  public:
      Led(int,int);//Construtor - Entrada Pino e intervalo para piscar
      ~Led(void);//Destrutor
      void acender(void);//Acender led
      void desligar(void);//Desligar led
      void piscar(void);//Piscar led
      //Gets e Sets
      void setPin(int);
      void setIntervalo(int);
      int getPin(void);
      int getIntervalo(void);
};

#endif