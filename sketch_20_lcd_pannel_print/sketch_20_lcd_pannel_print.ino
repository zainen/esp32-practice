#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SDA 14
#define SCL 13

LiquidCrystal_I2C lcd(0x27, 15, 2);

void setup() {
  // put your setup code here, to run once:
  Wire.begin(SDA, SCL);
  if (!i2CAddrTest(0x27)) {
    lcd = LiquidCrystal_I2C(0x3F, 16, 2);
  }
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("hello world!");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 1);
  lcd.print("Counter: ");
  lcd.print(millis() / 1000);
  delay(1000);
}

bool i2CAddrTest(uint8_t addr) {
  Wire.begin();
  Wire.beginTransmission(addr);
  if (Wire.endTransmission () == 0) {
    return true;
  }
  return false;
}
