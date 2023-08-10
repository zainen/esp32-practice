#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t recvPin = 21;
IRrecv irrecv(recvPin);
decode_results results;

int ledPin = 13;
int buzzerPin = 14;

void setup() {
  // put your setup code here, to run once:
  ledcSetup(0, 1000, 8);
  ledcAttachPin(ledPin, 0);
  pinMode(buzzerPin, OUTPUT);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
    handleControl(results.value);
    irrecv.resume();
  }
}

void handleControl(unsigned long value) {
  Serial.print(value);
  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);

  switch (value) {
    case 0xFF6897: // 0
      ledcWrite(0, 0);
      break;
    case 0xFF30CF: // 1
      ledcWrite(0, 7);
      break;
    case 0xFF18E7: // 2
      ledcWrite(0, 63);
      break;
    case 0xFF7A85: // 3
      ledcWrite(0, 255);
      break;
  }
}
