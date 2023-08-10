#include <Keypad.h> 
char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[4] = { 14, 13, 12, 11};
byte colPins[4] = {10, 9, 8, 18};

Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("ESP32S3 is ready!");
}
void loop() {
  // put your main code here, to run repeatedly:
  char keyPressed = myKeypad.getKey();
  if (keyPressed) {
    Serial.println(keyPressed);
  }
}
