#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

String message=("Philosophy: a text with readings");
int length;


void setup() {
 lcd.init();
 lcd.backlight();
 length=message.length();

}

void loop() 
{
  for(int i=0;i<length;i++)
  {
    ClearRow(2);
    lcd.print(message.substring(i,i+20));
    delay(200);
    }
   
}

void ClearRow(int rowNum)
{
  lcd.setCursor(0, rowNum);
  lcd.print("                     ");
  lcd.setCursor(0,rowNum);
  }
