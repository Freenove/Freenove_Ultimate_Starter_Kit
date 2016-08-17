/*
  Sketch 7.1.1
  ADC

  modified 2016/5/13
  by http://www.freenove.com
*/

int adcValue;     // Define a variable to save ADC value
float voltage;    // Define a variable to save the calculated voltage value

void setup() {
  Serial.begin(9600);      // Initialize the serial port and set the baud rate to 9600
  Serial.println("UNO is ready!");    // Print the string "UNO is ready!"
}

void loop() {
  adcValue = analogRead(A0);          // Convert analog of A0 port to digital
  voltage = adcValue * (5.0 / 1023.0);// Calculate voltage according to digital
  // Send the result to computer through serial
  Serial.print("convertValue:");
  Serial.println(adcValue);
  Serial.print("Voltage:");
  Serial.println(voltage);
  delay(500);
}

