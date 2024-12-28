##############################################################################
Chapter ADC
##############################################################################

Earlier, we have learned the digital ports of control board, and tried the output and input signals. Now, let us learn how to use analog ports.

Project ADC
***************************************************************

ADC is used to convert analog signals into digital signals. Control chip on the control board has integrated this function. Now let us try to use this function to convert analog signals into digital signals.

Component List
===============================================================

+-----------------------------------+---------------------------------------+
| Control board x1                  |  Breadboard x1                        |
|                                   |                                       |
|  |Chapter01_00_1|                 |   |Chapter01_01|                      |
+-----------------------------------+---------------------------------------+
| USB cable x1                      | Rotary potentiometer x1               |
|                                   |                                       |
|  |Chapter01_02|                   |  |Chapter07_00|                       |
+-----------------------------------+                                       |
| Jumper M/M x3                     |                                       |
|                                   |                                       |
|  |Chapter01_06|                   |                                       |
+-----------------------------------+---------------------------------------+

.. |Chapter01_00_1| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED_Blink/Chapter01_01.png
    :width: 95%
.. |Chapter01_04| image:: ../_static/imgs/1_LED_Blink/Chapter01_04.png
.. |Chapter01_06| image:: ../_static/imgs/1_LED_Blink/Chapter01_06.png
.. |Chapter07_00| image:: ../_static/imgs/7_ADC/Chapter07_00.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png

Circuit Knowledge
===============================================================

ADC
---------------------------------------------------------------

An ADC is an electronic integrated circuit used to convert analog signals such as voltages to digital or binary form consisting of 1s and 0s. The range of our ADC module is 10 bits, that means the resolution is 2^10=1024, so that its range (at 5V) will be divided equally into 1024 parts. 

Any analog value can be mapped to one digital value using the resolution of the converter. So the more bits the ADC has, the denser the partition of analog will be and the greater the precision of the resulting conversion.

.. image:: ../_static/imgs/7_ADC/Chapter07_01.png
    :align: center

Subsection 1: the analog in rang of 0V-5/1024V corresponds to digital 0;

Subsection 2: the analog in rang of 5 /1024V-2*5/1024V corresponds to digital 1;

The following analog signal will be divided accordingly.

Component Knowledge
===============================================================

Potentiometer
---------------------------------------------------------------

Potentiometer is a resistive element with three Terminal parts. Unlike the resistors that we have used thus far in our project which have a fixed resistance value, the resistance value of a potentiometer can be adjusted. A potentiometer is often made up by a resistive substance (a wire or carbon element) and movable contact brush. When the brush moves along the resistor element, there will be a change in the resistance of the potentiometer’s output side (3) (or change in the voltage of the circuit that is a part). The illustration below represents a linear sliding potentiometer and its electronic symbol on the right.

.. image:: ../_static/imgs/7_ADC/Chapter07_02.png
    :align: center

Between potentiometer pin 1 and pin 2 is the resistive element (a resistance wire or carbon) and pin 3 is connected to the brush that makes contact with the resistive element. In our illustration, when the brush moves from pin 1 to pin 2, the resistance value between pin 1 and pin 3 will increase linearly (until it reaches the highest value of the resistive element) and at the same time the resistance between pin 2 and pin 3 will decrease linearly and conversely down to zero. At the midpoint of the slider the measured resistance values between pin 1 and 3 and between pin 2 and 3 will be the same.

In a circuit, both sides of resistive element are often connected to the positive and negative electrodes of power. When you slide the brush “pin 3”, you can get variable voltage within the range of the power supply.

.. image:: ../_static/imgs/7_ADC/Chapter07_03.png
    :align: center

Rotary potentiometer
---------------------------------------------------------------

Rotary potentiometer and linear potentiometer have the same function; the only difference being the physical action being a rotational rather than a sliding movement.

.. image:: ../_static/imgs/7_ADC/Chapter07_04.png
    :align: center

Circuit
===============================================================

Use pin A0 on the control board to detect the voltage of rotary potentiometer.

.. list-table:: 
    :width: 100%
    :align: center

    *   -   Schematic diagram
        -   Hardware connection

    *   -   |Chapter07_05|
        -   |Chapter07_07|

.. |Chapter07_05| image:: ../_static/imgs/7_ADC/Chapter07_05.png
.. |Chapter07_07| image:: ../_static/imgs/7_ADC/Chapter07_07.png

Sketch
===============================================================

Sketch 7.1.1
---------------------------------------------------------------

Now, write code to detect the voltage of rotary potentiometer, and send the data to Serial Monitor window of Arduino IDE through serial port.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_7.1.1_ADC/Sketch_7.1.1_ADC.ino
    :linenos: 
    :language: c

From the code, we get the ADC value of pin A0, then convert it into voltage and sent to the serial port.

Verify and upload the code, open the Serial Monitor, and then you will see the original ADC value and converted voltage sent from control board.

Turn the rotary potentiometer shaft, and you can see the voltage change.

.. image:: ../_static/imgs/7_ADC/Chapter07_06.png
    :align: center

Project Control LED by Potentiometer
***************************************************************

