// Code written by Team Concoction.

#include <LiquidCrystal.h>// include the library code

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
float flowRate = 50.0; // the flow rate of the syringe, in mL/min.
float syringeSize = 5.0; // the capacity of the syringe, in mL.

void setup() {
  lcd.begin(20, 4);  // set up the LCD's number of columns and rows: 20 col, 4 rows
}

void loop() {
    int timeRemaining = (ceil(syringeSize*60/flowRate) - millis()/1000);
    timeRemaining = max(timeRemaining, 0);
    lcd.setCursor(0,0);  
    lcd.print("**Team Concoction**");

    lcd.setCursor(0,1);
    lcd.print("Flow rate:");

    lcd.setCursor(11,1);
    lcd.print((int)flowRate);

    lcd.setCursor(0, 2);
    lcd.print("Time until end (s): ");

    lcd.setCursor(0,3);
    lcd.print(timeRemaining);
   
}
