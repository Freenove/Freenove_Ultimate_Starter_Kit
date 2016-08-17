/*
  Sketch 6.2.2
  Receive Data through Serial Port

  modified 2016/5/13
  by http://www.freenove.com
*/

char inChar;      // define a variable to store character received from serial port
int counter = 0;  // define a variable as the data sent to Serial port

void setup() {
  Serial.begin(9600);                 // initialize serial port and set baud rate to 9600
  Serial.println("UNO is ready!");    // print the string "UNO is ready!"
}

void loop() {
  // Print value of variable counter to serial
  Serial.print("counter:");   // print the string "counter:"
  Serial.println(counter);    // print the value of variable "counter"
  delay(1000);                // wait 1000ms to avoid cycling too fast
  counter++;                  // variable "counter" increases 1
}

void serialEvent() {
  if (Serial.available()) {         // judge whether the data has been received
    inChar = Serial.read();         // read one character
    Serial.print("UNO received:");  // print the string "UNO received:"
    Serial.println(inChar);         // print the received character
  }
}

