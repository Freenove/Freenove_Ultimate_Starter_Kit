/* //<>//
 ******************************************************************************
 * Sketch  Dual Channel Voltmeter
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
  size(500, 250);
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

  int[] analogs = new int[2];
  analogs = serialDevice.requestAnalogs(2);
  if (analogs != null)
  {
    int vol1 = analogs[0] * 500 / 1023;
    int vol2 = analogs[1] * 500 / 1023;
    String sVol1 = vol1 / 100 + "." + vol1 / 10 % 10 + vol1 % 10;
    String sVol2 = vol2 / 100 + "." + vol2 / 10 % 10 + vol2 % 10;
    background(102);
    textSize(16);
    text("Press Enter to visit www.freenove.com", width / 2, height - 20);
    textSize(100);
    text("A0: " + sVol1 + "V", width / 2, 45);
    text("A1: " + sVol2 + "V", width / 2, 155);
  }
}

void keyPressed() 
{
  if (key == '\n' || key == '\r')
  {
    link("http://www.freenove.com");
  }
}

