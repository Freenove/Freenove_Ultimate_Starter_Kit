/* //<>//
 ******************************************************************************
 * Sketch  Voltmeter
 * Author  Ethan Pan @ Freenove (http://www.freenove.com)
 * Date    2016/8/14
 ******************************************************************************
 * Brief
 *   This sketch is used to make a voltmeter through communicate to an Arduino 
 *   board or other micro controller.
 *   It will automatically detect and connect to a device (serial port) which 
 *   use the same trans format.
 ******************************************************************************
 * Copyright
 *   Copyright © Freenove (http://www.freenove.com)
 * License
 *   Creative Commons Attribution ShareAlike 3.0 
 *   (http://creativecommons.org/licenses/by-sa/3.0/legalcode)
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
SerialDevice serialDevice = new SerialDevice(this);

void setup()
{
  size(320, 180);
  background(102);
  textAlign(CENTER, CENTER);
  textSize(64);
  text("Starting...", width / 2, (height - 40) / 2);
  textSize(16);
  text("www.freenove.com", width / 2, height - 20);
  frameRate(1000 / 40);
}

void draw()
{
  if (!serialDevice.active())
  {
    if (!serialDevice.start())
    {
      delay(1000);
      return;
    }
  }

  int analog = serialDevice.requestAnalog();
  if (analog != -1)
  {
    String sAnalog = "" + analog / 1000 + analog / 100 % 10 + analog / 10 % 10 + analog % 10;
    background(102);
    textSize(16);
    text("Press Enter to visit www.freenove.com", width / 2, height - 20);
    textSize(32);
    text("Analog value: " + sAnalog, width / 2, 20);
    int vol = analog * 500 / 1023;
    String sVol = vol / 100 + "." + vol / 10 % 10 + vol % 10;
    textSize(100);
    text(sVol + "V", width / 2, 90);
  }
}

void keyPressed() 
{
  if (key == '\n' || key == '\r')
  {
    link("http://www.freenove.com");
  }
}

