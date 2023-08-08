#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//#include <hd44780.h>

//I2C주소확인
LiquidCrystal_I2C lcd(0x3F,16,2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("No Warning :)");

  if (Serial.available() > 0) {
    
    while(Serial.available()>0) {
      String data = Serial.readString();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("!!!Warning!!!");
      lcd.setCursor(0,1);
      lcd.print("detected ");
      lcd.print(data);
      delay(600);
      lcd.clear();
    }    
  }
} 



  //else {
  //  lcd.clear();
  //  lcd.print("No Warning :)"); 
  //}


  //else { 
  //  lcd.clear();
  //  lcd.print("No Warning :)");
  //  }
  

