#include "Freenove_WS2812_Lib_for_ESP32.h"

#define LEDS_COUNT 8
#define LEDS_PIN 2
#define CHANNEL 0

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);

u8 m_colour[5][3] = { {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {0, 0, 0}};
int delayval = 50;

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.setBrightness(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < LEDS_COUNT; i++) {
      strip.setLedColorData(i, m_colour[j][0], m_colour[j][1], m_colour[j][2]);
      strip.show();
      delay(delayval);
    }
    delay(500);
  }
}
