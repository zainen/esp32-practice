int outPorts[] = { 14, 13, 12, 11 };

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 4; i++) {
    pinMode(outPorts[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  moveSteps(true, 32 * 64, 3);
  delay(3000);
}

void moveSteps( bool dir, int steps, byte ms) {
  for (unsigned long i = 0; i < steps; i++) {
    moveOneStep(dir);
    delay(constrain(ms, 3, 20));
  }
}

void moveOneStep(bool dir) {
  static byte out = 0x01;

  if (dir) {
    out != 0x08 ? out = out << 1 : out = 0x01;
  } else {
    out != 0x01 ? out = out >> 1 : out = 0x08;
  }

  for (int i = 0; i < 4; i++ ) {
    digitalWrite(outPorts[i], (out & (0x01 << i)) ? HIGH : LOW);
  }
}

void moveAround(bool dir, int turns, byte ms) {
  for (int i = 0; i < turns; i++) {
    moveSteps(dir, 32 * 64, ms);
  }
}

void moveAngle(bool dir, int angle, byte ms) {
  moveSteps(dir, (angle * 32 * 64/360), ms);
}