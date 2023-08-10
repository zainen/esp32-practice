int dataPin = 12;
int latchPin = 13;
int clockPin = 14;

void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte x = 0x01;
  for (int j = 0; j < 8; j++) {
    writeTo595(LSBFIRST, x);
    x <<= 1;
    delay(50);
  }
  delay(1000);
  x = 0x80;
  for (int j = 0; j < 8; j++) {
    writeTo595(LSBFIRST, x);
    x >>= 1;
    delay(50);
  }
  delay(1000);
}

void writeTo595(int order, byte _data) {
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, order, _data);

  digitalWrite(latchPin, HIGH);
}