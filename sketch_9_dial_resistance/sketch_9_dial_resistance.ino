#define PIN_ANALOG_IN 1


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adcVal = analogRead(PIN_ANALOG_IN);
  double voltage = adcVal / 4095.0 * 3.3;
  Serial.printf("ADC val: %d, \t Voltage: %.2fV\r\n", adcVal, voltage);
  delay(200);
}
