#define PIN_ANALOG_IN 1
#define PIN_LED 14
#define CHAN 0
#define LIGHT_MIN 372
#define LIGHT_MAX 2048

void setup() {
  ledcSetup(CHAN, 1000, 12);
  ledcAttachPin(PIN_LED, CHAN);
}
void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN); //read adc
  int pwmVal = map(constrain(adcVal, LIGHT_MIN, LIGHT_MAX), LIGHT_MIN, LIGHT_MAX, 0, 4095);
  // adcVal re-map to pwmVal
  ledcWrite(CHAN, pwmVal);
  delay(10);
}