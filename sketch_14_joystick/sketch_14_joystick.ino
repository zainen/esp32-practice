int xyzPins[] = {14, 13, 12};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(xyzPins[2], INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = analogRead(xyzPins[2]);
  Serial.printf("X: %.d \t Y: %.d \t Z: %.d \n", xVal, yVal, zVal);
  delay(500);
}