In the previous section, we have finished reading ADC value and converting it into voltage. Now, we will try to use potentiometer to control the brightness of LED.

Component List
===============================================================

+-----------------------------------+-------------------------------------------------------------+
| Control board x1                  |  Breadboard x1                                              |
|                                   |                                                             |
|  |Chapter01_00|                   |   |Chapter01_01_1|                                          |
+-----------------------------------+------------------------+-------------------+----------------+
| USB cable x1                      |Rotary potentiometer x1 | LED x1            |Resistor 220Ω x1|
|                                   |                        |                   |                |
|  |Chapter01_02|                   |  |Chapter07_00|        |  |Chapter01_03|   | |Chapter01_04| |
+-----------------------------------+                        |                   |                |
| Jumper M/M x2                     |                        |                   |                |
|                                   |                        |                   |                |
|  |Chapter01_06|                   |                        |                   |                |
+-----------------------------------+------------------------+-------------------+----------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_01_1| image:: ../_static/imgs/1_LED_Blink/Chapter01_01.png
    :width: 60%
.. |Chapter01_05| image:: ../_static/imgs/1_LED_Blink/Chapter01_05.png
.. |Chapter01_03| image:: ../_static/imgs/1_LED_Blink/Chapter01_03.png

Sketch
===============================================================

Sketch 7.2.1
---------------------------------------------------------------

Now, write the code to detect the voltage of rotary potentiometer, and control LED to emit light with different brightness according to that.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_7.2.1_Control_LED_by_Potentiometer/Sketch_7.2.1_Control_LED_by_Potentiometer.ino
    :linenos: 
    :language: c

In the code, we get the ADC value of pin A0 and map it to PWM duty cycle of LED pin port. According to different LED brightness, we can see the changes of voltage easily.

Verify and upload the code, turn the rotary potentiometer shaft, you will see the LED brightness change.

.. image:: ../_static/imgs/7_ADC/Chapter07_08.png
    :align: center

Project Control LED by Potentiometer
***************************************************************

In the previous section, we have finished reading ADC value and converted it into LED brightness. There are many components, especially the sensor whose output is analog. Now, we will try to use photoresistor to measure the brightness of light.

Component List
===============================================================

+-------------------+---------------------------------------------------------------------------+
| Control board x1  |  Breadboard x1                                                            |
|                   |                                                                           |
|  |Chapter01_00|   |   |Chapter01_01_2|                                                        |
+-------------------+--------------------+-----------------+------------------+-----------------+
| USB cable x1      |Photoresistor x1    | LED x1          | Resistor         | Resistor        |
|                   |                    |                 |                  |                 |
|  |Chapter01_02|   |  |Chapter07_09|    |  |Chapter01_03| | 10kΩ x1          |  220Ω x1        |
+-------------------+                    |                 |                  |                 |
| Jumper M/M x2     |                    |                 |  |Chapter05_00|  | |Chapter01_04|  |
|                   |                    |                 |                  |                 |
|  |Chapter01_06|   |                    |                 |                  |                 |
+-------------------+--------------------+-----------------+------------------+-----------------+

.. |Chapter05_00| image:: ../_static/imgs/5_Control_LED/Chapter05_00.png
.. |Chapter07_09| image:: ../_static/imgs/7_ADC/Chapter07_09.png
.. |Chapter01_01_2| image:: ../_static/imgs/1_LED_Blink/Chapter01_01.png
    :width: 50%

Component Knowledge
===============================================================

Photoresistor
---------------------------------------------------------------

A Photoresistor is simply a light sensitive resistor. It is an active component that decreases resistance with respect to receiving luminosity (light) on the component's light sensitive surface. A Photoresistor’s resistance value will change in proportion to the ambient light detected. With this characteristic, we can use a Photoresistor to detect light intensity. The Photoresistor and its electronic symbol are as follows.

.. image:: ../_static/imgs/7_ADC/Chapter07_10.png
    :align: center

The circuit below is often used to detect the change of photoresistor's resistance value:

.. image:: ../_static/imgs/7_ADC/Chapter07_11.png
    :align: center

In the above circuit, when a photoresistor's resistance value changes due to a change in light intensity, the voltage between the photoresistor and resistor R1 will also change, so the intensity of the light can be obtained by measuring the voltage.

Circuit
===============================================================

Use pin A0 on control board to detect the voltage of photoresistor, and use pin 9 to control one LED.

Sketch
===============================================================

Sketch 7.3.1
---------------------------------------------------------------

Now, write code to detect the voltage of rotary potentiometer, and control LED to emit light with different brightness according to that.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_7.3.1_Control_LED_through_Photoresistor/Sketch_7.3.1_Control_LED_through_Photoresistor.ino
    :linenos: 
    :language: c

In the code, we get the ADC value of pin A0, map it to PWM duty cycle of LED pin port. According to the brightness of LED, we can see the changes of voltage easily.

Verify and upload the code, cover photoresistor with your hand, then you can see the LED brightness change.

.. image:: ../_static/imgs/7_ADC/Chapter07_12.png
    :align: center