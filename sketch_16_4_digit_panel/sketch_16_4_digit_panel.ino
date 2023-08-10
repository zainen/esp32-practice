int latchPin = 39;
int clockPin = 40;
int dataPin = 38;
int comPin[] = {21, 47, 35, 36};

byte num[] = {
  0xc0, 0xf9, 0xa4, 0x0b, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x8e
};

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(comPin[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 4; i++) {
    electDigitalDisplay(i);

    writeData(num[i]);
    delay(5);
    writeData(0xff);
  }
}

void electDigitalDisplay(byte com) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(comPin[i], LOW);
  }
  digitalWrite(comPin[com], HIGH);
}

void writeData(int val) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, val);
  digitalWrite(latchPin, HIGH);
}