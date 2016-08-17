/*
  Sketch 11.1.1
  Servo Sweep

  modified 2016/5/13
  by http://www.freenove.com
*/

#include <Servo.h>

Servo myservo;              // create servo object to control a servo

int pos = 0;                // variable to store the servo position
int servoPin = 3;           // define the pin of servo signal line

void setup() {
  myservo.attach(servoPin); // attaches the servo on servoPin to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable "pos"
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable "pos"
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

