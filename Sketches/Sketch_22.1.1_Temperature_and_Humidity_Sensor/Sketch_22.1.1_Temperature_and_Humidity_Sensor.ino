/*
  Sketch 22.1.1
  Temperature & Humidity Sensor

  modified 2016/8/17
  by http://www.freenove.com
*/

#include <dht.h>

dht DHT;          // create dht object
int dhtPin = 10;  // the number of the DHT11 sensor pin

void setup() {
  Serial.begin(9600); // Initialize the serial port and set the baud rate to 9600
  Serial.println("UNO is ready!");  // Print the string "UNO is ready!"
}

void loop() {
  // read DHT11 and judge the state according to the return value
  int chk = DHT.read11(dhtPin);
  switch (chk)
  {
    case DHTLIB_OK: // When read data successfully, print temperature and humidity data
      Serial.print("Humidity: ");
      Serial.print(DHT.humidity);
      Serial.print("%, Temperature: ");
      Serial.print(DHT.temperature);
      Serial.println("C");
      break;
    case DHTLIB_ERROR_CHECKSUM: // Checksum error
      Serial.println("Checksum error");
      break;
    case DHTLIB_ERROR_TIMEOUT:  // Time out error
      Serial.println("Time out error");
      break;
    default:                    // Unknown error
      Serial.println("Unknown error");
      break;
  }
  delay(1000);
}

