#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 6 //kerrotaan mitä analogpinniä datasignaali pin käyttää
#define DHTTYPE DHT11 //kerrotaan mikä sensori

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT dht(DHTPIN, DHTTYPE);

void setup() {

    dht.begin();// käynnistetään mittaus sensori

    lcd.begin(16, 2); //laitetaan näyttö päälle
    lcd.setCursor(0, 0); //laitetaan cursor ekalle riville ja ekalle sarakkeelle
    lcd.print("Welcome user!");
    delay(5000);
    lcd.clear();

}

void loop() {
   lcd.setCursor(0,0);// set the cursor on the first row and column 
      lcd.print("Humidity="); 
      lcd.print((float)dht.readHumidity());//printataan näytölle kosteus floattina tarrkuuden takia
      lcd.print("%"); 
      lcd.setCursor(0,1);
      lcd.print("Temp="); 
      lcd.print((float)dht.readTemperature());//printataan lämpö celsiuksen joka on mittarin oletus mittaus
      lcd.print("Celsius"); 
      delay(2000); 
  }
