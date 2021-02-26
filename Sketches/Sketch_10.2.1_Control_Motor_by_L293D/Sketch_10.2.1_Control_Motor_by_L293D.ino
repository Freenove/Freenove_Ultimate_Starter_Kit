/*
  Sketch 10.2.1
  Control Motor by L293D

  modified 2016/5/13
  by http://www.freenove.com
*/

int in1Pin = 10;      // Define L293D channel 1 pin
int in2Pin = 9;       // Define L293D channel 2 pin
int enable1Pin = 11;  // Define L293D enable 1 pin

boolean rotationDir;  // Define a variable to save the motor's rotation direction, true and false are represented by positive rotation and reverse rotation.
int rotationSpeed;    // Define a variable to save the motor rotation speed

void setup() {
  // Initialize the pin into an output mode:
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
}

void loop() {
  int potenVal = analogRead(A0);  // Convert the voltage of rotary potentiometer into digital
  // Compare the number with value 512, if more than 512, clockwise rotates, otherwise, counter clockwise rotates
  rotationSpeed = potenVal - 512;
  if (potenVal > 512)
    rotationDir = true;
  else
    rotationDir = false;
  // Calculate the motor speed, the far number of deviation from the middle value 512, the faster the control speed will be
  rotationSpeed = abs(potenVal - 512);
  // Control the steering and speed of the motor
  driveMotor(rotationDir, map(rotationSpeed, 0, 512, 0, 255));
}

void driveMotor(boolean dir, int spd) {
  // Control motor rotation direction
  if (dir) {
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
  }
  else {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
  }
  // Control motor rotation speed
  analogWrite(enable1Pin, constrain(spd, 0, 255));
}
