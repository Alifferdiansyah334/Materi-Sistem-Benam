// LCD sederhana

#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float progress = 0;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("1120910000052");
  lcd.setCursor(0, 1);
  lcd.print("Hello World");
}