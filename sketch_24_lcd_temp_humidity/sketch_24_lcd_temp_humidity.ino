#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHTesp.h"

#define SDA 14
#define SCL 13

DHTesp dht;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int dhtPin = 21;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(SDA, SCL);
  if (!i2CAddrTest(0x27)) {
    lcd = LiquidCrystal_I2C(0x3F, 16, 2);
  }
  lcd.init();
  lcd.backlight();
  dht.setup(dhtPin, DHTesp::DHT11);
}

void loop() {
  // put your main code here, to run repeatedly:
  flag:TempAndHumidity DHT = dht.getTempAndHumidity();
  if (dht.getStatus() != 0) {
    goto flag;
  }
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
  lcd.print(DHT.temperature);
  lcd.setCursor(0, 1);
  lcd.print("Humidity:   ");
  lcd.print(DHT.humidity);
  delay(2000);
}

bool i2CAddrTest(uint8_t addr) {
  Wire.begin();
  Wire.beginTransmission(addr);
  if (Wire.endTransmission() == 0) {
    return true;
  }
  return false;
}
