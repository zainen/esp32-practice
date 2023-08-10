#define IN_POT 1
int in1Pin = 13;
int in2Pin = 14;
int enable1Pin = 12;
int channel = 0;


boolean rotationDir;
int rotationSpeed;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enable1Pin, OUTPUT);

  ledcSetup(channel, 1000, 11);
  ledcAttachPin(enable1Pin, channel);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potVal = analogRead(IN_POT);
  rotationSpeed = potVal - 2048;
  if (potVal > 2048) {
    rotationDir = true;
  } else {
    rotationDir = false;
  }
  rotationSpeed = abs(potVal - 2048);
  driveMotor(rotationDir, constrain(rotationSpeed, 0, 2048));
}

void driveMotor(boolean dir, int spd) {
  if(dir) {
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
  } else {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
  }
}
