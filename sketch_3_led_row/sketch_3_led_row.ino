byte ledPins[] = {21, 47, 48, 38, 39, 40, 41, 42, 2, 1};
int ledCounts;

void setup() {
  // put your setup code here, to run once:
  ledCounts = sizeof(ledPins);
  for (int i = 0; i < ledCounts; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < ledCounts; i++) {
    i++;
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  } 
  for (int i = ledCounts - 2; i > -1; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
    i--;
  }
}
