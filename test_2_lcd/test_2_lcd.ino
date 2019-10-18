#include <LiquidCrystal.h>

LiquidCrystal lcd(12,7,6,9,10,11,5,4,3,2);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.print("o");
}

void loop() {
  // put your main code here, to run repeatedly:

}
