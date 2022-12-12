#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); 
int button = 12; 
int ledPin = 13;
int buttonState=0;
void setup() {
 Serial.begin(115200);
 pinMode(button, INPUT);
 pinMode(ledPin, OUTPUT);
 lcd.init();
 lcd.backlight();
 lcd.setCursor(0,0);
 lcd.print("asfdasdf");
 lcd.setCursor(0,1);
 lcd.print("fsadf");
 lcd.setCursor(0,2);
 lcd.print("fasdf");
 lcd.setCursor(0,3);
 lcd.print("Sdfdsff");
}
void loop() {
 buttonState=digitalRead(button); // put your main code here, to run repeatedly:
 if (buttonState == 1)
 {
 Serial.println("11");
 digitalWrite(ledPin, HIGH);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Book Name:");
 lcd.setCursor(0,1);
 lcd.print("Pisiks");
 lcd.setCursor(0,2);
 lcd.print("Row:");
 lcd.setCursor(0,3);
 lcd.print("Yung nailaw");
 delay(5000);
 }
 if (buttonState==0)
 {
  
 Serial.println("00");
 digitalWrite(ledPin, LOW);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("asfdasdf");
 lcd.setCursor(0,1);
 lcd.print("fsadf");
 lcd.setCursor(0,2);
 lcd.print("fasdf");
 lcd.setCursor(0,3);
 lcd.print("Sdfdsff");
 
 delay(200);
 }
}
