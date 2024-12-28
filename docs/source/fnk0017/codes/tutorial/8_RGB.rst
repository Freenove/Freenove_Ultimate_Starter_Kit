##############################################################################
Chapter RGB LED
##############################################################################

Earlier, we have learned to apply the analog port and ADC of the control board. Now, we'll use ADC to control RGB LED.

Project Control RGB LED through Potentiometer
***************************************************************

RGB LED has three different-color LEDs inside, and we will use 3 potentiometers to control these 3 LEDs to emit light with different brightness, and observe what will happen.

Component List
===============================================================

+-----------------------------------+-------------------------------------------------------------+
| Control board x1                  |  Breadboard x1                                              |
|                                   |                                                             |
|  |Chapter01_00|                   |   |Chapter01_01|                                            |
+-----------------------------------+------------------------+-------------------+----------------+
| USB cable x1                      |Rotary                  | RGB LED x1        |Resistor        |
|                                   |                        |                   |                |
|  |Chapter01_02|                   |potentiometer x3        |  |Chapter08_00|   |220Ω x3         |
+-----------------------------------+                        |                   |                |
| Jumper M/M x2                     | |Chapter07_00|         |                   | |Chapter01_04| |
|                                   |                        |                   |                |
|  |Chapter01_06|                   |                        |                   |                |
+-----------------------------------+------------------------+-------------------+----------------+

.. |Chapter08_00| image:: ../_static/imgs/8_RGB/Chapter08_00.png
.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED_Blink/Chapter01_01.png
    :width: 63%
.. |Chapter01_04| image:: ../_static/imgs/1_LED_Blink/Chapter01_04.png
.. |Chapter01_06| image:: ../_static/imgs/1_LED_Blink/Chapter01_06.png
.. |Chapter07_00| image:: ../_static/imgs/7_ADC/Chapter07_00.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png

Component Knowledge
===============================================================

RGB LED
---------------------------------------------------------------

A RGB LED has 3 LEDs integrated into one LED component. It can respectively emit Red, Green and Blue light. In order to do this, it requires 4 pins (this is also how you identify it). The long pin (1) is the common which is the Cathode (+) or positive lead, the other 3 are the Anodes (-) or negative leads. A rendering of a RGB LED and its electronic symbol are shown below. We can make RGB LED emit various colors of light and brightness by controlling the 3 Anodes (2, 3 & 4) of the RGB LED

.. image:: ../_static/imgs/8_RGB/Chapter08_01.png
    :align: center

Red, Green, and Blue light are called 3 Primary Colors when discussing light (Note: for pigments such as paints, the 3 Primary Colors are Red, Blue and Yellow). When you combine these three Primary Colors of light with varied brightness, they can produce almost any color of visible light. Computer screens, single pixels of cell phone screens, neon lamps, etc. can all produce millions of colors due to phenomenon.

.. image:: ../_static/imgs/8_RGB/Chapter08_02.png
    :align: center

We know from the previous section that, control board controls LED to emit a total of 256(0-255) different brightness via PWM. So, through different combinations of RGB light brightness, we can create 256^3=16777216(16Million) colors.

Circuit
===============================================================

Use pin A0, A1, A2 ports of the control board to detect the voltage of rotary potentiometer, and control RGB LED by pin 9, 10, 11.

.. list-table:: 
    :width: 100%
    :align: center

    *   -   Schematic diagram
    *   -   |Chapter08_03|

    *   -   Hardware connection
    *   -   |Chapter08_04|

.. |Chapter08_03| image:: ../_static/imgs/8_RGB/Chapter08_03.png
.. |Chapter08_04| image:: ../_static/imgs/8_RGB/Chapter08_04.png

Sketch
===============================================================

Sketch 8.1.1
---------------------------------------------------------------

Now, write code to detect the voltages of these three rotary potentiometers, and convert them into PWM duty cycle to control 3 LEDs inside the RGB LED.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_8.1.1_Control_RGB_LED_through_Potentiometer/Sketch_8.1.1_Control_RGB_LED_through_Potentiometer.ino
    :linenos: 
    :language: c

In the code, we get the voltages of three rotary potentiometers, and convert them into PWM duty cycle to control the three LEDs of the RGB LED to emit light with different brightness.

Verify and upload the code, rotate the three rotary potentiometer shaft, and you can see the LED light change in its color and brightness.

Project Multicolored LED
***************************************************************

In the previous section, we have finished controlling the RGB LED to emit light with different color and brightness through three potentiometers. Now, we will try to make RGB LED emit multicolored lights automatically.

Component List
===============================================================

+-----------------------------------+---------------------------------------+
| Control board x1                  |  Breadboard x1                        |
|                                   |                                       |
|  |Chapter01_00|                   |   |Chapter01_01_1|                    |
+-----------------------------------+-------------------+-------------------+
| USB cable x1                      | RGB LED x1        | Resistor 220Ω x10 |
|                                   |                   |                   |
|  |Chapter01_02|                   |  |Chapter08_00|   |  |Chapter01_04|   |
+-----------------------------------+                   |                   |
| Jumper M/M x11                    |                   |                   |
|                                   |                   |                   |
|  |Chapter01_06|                   |                   |                   |
+-----------------------------------+-------------------+-------------------+

.. |Chapter01_01_1| image:: ../_static/imgs/1_LED_Blink/Chapter01_01.png
    :width: 85%

Circuit
===============================================================

Use pin 9, 10, 11 of the control board to control RGB LED.

.. list-table:: 
    :width: 100%
    :align: center

    *   -   Schematic diagram
    *   -   |Chapter08_05|

    *   -   Hardware connection
    *   -   |Chapter08_06|

.. |Chapter08_05| image:: ../_static/imgs/8_RGB/Chapter08_05.png
.. |Chapter08_06| image:: ../_static/imgs/8_RGB/Chapter08_06.png

Sketch
===============================================================

Sketch 8.2.1
---------------------------------------------------------------

Now, write code to generate three random numbers, and convert them into PWM duty cycle to control the three LEDs of RGB LED.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_8.2.1_Colorful_LED/Sketch_8.2.1_Colorful_LED.ino
    :linenos: 
    :language: c

In the code, we create three random numbers, and convert them into PWM duty cycle to control the three LEDs of RGB LED to emit light with different brightness. At regular intervals, a new random number will be created, so RGB LED will start flashing light with different colors and brightness.

.. py:function:: random(min, max)

    random (min, max) function is used to generate random number, and it will return a random value in the range (min, Max-1).
    
    You can also use random (max) function, the function set the minimum value into 0 by default, and returns a random value in the range (0, Max-1).

Verify and upload the code, and RGB LED starts flashing with different colors and brightness.

