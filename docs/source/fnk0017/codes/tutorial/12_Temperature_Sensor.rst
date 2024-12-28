##############################################################################
Chapter Temperature Sensor
##############################################################################

Earlier, we have used control board and photoresistor to detect the intensity of light. Now, we will learn to use the temperature sensor.

Project Detect the Temperature
***************************************************************

We will use a thermistor to detect the ambient temperature.

Component List
===============================================================

+------------------------------------+---------------------------------+
| Control board x1                   |Breadboard x1                    |
|                                    |                                 |
|  |Chapter01_00|                    |  |Chapter01_01|                 |
+------------------------------------+---------------------------------+
| USB cable x1                       | Jumper M/M x6                   |
|                                    |                                 |
|  |Chapter01_02|                    |  |Chapter01_06|                 |
+------------------------------------+---------------------------------+
| Thermistor x1                      | Resistor 10kΩ x1                |
|                                    |                                 |
|  |Chapter12_00|                    |  |Chapter05_00|                 |
+------------------------------------+---------------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED_Blink/Chapter01_01.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png
.. |Chapter01_06| image:: ../_static/imgs/1_LED_Blink/Chapter01_06.png
.. |Chapter12_00| image:: ../_static/imgs/12_Temperature_Sensor/Chapter12_00.png
.. |Chapter05_00| image:: ../_static/imgs/5_Control_LED/Chapter05_00.png

Component Knowledge
===============================================================

Thermistor
---------------------------------------------------------------

Thermistor is a temperature sensitive resistor. When it senses a change in temperature, the resistance of the Thermistor will change. We can take advantage of this characteristic by using a Thermistor to detect temperature intensity. A Thermistor and its electronic symbol are shown below.

.. image:: ../_static/imgs/12_Temperature_Sensor/Chapter12_01.png
    :align: center

The relationship between resistance value and temperature of thermistor is:
    
    Rt=R*EXP[B*(1/T2-1/T1)]

Where:

    Rt is the thermistor resistance under T2 temperature;
    
    R is in the nominal resistance of thermistor under T1 temperature;
    
    EXP[n] is nth power of e;
    
    B is for thermal index;
    
    T1, T2 is Kelvin temperature (absolute temperature). Kelvin temperature=273.15+celsius temperature.

Parameters of the thermistor we use is: B=3950, R=10k, T1=25.

The circuit connection method of the thermistor is similar to photoresistor, as the following:

.. image:: ../_static/imgs/12_Temperature_Sensor/Chapter12_02.png
    :align: center

We can use the value measured by the analog pin of control board to obtain resistance value of the thermistor, and then we can use the formula to obtain the temperature value.

Circuit
===============================================================

Use pin A0 on the control board to detect the voltage of thermistor.

.. list-table:: 
    :width: 100%
    :align: center

    *   -   Schematic diagram
        -   Hardware connection

    *   -   |Chapter12_03|
        -   |Chapter12_04|

.. |Chapter12_03| image:: ../_static/imgs/12_Temperature_Sensor/Chapter12_03.png
.. |Chapter12_04| image:: ../_static/imgs/12_Temperature_Sensor/Chapter12_04.png

Sketch
===============================================================

Sketch 12.1.1
---------------------------------------------------------------

Now, write the code to detect the voltage value of thermistor, calculate the temperature value, and send it to Serial Monitor.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_12.1.1_Detect_the_temperature/Sketch_12.1.1_Detect_the_temperature.ino
    :linenos: 
    :language: c

In the code, we obtain the ADC value of pin A0, and convert it into temperature value, and then send it to the serial port.

Verify and upload the code, open the Serial Monitor, and then you will see the temperature value sent from control board.

.. image:: ../_static/imgs/12_Temperature_Sensor/Chapter12_05.png
    :align: center
