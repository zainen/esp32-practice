#define PIN_LED 21
#define PRESS_VAL 80000
#define RELEASE_VAL 60000

bool isProcessed = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(touchRead(T14) > PRESS_VAL) {
    if (!isProcessed) {
      isProcessed = true;
      Serial.println("touch detected!");
      reverseGPIO(PIN_LED);
    }
  }
  if (touchRead(T14) < RELEASE_VAL) {
    if(isProcessed) {
      isProcessed = false;
      Serial.println("released!");
    }
  }
}

void reverseGPIO(int pin) {
  digitalWrite(pin, !digitalRead(pin));
}
