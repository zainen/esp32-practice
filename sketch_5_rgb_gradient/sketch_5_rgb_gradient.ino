const byte ledPins[] = {38, 39, 40};
const byte chns[] = {0, 1, 2};


void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 3; i++) {
  ledcSetup(chns[i], 1000, 8);
  ledcAttachPin(ledPins[i], chns[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 256; i++) {
    setColour(wheel(i));
    delay(20);
  }
}

void setColour(long rgb) {
  ledcWrite(chns[0], 255 - (rgb >> 16) & 0xFF);
  ledcWrite(chns[1], 255 - (rgb >> 8) & 0xFF);
  ledcWrite(chns[2], 255 - (rgb >> 0) & 0xFF);
}

long wheel(int pos) {
  long WheelPos = pos % 0xff;
  if (WheelPos < 85) {
    WheelPos -= 85;
    return (((255 - WheelPos * 3) << 8) | (WheelPos * 3));
  } else {
    WheelPos -= 170;
    return ((WheelPos * 3) << 16 | (255 - WheelPos * 3));
  }
}