void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("ESP32S3 Initialization Complete");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("Running time : %.1f s \n", millis() / 1000.0f);
  delay(1000);
}
