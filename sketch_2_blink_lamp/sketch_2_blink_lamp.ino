#define PIN_LED 1
#define PIN_BUTTON 13

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(PIN_BUTTON) == LOW) {
    delay(20);
    if (digitalRead(PIN_BUTTON) == LOW) {
      reverseGPIO(PIN_LED);
    }
    while(digitalRead(PIN_BUTTON) == LOW);
    delay(20);
    while(digitalRead(PIN_BUTTON) == LOW);
  }
}


void reverseGPIO(int pin) {
  digitalWrite(pin, !digitalRead(pin));
}