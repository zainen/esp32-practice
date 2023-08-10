int dataPin = 12;
int latchPin = 13;
int clockPin = 14;

byte num[] = {
  0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e
};

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 16; i++) {
    writeData(num[i]);
    delay(1000);
    writeData(0xff);
  }
}

void writeData(int value) {
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, LSBFIRST, value);

  digitalWrite(latchPin, HIGH);
}
