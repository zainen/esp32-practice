#define PIN_BUTTON 21
#define PIN_BUZZER 14
#define CHN 0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
  Serial.printf("setup: %f \n", ledcSetup(CHN, 1, 10));
  Serial.printf("write: %f \n", ledcWriteTone(CHN, 0));
  ledcAttachPin(PIN_BUZZER, CHN);
  ledcWriteTone(CHN, 2000);
  delay(300);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(PIN_BUTTON) == LOW) {
    alert();
  } else {
    ledcWriteTone(CHN, 0);
  }
}

void alert() {
  float sinVal;
  int toneVal;
  for (int x = 0; x < 360; x += 10) {
    sinVal = sin(x * (PI / 180));
    toneVal = 2000 + sinVal * 500;
    ledcWriteTone(CHN, toneVal);
    delay(100);
  }
}
