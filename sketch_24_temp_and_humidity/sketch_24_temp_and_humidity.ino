#include <DHTesp.h>

DHTesp dht;
int dhtPin = 21;

void setup() {
  // put your setup code here, to run once:
  dht.setup(dhtPin, DHTesp::DHT11);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  flag:TempAndHumidity newValues = dht.getTempAndHumidity();
  if(dht.getStatus() != 0) {
    goto flag;
  }
  Serial.println(" Temperature: " + String(newValues.temperature) + " Humidity: " + String(newValues.humidity));
  delay(2000);
}
