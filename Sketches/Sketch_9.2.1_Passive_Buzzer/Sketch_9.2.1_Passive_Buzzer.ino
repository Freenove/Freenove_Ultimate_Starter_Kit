/*
  Sketch 9.2.1
  Passive Buzzer

  modified 2016/5/13
  by http://www.freenove.com
*/

int buzzerPin = 9;    // the number of the buzzer pin
float sinVal;         // Define a variable to save sine value
int toneVal;          // Define a variable to save sound frequency

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set Buzzer pin to output mode
}

void loop() {
  for (int x = 0; x < 360; x++) {       // X from 0 degree->360 degree
    sinVal = sin(x * (PI / 180));       // Calculate the sine of x
    toneVal = 2000 + sinVal * 500;      // Calculate sound frequency according to the sine of x
    tone(buzzerPin, toneVal);           // Output sound frequency to buzzerPin
    delay(1);
  }
}

