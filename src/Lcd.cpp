#include "Lcd.hpp"

Lcd::Lcd(int pino){
    this->pino = pino;
}

Lcd::~Lcd(){}

int Lcd::opcao(){
    button = analogRead(pino);

    if(button>=100 && button<=160){
        this->button=1;
        return 1;
    }else if(button>=260 && button<=360){
        this->button=2;
        return 2;
    }else if(button>=400 && button<=560){
        this-> button=3;
        return 3;
    }else if(button>=0 && button<=75){
        this->button=4;
        return 4;
    }else if(button>=600 && button<=780){
        this->button=5;
        return 5;
    }else{
        return opcao();
    }
}

void Lcd::botao(LiquidCrystal lcd){
 lcd.setCursor(0,0);
 lcd.print("Tecla apertada:");
 lcd.setCursor(0,1);
 switch(button){
  case 1:{
     lcd.print("Cima");
  }break;
  case 2:{
    lcd.print("Baixo");
  }break;
  case 3:{
    lcd.print("Esquerda");
  }break;
  case 4:{
    lcd.print("Direita");
  }break;
  case 5:{
    lcd.print("Select");
  }break;
  default:{
    lcd.print("Invalida");
  }
 }
}

void Lcd::carregar(LiquidCrystal lcd,int tempo){
  for(int i=0;i<16;i++){
        lcd.setCursor(i,1);
        lcd.write(byte(0));
        delay(tempo);
    }
     lcd.clear();
}
