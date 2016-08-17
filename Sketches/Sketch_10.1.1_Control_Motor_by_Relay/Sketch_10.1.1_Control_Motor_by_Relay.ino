/*
  Sketch 10.1.1
  Control Motor by Relay

  modified 2016/5/13
  by http://www.freenove.com
*/

int relayPin = 9;     // the number of the relay pin
int buttonPin = 12;   // the number of the push button pin

int buttonState = HIGH;     // Record button state, and initial the state to high level
int relayState = LOW;       // Record relay state, and initial the state to low level
int lastButtonState = HIGH; // Record the button state of last detection
long lastChangeTime = 0;    // Record the time point for button state change

void setup() {
  pinMode(buttonPin, INPUT);  // Set push button pin into input mode
  pinMode(relayPin, OUTPUT);  // Set relay pin into output mode
  digitalWrite(relayPin, relayState); // Set the initial state of relay into "off"
  Serial.begin(9600);                 // Initialize serial port,and set baud rate to 9600
}

void loop() {
  int nowButtonState = digitalRead(buttonPin); // Read current state of button pin
  // If button pin state has changed, record the time point
  if (nowButtonState != lastButtonState) {
    lastChangeTime = millis();
  }
  // If button state changes, and stays stable for a while, then it should have skipped the bounce area
  if (millis() - lastChangeTime > 10) {
    if (buttonState != nowButtonState) {  // Confirm button state has changed
      buttonState = nowButtonState;
      if (buttonState == LOW) {     // Low level indicates the button is pressed
        relayState = !relayState;           // Reverse relay state
        digitalWrite(relayPin, relayState); // Update relay state
        Serial.println("Button is Pressed!");
      }
      else {                        // High level indicates the button is released
        Serial.println("Button is Released!");
      }
    }
  }
  lastButtonState = nowButtonState; // Save the state of last button
}

