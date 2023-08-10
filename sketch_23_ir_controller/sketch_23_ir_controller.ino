#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t recvPin = 21;
IRrecv irrecv(recvPin);
decode_results results;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  irrecv.enableIRIn();
  Serial.print("IRrecvDemo is not running and waiting for IR meesage on Pin ");
  Serial.println(recvPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
    serialPrintUint64(results.value, HEX);
    Serial.println("");
    irrecv.resume();
  }
  delay(1000);
}
