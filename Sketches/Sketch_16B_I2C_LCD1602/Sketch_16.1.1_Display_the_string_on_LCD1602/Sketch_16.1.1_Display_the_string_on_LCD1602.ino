/*
  Sketch 16.1.1
  Display the string on LCD1602

  modified 2016/5/13
  by http://www.freenove.com
*/
#include <LiquidCrystal_I2C.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();                // initialize the lcd
  lcd.backlight();           // Turn on backlight
  lcd.print("hello, world!");// Print a message to the LCD
}

void loop() {
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);// set the cursor to column 0, line 1
  // print the number of seconds since reset:
  lcd.print("Counter:");
  lcd.print(millis() / 1000);
}
