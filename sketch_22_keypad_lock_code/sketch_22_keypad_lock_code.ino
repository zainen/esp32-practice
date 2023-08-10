#include <Keypad.h>

#define SERVO_PIN 21
#define SERVO_CHN 0
#define SERVO_FRQ 50
#define SERVO_BIT 12
#define BUZZER_PIN 17

void servo_set_pin(int pin);
void servo_set_angle(int angle);

byte rowPins[4] = {14, 13, 12, 11}; 
byte colPins[4] = {10, 9, 8, 18}; 

char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
 
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

char passWord[]= {"1234"};

void setup() {
  // put your setup code here, to run once:
  servo_set_pin(SERVO_PIN);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  static char keyIn[4];
  static byte keyInNum = 0;
  char keyPressed = myKeypad.getKey();

  if (keyPressed) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);

    keyIn[keyInNum++] = keyPressed;

    if (keyInNum == 4) {
      bool isRight = true;
      for (int i = 0; i < 4; i++) {
        if (keyIn[i] != passWord[i]) {
          isRight = false;
        }
      }
      if (isRight) {
        servo_set_angle(90);
        delay(2000);
        servo_set_angle(0);
        Serial.println("passWord Right!");
      } else {
        digitalWrite(BUZZER_PIN, HIGH);
        delay(1000);
        digitalWrite(BUZZER_PIN, LOW);
        Serial.println("passWord error!");
      }
      keyInNum = 0;
    }
  }
}

void servo_set_pin(int pin) {
  ledcSetup(SERVO_CHN, SERVO_FRQ, SERVO_BIT);
  ledcAttachPin(pin, SERVO_CHN);
}

void servo_set_angle(int angle) {
  if (angle > 180 || angle < 0) {
    return;
  }
  long pwm_value = map(angle, 0, 180, 103, 512);
  ledcWrite(SERVO_CHN, pwm_value);
}
