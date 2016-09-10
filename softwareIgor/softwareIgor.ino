#include <LiquidCrystal.h>
#include <Wire.h>
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);


int sensorPinA0 = A0;
int sensorPinA1 = A1;

int contadorEntrada = 0;
int contadorSaida = 0;

int contenta0 = 0;
int contenta1 = 0;

boolean cont = true;
boolean control = true;
int pecas = 10;
void setup() {

  Serial.begin(9600);
  lcd.begin();
}
void loop() {

  do
  {
    contadorEntrada = analogRead(sensorPinA1);

    if (contadorEntrada >= 30) {
      if (control) {
        programaIgor();
        //delay(300);
        control = false;
      }
    } else {
      control = true;
    }
  } while (cont);
}

void programaIgor() {
  lcd.setCursor(0, 0);
  pecas = pecas - 1;
  lcd.backlight();
  if(pecas  < 0){
    lcd.print("Termino!!!!!!");
    lcd.print(pecas * (-1));
    //delay(20000);
  }else{
    lcd.print("Entrada.: ");
  lcd.print(pecas);
  }
}

