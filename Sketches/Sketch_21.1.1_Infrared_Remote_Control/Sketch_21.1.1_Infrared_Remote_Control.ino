/*
  Sketch 21.1.1
  Infrared Remote Control

  modified 2016/8/17
  by http://www.freenove.com
*/

#include <IRremote.h>

int RECV_PIN = 12;        // Infrared receiving pin
IRrecv irrecv(RECV_PIN); // Create a class object used to receive class
decode_results results; // Create a decoding results class object

void setup()
{
  Serial.begin(9600); // Initialize the serial port and set the baud rate to 9600
  Serial.println("UNO is ready!");  // Print the string "UNO is ready!"
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {  // Waiting for decoding
    Serial.println(results.value, HEX); // Print out the decoded results
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}

