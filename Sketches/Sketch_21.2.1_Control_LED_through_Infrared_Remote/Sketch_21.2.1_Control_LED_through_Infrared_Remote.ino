/*
  Sketch 21.2.1
  Control LED through Infrared Remote

  modified 2016/8/17
  by http://www.freenove.com
*/

#include <IRremote.h>

int RECV_PIN = 12;        // Infrared receiving pin
IRrecv irrecv(RECV_PIN); // Create a class object used to receive class
decode_results results; // Create a decoding results class object

int ledPin = 5;           // the number of the LED pin
int buzzerPin = 13;       // the number of the buzzer pin

void setup()
{
  Serial.begin(9600); // Initialize the serial port and set the baud rate to 9600
  Serial.println("UNO is ready!");  // Print the string "UNO is ready!"
  irrecv.enableIRIn(); // Start the receiver
  pinMode(ledPin, OUTPUT);          // set LED pin into output mode
  pinMode(buzzerPin, OUTPUT);       // set buzzer pin into output mode
}

void loop() {
  if (irrecv.decode(&results)) {  // Waiting for decoding
    Serial.println(results.value, HEX); // Print out the decoded results
    handleControl(results.value); // Handle the commands from remote control
    irrecv.resume(); // Receive the next value
  }
}

void handleControl(unsigned long value) {
  // Make a sound when it rereives commands
  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
  // Handle the commands
  switch (value) {
    case 0xFF6897:              // Receive the number '0'
      analogWrite(ledPin, 0);   // Turn off LED
      break;
    case 0xFF30CF:              // Receive the number '1'
      analogWrite(ledPin, 7);   // Dimmest brightness
      break;
    case 0xFF18E7:              // Receive the number '2'
      analogWrite(ledPin, 63);  // Medium brightness
      break;
    case 0xFF7A85:              // Receive the number '3'
      analogWrite(ledPin, 255); // Strongest brightnss
      break;
  }
}

