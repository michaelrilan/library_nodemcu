//#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27,20,4); 
//void setup() {
//  // put your setup code here, to run once:
//  lcd.init();
//  lcd.backlight();
//  lcd.setCursor(0,0);
//  lcd.print("qwertyuiopasdfghjkzx");
//  lcd.setCursor(0,1);
//  lcd.print("HEHEHEHE");
//  lcd.setCursor(0,2);
//  lcd.print("waaaaa");
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//
//}
// include the library code:
//#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27,20,4); 
//
//// initialize the library by associating any needed LCD interface pin
//// with the arduino pin number it is connected to
//
//void setup() {
//  // set up the LCD's number of columns and rows:
//  lcd.init();
//  // Print a message to the LCD.
//  lcd.backlight();
//  lcd.setCursor(0,0);
//  lcd.print("hello, world!");
//  delay(1000);
//}
//
//void loop() {
//    
//  // scroll 13 positions (string length) to the left
//  // to move it offscreen left:
//
//
//  // scroll 29 positions (string length + display length) to the right
//  // to move it offscreen right:
//  {
//  for (int positionCounter = 0; positionCounter < 20; positionCounter++) {
//    // scroll one position right:
//    lcd.setCursor(0,0);
//    lcd.scrollDisplayLeft();
//    // wait a bit:
//    delay(500);
//  } 
//  }
//
//
//
//}
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // F Malpartida's NewLiquidCrystal library
LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {

// Switch on the backlight
lcd.backlight();

// Reset the display
lcd.clear();
delay(500);
lcd.home();
}

void loop() {

// Print on the LCD
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("Yellow");
lcd.setCursor(0,1);
lcd.print("Purple");
  
// scroll 20 positions (display length + string length) to the left
 // to move it back to center:
 for (int positionCounter = 0; positionCounter < 20; positionCounter++) {
   // scroll one position left:
   lcd.scrollDisplayLeft();
   // wait a bit:
   delay(300);
   }

  // delay at the end of the full loop:
  delay(2000);
 
}
