/*
  Sketch 4.1.1
  LEDs Emit Different Brightness

  modified 2016/5/13
  by http://www.freenove.com
*/

// set pin numbers:
int ledPin1 = 5,            // the number of the LED1 pin
    ledPin2 = 6,            // the number of the LED2 pin
    ledPin3 = 9,            // the number of the LED3 pin
    ledPin4 = 10;           // the number of the LED4 pin

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop()
{
  // set the ports output PWM waves with differrent duty cycle
  analogWrite(ledPin1, map(2, 0, 100, 0, 255));
  analogWrite(ledPin2, map(10, 0, 100, 0, 255));
  analogWrite(ledPin3, map(50, 0, 100, 0, 255));
  analogWrite(ledPin4, map(100, 0, 100, 0, 255));
}

