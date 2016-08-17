/*
  Sketch 23.1.1
  Infrared Motion Sensor

  modified 2016/8/17
  by http://www.freenove.com
*/

int sensorPin = 12; // the number of the infrared motion sensor pin
int ledPin = 13;    // the number of the LED pin

void setup() {
  pinMode(sensorPin, INPUT);  // initialize the sensor pin as input
  pinMode(ledPin, OUTPUT);    // initialize the LED pin as output
}

void loop() {
  // Turn on or off LED according to Infrared Motion Sensor
  digitalWrite(ledPin, digitalRead(sensorPin));
  delay(1000);              // wait for a second
}

