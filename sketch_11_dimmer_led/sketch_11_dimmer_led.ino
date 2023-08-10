#define PIN_ANALOG_IN 1
#define PIN_LED 21
#define CHAN 0

void setup() {
  // put your setup code here, to run once:
  ledcSetup(CHAN, 1000, 12);
  ledcAttachPin(PIN_LED, CHAN);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adcVal = analogRead(PIN_ANALOG_IN);
  int pwmVal = adcVal;
  ledcWrite(CHAN, pwmVal);
  delay(10);
}
