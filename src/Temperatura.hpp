#ifndef PROJECT_TEMPERATURA_HPP
#define PROJECT_TEMPERATURA_HPP
#include <DallasTemperature.h>

/**
 * Classe - Temneratura
*/
class Temperatura{
   public:
      Temperatura();//Construtor
      ~Temperatura();//Destrutor
      bool verificar(DallasTemperature,DeviceAddress);//Verificar se o sensor de temperatura está conectado
      float getTemp();//Pegar Temperatura Atual
      void setTemp(float);//Inserir Temperatura
      bool celsius(DallasTemperature,DeviceAddress);//Pegar a temperatura do ambiente
  private:
      float temp=0;
};

#endif
