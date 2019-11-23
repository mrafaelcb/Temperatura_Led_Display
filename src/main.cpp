#include <Arduino.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>
#include <NewTone.h>
#include "Temperatura.hpp"
#include "Led.hpp"
#include "Lcd.hpp"

#define SERIAL 9600
//#define LED_1 9
#define INTERVALO 50
#define TEMPERATURA 10
#define LCD 0

//Led *led_1;
Temperatura *temperatura;
OneWire oneWire(TEMPERATURA);// Define uma instância do oneWire para comunicação com o sensor
DallasTemperature sensors(&oneWire);
DeviceAddress sensor_1; //Arrays para armazenar endereços de dispositivo(sensores)
LiquidCrystal lcd(8,9,4,5,6,7);
Lcd *tela;

byte Carregando[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

void setup() {
  Serial.begin(SERIAL);
  sensors.begin();
  lcd.createChar(0,Carregando);
  lcd.begin(16,2);
  //led_1 = new Led(LED_1, INTERVALO);
  temperatura = new Temperatura();
  temperatura->celsius(sensors,sensor_1);
  tela = new Lcd(LCD);
  lcd.setCursor(2,0);
  lcd.print("Bem-vindo ao");
  lcd.setCursor(5,1);
  lcd.print("Sensor");
  delay(1500);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("AGUARDE...");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ajustando...");
  temperatura->celsius(sensors,sensor_1);
  tela->carregar(lcd,200);
}

void loop() {
  if(temperatura->celsius(sensors,sensor_1)){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temperatura:");
    lcd.setCursor(10,1);
    Serial.println(String(temperatura->getTemp()) + "C");
    lcd.print(String(temperatura->getTemp()) + "C");
    delay(2000);
  }else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Desconectado.");
  }
}