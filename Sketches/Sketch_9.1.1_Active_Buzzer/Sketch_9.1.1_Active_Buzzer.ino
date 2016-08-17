/*
  Sketch 9.1.1
  Active Buzzer

  modified 2016/5/13
  by http://www.freenove.com
*/

int buttonPin = 12;   // the number of the push button pin
int buzzerPin = 9;    // the number of the buzzer pin

void setup() {
  pinMode(buttonPin, INPUT);  // Set push button pin into input mode
  pinMode(buzzerPin, OUTPUT); // Set Buzzer pin into output mode
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) // If the pin is high level, the button is not pressed.
    digitalWrite(buzzerPin, LOW);     // Turn off Buzzer
  else                                // The button is pressed, if the pin is low level
    digitalWrite(buzzerPin, HIGH);    // Turn on Buzzer
}

