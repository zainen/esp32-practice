const byte ledPins[] = {21, 47, 38, 39, 40, 41, 42, 2};
const byte chns[] = {0, 1, 2, 3, 4, 5, 6, 7};
const int dutys[] = {0, 0, 0, 0, 0, 0, 0, 0,
                      1023, 512, 256, 128, 64, 32, 16, 8,
                      0, 0, 0, 0, 0, 0, 0, 0
                      };

int ledCounts;
int delayTimes = 50;
void setup() {
  // put your setup code here, to run once:
  ledCounts = sizeof(ledPins);
  for (int i = 0; i < ledCounts; i++) {
    ledcSetup(chns[i], 1000, 10);
    ledcAttachPin(ledPins[i], chns[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 16; i++) {
    for ( int j = 0; j < ledCounts; j++) {
      ledcWrite(chns[j], dutys[i + j]);
    }
    delay(delayTimes);
  }
  for (int i = 0; i < 16; i++) {
    for (int j = ledCounts - 1; j > -1; j--) {
      ledcWrite(chns[j], dutys[i + (ledCounts - 1 - j)]);
    }
    delay(delayTimes);
  }
}
