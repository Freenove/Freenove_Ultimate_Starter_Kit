/*
  Sketch 2.1.2
  Two LEDs Blink

  modified 2016/5/13
  by http://www.freenove.com
*/

// set pin numbers:
int led1Pin = 4;            // the number of the LED1 pin
int led2Pin = 5;            // the number of the LED2 pin

void setup() {
  // initialize the LED pin as an output:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  setLed(HIGH, LOW);      // set LED1 on, and LED2 off.
  setLed(LOW, HIGH);      // set LED1 off, and LED2 on.
}

void setLed(int led1, int led2) {
  digitalWrite(led1Pin, led1);   // the state of LED1 is determined by variable led1.
  digitalWrite(led2Pin, led2);   // the state of LED2 is determined by variable led2.
  delay(1000);                   // wait for a second
}

