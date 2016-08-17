/*
  Sketch 19.2.1
  Combination Lock

  modified 2016/8/17
  by http://www.freenove.com
*/

#include <Keypad.h>
#include <Servo.h>

// define the symbols on the buttons of the keypad
char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[4] = {11, 10, 9, 8}; // connect to the row pinouts of the keypad
byte colPins[4] = {7, 6, 5, 4};   // connect to the column pinouts of the keypad

// initialize an instance of class NewKeypad
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

Servo myservo;     // Create servo object to control a servo
int servoPin = 12;  // Define the servo pin
int buzzerPin = 13; // Define the buzzer pin

char passWord[] = {'1', '2', '3', '4'}; // Save the correct password

void setup() {
  myservo.attach(servoPin);   // Attaches the servo on servoPin to the servo object
  myservo.write(45);          // Let the steering gear move to the start position
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  static char keyIn[4];     // Save the input character
  static byte keyInNum = 0; // Save the the number of input characters
  char keyPressed = myKeypad.getKey();  // Get the character input
  // Handle the input characters
  if (keyPressed) {
    // Make a prompt tone each time press the key
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    // Save the input characters
    keyIn[keyInNum++] = keyPressed;
    // Judge the correctness after input
    if (keyInNum == 4) {
      bool isRight = true;            // Save password is correct or not
      for (int i = 0; i < 4; i++) {   // Judge each character of the password is correct or not
        if (keyIn[i] != passWord[i])
          isRight = false;            // Mark wrong passageword if there is any wrong character.
      }
      if (isRight) {                  // If the input password is right
        myservo.write(135);           // Open the switch
        delay(2000);                  // Delay a period of time
        myservo.write(45);            // Close the switch
      }
      else {                          // If the input password is wrong
        digitalWrite(buzzerPin, HIGH);// Make a wrong password prompt tone
        delay(500);
        digitalWrite(buzzerPin, LOW);
      }
      keyInNum = 0; // Reset the number of the input characters to 0
    }
  }
}

