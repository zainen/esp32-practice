int relayPin = 14;

// the number of the relay pin
int buttonPin = 21; // the number of the push button pin
int buttonState = HIGH; // Record button state, and initial the state to high level
int relayState = LOW; // Record relay state, and initial the state to low level
int lastButtonState = HIGH; // Record the button state of last detection
long lastChangeTime = 0;
// Record the time point for button state change
void setup() {
pinMode(buttonPin, INPUT_PULLUP); // Set push button pin into input mode
pinMode(relayPin, OUTPUT); // Set relay pin into output mode
digitalWrite(relayPin, relayState); // Set the initial state of relay into "off"
}
void loop() {
int nowButtonState = digitalRead(buttonPin);// Read current state of button pin
// If button pin state has changed, record the time point
if (nowButtonState != lastButtonState) {
lastChangeTime = millis();
}
// If button state changes, and stays stable for a while, then it should have skipped the bounce area
if (millis() - lastChangeTime > 10) {
if (buttonState != nowButtonState) {
// Confirm button state has changed
buttonState = nowButtonState;
if (buttonState == LOW) {
relayState = !relayState;
// Low level indicates the button is pressed
// Reverse relay state
digitalWrite(relayPin, relayState); // Update relay state
}
}
}
lastButtonState = nowButtonState; // Save the state of last button
}