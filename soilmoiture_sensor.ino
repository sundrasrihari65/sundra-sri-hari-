#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
int led1=7;
int led2=8;
int led3=12;
int moiture_sensor=A0;
void setup() {
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(led3,OUTPUT);
 pinMode(moiture_sensor,INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("HELLO");

}

void loop() {
  int data=analogRead(moiture_sensor);
  lcd.clear();
  if(data>700) {
  lcd.setCursor(0,0);
  lcd.print("soil_is_dry"); 
  digitalWrite(led1,1);
  delay(200);
  digitalWrite(led1,0);
  }
  else if(data>600&&data<700) {
  lcd.setCursor(0,0);
  lcd.print("in_goodcondition");
  digitalWrite(led2,1);
  delay(200); 
  digitalWrite(led2,0);
  }
  else   {
    lcd.setCursor(0,0);
    lcd.print("toomuch_water");
    digitalWrite(led3,1);
    delay(200);
    digitalWrite(led3,0);
  }
}
