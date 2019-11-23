
#include "Temperatura.hpp"

/**
 * Construtor
*/
Temperatura::Temperatura(){}

/**
 * Destrutor
*/
Temperatura::~Temperatura(){}

/**
 * Verificar se o sensor de temperatura está conectado
*/
bool Temperatura::verificar(DallasTemperature sensors, DeviceAddress sensor1){
  if(!sensors.getAddress(sensor1,0)){//Pesquisa se a sensor conectado caso não encontrar
      return false;
  }else{
      return true;//retorna verdade caso encontrar o sensor
  }
}

/**
 * Pegar Temperatura Atual
*/
float Temperatura::getTemp(){
  return this->temp;
}

/**
 * Insere Temperatura Atual
*/
void Temperatura::setTemp(float temp){
  this->temp = temp;
}

/**
 * Pegar a temperatura do ambiente
*/
bool Temperatura::celsius(DallasTemperature sensors,DeviceAddress sensor1){
    if(verificar(sensors,sensor1)){
      sensors.requestTemperatures();//Metodo para obter a temperatura
      setTemp(sensors.getTempC(sensor1));
      return true;
    }else{
      return false;
    }
}