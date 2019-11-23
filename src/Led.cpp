#include "Led.hpp"

/**
 * Construtor
 * Entrada Pino e intervalo para piscar
*/
Led::Led(int pin,int intervalo){
    this->setPin(pin);
    this->setIntervalo(intervalo);
};

/**
 * Destrutor
*/
Led::~Led(){
};

/**
 * Acender led
*/
void Led::acender(){
    digitalWrite(this->getPin(), HIGH);
};

/**
 * Desligar led
*/
void Led::desligar(){
    digitalWrite(this->getPin(), LOW);
    delay(this->getIntervalo());
};

/**
 * Piscar led
*/
void Led::piscar(){
    this->acender();
    delay(this->getIntervalo());
    this->desligar();
}

/**
 * Gets e Sets
*/
void Led::setPin(int pin){
    this->pin = pin;
    pinMode(this->pin, OUTPUT);
}

void Led::setIntervalo(int intervalo){
    this->intervalo = intervalo;
}

int Led::getPin(){
    return this->pin;
}

int Led::getIntervalo(){
    return this->intervalo;
};