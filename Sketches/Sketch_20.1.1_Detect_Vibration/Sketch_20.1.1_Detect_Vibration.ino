/*
  Sketch 20.1.1
  Detect Vibration

  modified 2016/8/17
  by http://www.freenove.com
*/

int buzzerPin = 13; // Define the buzzer pin
int switchPin = 3;  // Define the vibration switch pin, which can cause interrupt

bool isVibrate = false;

void setup() {
  pinMode(buzzerPin, OUTPUT);       // Set the buzzer pin to output mode
  pinMode(switchPin, INPUT_PULLUP); // Set the vibration switch pin to pull up input mode
  // Set interrupt, if vibration switch pin change from high level to low level, vibrate function will be called
  attachInterrupt(digitalPinToInterrupt(switchPin), vibrate, FALLING);
}

void loop() {
  if (isVibrate) {  // If the interrupt function is triggered
    isVibrate = false;  // Marked no trigger again
    digitalWrite(buzzerPin, HIGH);  // Open the buzzer
    delay(50);          // Delay for a period of time
  }
  else              // Else close the buzzer
    digitalWrite(buzzerPin, LOW);
}

void vibrate() {
  isVibrate = true; // Marked as the trigger
}

