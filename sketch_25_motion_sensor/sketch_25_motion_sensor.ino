int sensorPin = 13;
int ledPin = 14;


void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, digitalRead(sensorPin));
  delay(1000);
}
