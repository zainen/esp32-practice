#define PIN_LED 2
#define CHN 0
#define FRQ 5000
#define PWM_BIT 8

void setup() {
  // put your setup code here, to run once:
  ledcSetup(CHN, FRQ, PWM_BIT);
  ledcAttachPin(PIN_LED, CHN);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 255; i++) {
    ledcWrite(CHN, i);
    delay(20);
  }
  for (int i = 255; i > - 1; i--) {
    ledcWrite(CHN, i);
    delay(20);
  }
}
