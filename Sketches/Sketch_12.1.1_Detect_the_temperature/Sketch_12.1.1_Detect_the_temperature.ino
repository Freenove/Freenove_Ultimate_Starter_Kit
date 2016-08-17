/*
  Sketch 12.1.1
  Detect the temperature

  modified 2016/5/13
  by http://www.freenove.com
*/

void setup() {
  Serial.begin(9600);                 // Initialize the serial port, set the baud rate into 9600
  Serial.println("UNO is ready!");    // Print the string "UNO is ready!"
}

void loop() {
  int lmVal = analogRead(A0);         // Convert analog value of A0 port into digital value
  // Calculate the temperature value according to the converted digital value
  float temVal = (float)lmVal / 1023.0 * 5.0 / 0.01;
  // Send the result to computer through serial port
  Serial.print("Current temperature is: ");
  Serial.print(temVal);
  Serial.println(" C");
  delay(500);
}

