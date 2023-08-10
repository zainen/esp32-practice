#define PIN_ANALOG_IN 1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adcValue = analogRead(PIN_ANALOG_IN);
  double voltage = (float)adcValue / 4095.0 * 3.3;
  double Rt = 10 * voltage / (3.3 - voltage);
  double tempK = 1 / (1 / (273.15 + 25) + log(Rt / 10) / 3950.0);
  double tempC = tempK - 273.15;
  Serial.printf("ADC value : %d, \t Voltage : %.2fV, \tTemperature : %.2fC \n", adcValue, voltage, tempC);
  delay(1000);
}
