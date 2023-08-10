void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("Touch value: %d \r\n", touchRead(T14));
  delay(1000);
}
