const byte adcChns[] = { 12, 13, 14 };
const byte ledPins[] = { 38, 39, 40 };
const byte pwmChns[] = { 0, 1, 2 };
int colours[] = { 0, 0, 0 };

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 3; i++) {
    ledcSetup(pwmChns[i], 1000, 8);
    ledcAttachPin(ledPins[i], pwmChns[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 3; i++) {
    colours[i] = map(analogRead(adcChns[i]), 0, 4096, 0, 255);
    Serial.printf("colour val %.d : %.d", i, colours[i]);
    ledcWrite(pwmChns[i], 256 - colours[i]);
  }
  delay(10);
}
