const byte ledPins[] = {38, 39, 40};
const byte chns[] = {0, 1, 2};
int red, green, blue;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 3; i++) {
    ledcSetup(chns[i], 1000, 8);
    ledcAttachPin(ledPins[i], chns[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  red = random(0, 256);
  green = random(0, 256);
  blue = random(0, 256);
  setColour(red, green, blue);
  delay(200);
}

void setColour(byte r, byte g, byte b) {
  ledcWrite(chns[0], 255 - r);
  ledcWrite(chns[1], 255 - g);
  ledcWrite(chns[2], 255 - b);
}
