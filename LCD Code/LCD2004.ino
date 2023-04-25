//LCD2004
//You should now see your LCD2004 display the characters 
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2017.3.7 
#include <LiquidCrystal.h>// include the library code
/**********************************************************/
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
/*********************************************************/
void setup()
{
  lcd.begin(20, 4);  // set up the LCD's number of columns and rows: 
}
/*********************************************************/
void loop() 
{
    lcd.setCursor(4,0);  // set the cursor to column 19, line 0
    lcd.print("Team Concoction");
    lcd.setCursor(4,1);
    lcd.print("DF 2100");
     lcd.setCursor(2,2);
    lcd.print("Hello!");
     lcd.setCursor(1,3);
    lcd.print("Syringe Pump");
   
}
/************************************************************/
