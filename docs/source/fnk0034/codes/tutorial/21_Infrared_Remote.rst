##############################################################################
Chapter Infrared Remote
##############################################################################

In this chapter, we'll learn how to use an infrared remote control, and control a LED.

Project Infrared Remote Control
***************************************************************

First, we need to understand how infrared remote control works, and then get the command sent from infrared remote control.

Component List
===============================================================

+-----------------------------------+--------------------------------------------------------+
| Control board x1                  |  Breadboard x1                                         |
|                                   |                                                        |
|  |Chapter01_00|                   |   |Chapter01_01|                                       |
+-----------------------------------+-------------------+-------------------+----------------+
| USB cable x1                      | Infrared          | Resistor          | Jumper M/M x4  |
|                                   |                   |                   |                |
|  |Chapter01_02|                   | receiver x1       | 10kΩ x1           | |Chapter01_06| |
+-----------------------------------+                   |                   |                |
| Infrared remote x1                |                   |                   |                |
|                                   |                   |                   |                |
| (May need CR2025 battery x1,      |                   |                   |                |
|                                   |                   |                   |                |
| , please check the holder)        |                   |                   |                |
|                                   | |Chapter21_00|    |  |Chapter05_00|   |                |
|  |Chapter21_01|                   |                   |                   |                |
+-----------------------------------+-------------------+-------------------+----------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED_Blink/Chapter01_01.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png
.. |Chapter01_06| image:: ../_static/imgs/1_LED_Blink/Chapter01_06.png
.. |Chapter05_00| image:: ../_static/imgs/5_Control_LED/Chapter05_00.png
.. |Chapter21_00| image:: ../_static/imgs/21_Infrared_Remote/Chapter21_00.png
.. |Chapter21_01| image:: ../_static/imgs/21_Infrared_Remote/Chapter21_01.png

Component Knowledge
===============================================================

Infrared remote
---------------------------------------------------------------

An Infrared(IR) remote control is a device with a certain number of buttons. Pressing down different buttons will make the infrared emission tube, which is located in the front of the remote control, send infrared with different encoding. Infrared remote control technology is widely used in household appliances, such as TV, air conditioning, etc. Thus, it makes it possible for you to switch TV programs and adjust the temperature of the air conditioning away from them. The remote control we use is shown below:

.. image:: ../_static/imgs/21_Infrared_Remote/Chapter21_02.png
    :align: center

Infrared receiver
---------------------------------------------------------------

Infrared(IR) receiver is a component which can receive the infrared light, so we can use it to detect the signal emitted by the infrared remote control. DATA pin here outputs the received infrared signal.

.. image:: ../_static/imgs/21_Infrared_Remote/Chapter21_03.png
    :align: center

Circuit
===============================================================

Use pin 12 on the control board to connect IR receiver.

.. list-table:: 
    :width: 100%
    :align: center

    *   -   Schematic diagram
    *   -   |Chapter21_04|
    *   -   Hardware connection
    *   -   |Chapter21_05|

.. |Chapter21_04| image:: ../_static/imgs/21_Infrared_Remote/Chapter21_04.png
.. |Chapter21_05| image:: ../_static/imgs/21_Infrared_Remote/Chapter21_05.png

Sketch
===============================================================

Sketch 21.1.1
---------------------------------------------------------------

Before writing code, we need to import the library needed.

Click “Add .ZIP Library...” and then find IRremote.zip in libraries folder (this folder is in the folder unzipped from the ZIP file we provided). This library makes it easy to control IR receiver.

Now, write code to get the command sent from IR remote control, and send it to the serial port.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_21.1.1_Infrared_Remote_Control/Sketch_21.1.1_Infrared_Remote_Control.ino
    :linenos: 
    :language: c

We use the IRrecv class provided by the IRremote library to control IR receiver in this code. As shown below, instantiate one IRrecv object, and the parameter represents the pin connected to the IR receiver.

.. code-block:: c

    IRrecv irrecv(RECV_PIN); // Create a class object used to receive class

decode_results class provided by the IRremote library is used to save the results of IR control decoding.

.. code-block:: c

    decode_results results;  // Create a decoding results class object

Start the signal receiving in the setup() function   

.. code-block:: c

    irrecv.enableIRIn();   // Start the receiver

