/*
  Sketch 13.1.1
  Joystick

  modified 2016/5/13
  by http://www.freenove.com
*/

int xAxisPin = 0;           // define X pin of Joystick
int yAxisPin = 1;           // define Y pin of Joystick
int zAxisPin = 8;           // define Z pin of Joystick
int xVal, yVal, zVal;       // define 3 variables to store the values of 3 direction

void setup() {
  pinMode(zAxisPin, INPUT_PULLUP);    // initialize the port to pull-up input
  Serial.begin(9600);         // initialize the serial port with baud rate 9600
  Serial.println("UNO is ready!");    // print the string "UNO is ready!"
}

void loop() {
  // read analog value in XY axis
  xVal = analogRead(xAxisPin);
  yVal = analogRead(yAxisPin);
  // read digital value of switch in Z axis
  zVal = digitalRead(zAxisPin);
  //print the data read above
  Serial.print("X : ");
  Serial.print(xVal);
  Serial.print("   \t Y : ");
  Serial.print(yVal);
  Serial.print("   \t Z : ");
  Serial.println(zVal);
  delay(200);
}

