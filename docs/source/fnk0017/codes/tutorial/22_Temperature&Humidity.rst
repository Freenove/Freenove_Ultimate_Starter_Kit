##############################################################################
Chapter Temperature & Humidity Sensor
##############################################################################

In this chapter, we will learn how to use a sensor that can detect temperature and humidity.

Project Temperature & Humidity Sensor
***************************************************************

Now, let's try to get the temperature and humidity value of the current environment.

Component List
===============================================================

+-----------------------------------+---------------------------------------+
| Control board x1                  |  Breadboard x1                        |
|                                   |                                       |
|  |Chapter01_00|                   |   |Chapter01_01|                      |
+-----------------------------------+-------------------+-------------------+
| USB cable x1                      | Resistor 10kΩ x1  | DHT11 x1          |
|                                   |                   |                   |
|  |Chapter01_02|                   |  |Chapter05_00|   |  |Chapter22_00|   |
+-----------------------------------+                   |                   |
| Jumper M/M x3                     |                   |                   |
|                                   |                   |                   |
|  |Chapter01_06|                   |                   |                   |
+-----------------------------------+-------------------+-------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED_Blink/Chapter01_01.png
    :width: 85%
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png
.. |Chapter05_00| image:: ../_static/imgs/5_Control_LED/Chapter05_00.png
.. |Chapter22_00| image:: ../_static/imgs/22_Temperature&Humidity/Chapter22_00.png
.. |Chapter01_06| image:: ../_static/imgs/1_LED_Blink/Chapter01_06.png

Component Knowledge
===============================================================

DHT11
---------------------------------------------------------------

The Temperature & Humidity Sensor DHT11 is a compound temperature & humidity sensor, and the output digital signal has been calibrated by its manufacturer.

.. image:: ../_static/imgs/22_Temperature&Humidity/Chapter22_01.png
    :align: center

DHT11 uses customized single-line communication protocol, so we can use the library to read data more conveniently.

Circuit
===============================================================

Use pin 10 on control board to connect DHT11.

.. list-table:: 
    :width: 100%
    :align: center

    *   -   Schematic diagram
    *   -   |Chapter22_02|
    *   -   Hardware connection
    *   -   |Chapter22_03|

.. |Chapter22_02| image:: ../_static/imgs/22_Temperature&Humidity/Chapter22_02.png
.. |Chapter22_03| image:: ../_static/imgs/22_Temperature&Humidity/Chapter22_03.png

Sketch
===============================================================

Sketch 22.1.1
---------------------------------------------------------------

Before writing code, we need to import the library needed.

Click “Add .ZIP Library...” and then find DHT.zip in libraries folder (this folder is in the folder unzipped from the ZIP file we provided). This library can make it convenient for us to control DHT11.

Now, write code to get the temperature and humidity data measured by DHT11, and sent it to the serial port.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_22.1.1_Temperature_and_Humidity_Sensor/Sketch_22.1.1_Temperature_and_Humidity_Sensor.ino
    :linenos: 
    :language: c

In the code, we use the dht class provided by the DHT library to control DHT11. The following is a DHT object. As shown below, instantiate one dht object.

.. code-block:: c

    dht DHT;          // create dht object

Read DHT11 data and send the result to the serial port in the loop() function.

.. code-block:: c

    // read DHT11 and judge the state according to the return value
    int chk = DHT.read11(dhtPin);
    switch (chk)
    {
        case DHTLIB_OK: // When read data successfully print temperature and humidity data
        Serial.print("Humidity: ");
        Serial.print(DHT.humidity);
        Serial.print("%, Temperature: ");
        Serial.print(DHT.temperature);
        Serial.println("C");
        break;
        ...
    }


Send the failure reason when fail to read.

.. code-block:: c

    case DHTLIB_ERROR_CHECKSUM: // Checksum error
      Serial.println("Checksum error");
      break;
    case DHTLIB_ERROR_TIMEOUT:  // Time out error
      Serial.println("Time out error");
      break;
    default:                    // Unknown error
      Serial.println("Unknown error");
      break;

Verify and upload the code, open the Serial Monitor, and then you will see the temperature and humidity data being sent from control board.

.. image:: ../_static/imgs/22_Temperature&Humidity/Chapter22_04.png
    :align: center


