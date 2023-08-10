#include "Freenove_WS2812_Lib_for_ESP32.h"

#define PIN_POT 1
#define LEDS_COUNT 8
#define LEDS_PIN 14
#define CHANNEL 0
#define BRIGHTNESS 20

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);

void setup() {
  // put your setup code here, to run once:
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int colourPos = map(analogRead(PIN_POT), 0, 4095, 0, 255);
  for (int i = 0; i < LEDS_COUNT; i++) {
    strip.setLedColorData(i, strip.Wheel(colourPos + i * 255 / 8));
  }
  strip.show();
  delay(10);
}
