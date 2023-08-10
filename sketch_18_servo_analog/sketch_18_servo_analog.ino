#define SERVO_PIN 21
#define SERVO_CHN 0
#define SERVO_FRQ 50
#define SERVO_BIT 12
#define ADC_PIN 14

void servo_set_pin(int pin);
void servo_set_angle(int angle);

void setup() {
  // put your setup code here, to run once:
  servo_set_pin(SERVO_PIN);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potVal = analogRead(ADC_PIN);
  Serial.printf("potVal_1: %d\n", potVal);

  potVal = map(potVal, 0, 4095, 0, 180);

  servo_set_angle(potVal);
  Serial.printf("potVal_2: %d\n", potVal);
  delay(15);
}

void servo_set_pin(int pin) {
  ledcSetup(SERVO_CHN, SERVO_FRQ, SERVO_BIT);
  ledcAttachPin(pin, SERVO_CHN);
}

void servo_set_angle(int angle) {
  if (angle > 180 || angle < 0) 
    return;
  long pwm_value = map(angle, 0, 180, 103, 512);
  ledcWrite(SERVO_CHN, pwm_value);
}