In the loop() function, decode the received signal, and sent it to computer through the serial port.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_21.1.1_Infrared_Remote_Control/Sketch_21.1.1_Infrared_Remote_Control.ino
    :linenos: 
    :language: c
    :lines: 22-28

Verify and upload the code, open the Serial Monitor, and press the IR control button, and then you can see the corresponding code being printed out.

.. image:: ../_static/imgs/21_Infrared_Remote/Chapter21_06.png
    :align: center

Project Control LED through Infrared Remote
***************************************************************

Now, let us try to control a LED through infrared remote.

Component List
===============================================================

+------------------------------------+---------------------------------+
| Control board x1                   | Breadboard x1                   |
|                                    |                                 |
|  |Chapter01_00|                    |  |Chapter01_01|                 |
+------------------------------------+---------------------------------+
| USB cable x1                       | NPN transistor x1               |
|                                    |                                 |
|  |Chapter01_02|                    |  |Chapter09_00|                 |
+------------------------------------+---------------------------------+
| Resistor 1kΩ x1                    | Active buzzer x1                |
|                                    |                                 |
|  |Chapter09_02|                    |  |Chapter09_01|                 |
+------------------------------------+---------------------------------+
| Jumper M/M x10                     | Infrared remote x1              |
|                                    |                                 |
|  |Chapter01_06|                    |  |Chapter21_01|                 |
+------------------------------------+---------------------------------+
| LED x1                             | Resistor 10kΩ x1                |
|                                    |                                 |
|  |Chapter01_03|                    |  |Chapter05_00|                 |
+------------------------------------+---------------------------------+
| Resistor 220Ω x1                   | Infrared receiver x1            |
|                                    |                                 |
|  |Chapter01_04|                    |  |Chapter21_00|                 |
+------------------------------------+---------------------------------+

.. |Chapter09_00| image:: ../_static/imgs/9_Buzzer/Chapter09_00.png
.. |Chapter09_01| image:: ../_static/imgs/9_Buzzer/Chapter09_01.png
.. |Chapter20_00| image:: ../_static/imgs/20_Vibration_Switch/Chapter20_00.png
.. |Chapter09_02| image:: ../_static/imgs/9_Buzzer/Chapter09_02.png
.. |Chapter01_03| image:: ../_static/imgs/1_LED_Blink/Chapter01_03.png
.. |Chapter01_04| image:: ../_static/imgs/1_LED_Blink/Chapter01_04.png

Circuit
===============================================================

Connect pin 12 on the control board to IR receiver to simulate a desk lamp. And drive buzzer through pin 13, drive LED through pin 5. 

.. list-table:: 
    :width: 100%
    :align: center

    *   -   Schematic diagram
    *   -   |Chapter21_07|
    *   -   Hardware connection
    *   -   |Chapter21_08|

.. |Chapter21_07| image:: ../_static/imgs/21_Infrared_Remote/Chapter21_07.png
.. |Chapter21_08| image:: ../_static/imgs/21_Infrared_Remote/Chapter21_08.png

Sketch
===============================================================

Sketch 21.2.1
---------------------------------------------------------------

Now, write code to get the commands sent from IR remote, and control the LED light on/off or emit light with different brightness, and control the buzzer to generate a confirmation sound when it receives the command.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_21.2.1_Control_LED_through_Infrared_Remote/Sketch_21.2.1_Control_LED_through_Infrared_Remote.ino
    :linenos: 
    :language: c

Based on the last section, we add some new functions: control LED and buzzer.

We define a function that is used to handle the received commands. When this function is executed, make the buzzer beep first, then output PWM signals with different duty cycle to the pin connected to LED according to the receiving commands 

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_21.2.1_Control_LED_through_Infrared_Remote/Sketch_21.2.1_Control_LED_through_Infrared_Remote.ino
    :linenos: 
    :language: c
    :lines: 35-55

Each time when the command is received, the function above will be called in the loop() function.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_21.2.1_Control_LED_through_Infrared_Remote/Sketch_21.2.1_Control_LED_through_Infrared_Remote.ino
    :linenos: 
    :language: c
    :lines: 27-33

Verify and upload the code, press the button '0', '1', '2', '3' on IR remote, and then you can see LED emit light with different brightness, and the buzzer will start beeping when it receives the signal.

