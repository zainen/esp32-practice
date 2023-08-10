String inputString = "";
bool stringComplete = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println(String("]\nESP32S3 initialization completed! \r\n")
                  + String ("Please input some characters, \r\n")
                  + String("selects \"NewLine\" below and Ctrl + Enter to send a message to ESP32S3 \r\n")
                );
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char inChar = Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
  if (stringComplete) {
    Serial.printf("inputString: %s \n", inputString);
    inputString = "";
    stringComplete = false;
  }
}
