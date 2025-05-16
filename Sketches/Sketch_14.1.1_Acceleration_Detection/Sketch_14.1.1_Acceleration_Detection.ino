/*
  Sketch 14.1.1
  Acceleration Detection

  modified 2016/5/13
  by http://www.freenove.com
*/

// Reference the library to be be used by MPU6050
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

MPU6050 accelgyro;          // Construct a MPU6050 object using the default address
int16_t ax, ay, az;         // define acceleration values of 3 axes
int16_t gx, gy, gz;         // Define variables to save the values in 3 axes of gyroscope
#define LED_PIN 13          // the number of the LED pin
bool blinkState = false;    // Define a variable to save the state of LED

void setup() {
  Serial.begin(9600);       // initialize the serial port, and baud rate is set to 9600
  Serial.println("Initializing I2C devices...");
  Wire.begin();             // initialize I2C
  accelgyro.initialize();   // initialize MPU6050
  Serial.println("Testing device connections...");
  // when you need to calibrate the gravity acceleration, you can set the offset here and eliminate the note
  // accelgyro.setXAccelOffset(-1200);
  // accelgyro.setYAccelOffset(-2500);
  // accelgyro.setZAccelOffset(1988);
  Serial.print("X.Y.Z offset :\t");
  Serial.print(accelgyro.getXAccelOffset()); Serial.print("\t");
  Serial.print(accelgyro.getYAccelOffset()); Serial.print("\t");
  Serial.print(accelgyro.getZAccelOffset()); Serial.print("\n");
  // initialize LED port
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // read raw accel/gyro measurements from device
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  // display tab-separated accel/gyro x/y/z values
  Serial.print("a/g:\t");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");
  Serial.print(gx); Serial.print("\t\t");
  Serial.print(gy); Serial.print("\t\t");
  Serial.println(gz);
  // converted acceleration unit to g and the gyroscope unit to dps (degree per second) according to the sensitivity
  Serial.print("a/g:\t");
  Serial.print((float)ax / 16384); Serial.print("g\t");
  Serial.print((float)ay / 16384); Serial.print("g\t");
  Serial.print((float)az / 16384); Serial.print("g\t");
  Serial.print((float)gx / 131); Serial.print("d/s  \t");
  Serial.print((float)gy / 131); Serial.print("d/s  \t");
  Serial.print((float)gz / 131); Serial.print("d/s  \n");
  delay(300);
  // blink LED to indicate activity
  blinkState = !blinkState;
  digitalWrite(LED_PIN, blinkState);
}

