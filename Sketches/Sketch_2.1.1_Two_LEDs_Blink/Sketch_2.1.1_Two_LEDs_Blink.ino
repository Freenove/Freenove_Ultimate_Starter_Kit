/*
  Sketch 2.1.1
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
  digitalWrite(led1Pin, HIGH);   // turn the LED1 on
  digitalWrite(led2Pin, LOW);    // turn the LED2 off
  delay(1000);                   // wait for a second

  digitalWrite(led1Pin, LOW);    // turn the LED1 off
  digitalWrite(led2Pin, HIGH);   // turn the LED2 on
  delay(1000);                   // wait for a second
}

