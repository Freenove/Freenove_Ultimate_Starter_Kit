##############################################################################
Chapter Vibration Switch
##############################################################################

Vibration switch is a component that can detect vibration. We will use this sensor later.

Project Detect Vibration
***************************************************************

Now let us try to use vibration switch to detect vibration.

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
| Jumper M/M x4                      | Vibration switch x1             |
|                                    |                                 |
| Jumper F/M x2                      |                                 |
|                                    |                                 |
|  |Chapter01_06|                    |  |Chapter20_00|                 |
+------------------------------------+---------------------------------+

.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png
.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED_Blink/Chapter01_01.png
.. |Chapter09_00| image:: ../_static/imgs/9_Buzzer/Chapter09_00.png
.. |Chapter09_01| image:: ../_static/imgs/9_Buzzer/Chapter09_01.png
.. |Chapter20_00| image:: ../_static/imgs/20_Vibration_Switch/Chapter20_00.png
.. |Chapter09_02| image:: ../_static/imgs/9_Buzzer/Chapter09_02.png
.. |Chapter01_06| image:: ../_static/imgs/1_LED_Blink/Chapter01_06.png

Component Knowledge

Vibration Switch

Vibration switches is a kind of sensor that can detect vibration. When the vibration amplitude is greater than the critical value, two pins of the vibration switch will be switched on.

.. image:: ../_static/imgs/20_Vibration_Switch/Chapter20_01.png
    :align: center

The internal circuit of the Vibration switch is as below, one of the pins is connected with a metal bar and the other is connected with spring. The spring will swing when a vibration occurs. When the vibration is strong enough, the spring will contact with the metal bar to make the two pins connected with each other.

.. image:: ../_static/imgs/20_Vibration_Switch/Chapter20_02.png
    :align: center

Circuit Knowledge
===============================================================

Digital pins with interrupts

Some of the control board digital pins can be configured to interrupt mode, which can trigger interrupt event and execute interrupt function.

Pin 2 and 3 of the control board can be configured to interrupt mode. Conditions that trigger interrupt can be configured to:

.. list-table:: 
    :width: 80%
    :widths: 1 1
    :align: center

    *   -   Condition
        -   Function
  
    *   -   LOW
        -   to trigger the interrupt whenever the pin is low 

    *   -   CHANGE
        -   to trigger the interrupt whenever the pin changes value

    *   -   RISING
        -   to trigger when the pin goes from low to high

    *   -   FALLING
        -   to trigger for when the pin goes from high to low

Interrupts are useful for making things happen automatically in microcontroller programs, and they can help solve timing problems. Ideal tasks for using an interrupt may include reading a rotary encoder, or monitoring user input.

Circuit
===============================================================

Use pin 3 on the control board to connect vibration switch, and pin 13 to drive buzzer.

.. list-table:: 
    :width: 100%
    :align: center

    *   -   Schematic diagram
    *   -   |Chapter20_03|
    *   -   Hardware connection
    *   -   |Chapter20_04|

.. |Chapter20_03| image:: ../_static/imgs/20_Vibration_Switch/Chapter20_03.png
.. |Chapter20_04| image:: ../_static/imgs/20_Vibration_Switch/Chapter20_04.png

Sketch
===============================================================

Sketch 20.1.1
---------------------------------------------------------------

Now write code to detect whether the vibration switch is conducted and whether it makes a buzzer sound when conducted.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_20.1.1_Detect_Vibration/Sketch_20.1.1_Detect_Vibration.ino
    :linenos: 
    :language: c

This code configures the pin that is connected to vibration switch to be triggered by falling edge, that is, FALLING mode.

.. code-block:: c

    attachInterrupt(digitalPinToInterrupt(switchPin), vibrate, FALLING);

.. py:function:: attachInterrupt(interrupt, ISR, mode);

    This function is used to configure the digital pin's interrupt mode. Each parameter of the function is as follows:
    
    interrupt: the number of the interrupt (int). Normally you should use digitalPinToInterrupt(pin) to translate the actual digital pin to the specific interrupt number.
    
    ISR: the ISR to be called when an interrupt occurs; this function must take no parameters and return nothing. This function is sometimes referred to as an interrupt service routine.

And we configure the pins that connected with vibration switch into pull up input mode. This way can ensure a high level of vibration switch when not connected, and low level when connected. So it can cause interrupt.

.. code-block:: c

    pinMode(switchPin, INPUT_PULLUP); // Set the vibration switch pin to pull up input mode

The following is the interrupt function, and it will be executed when the interrupt is triggered.

.. code-block:: c

    void vibrate() {
        isVibrate = true; // Marked as the trigger
    }

Interrupt function should keep short, so we use a variable "isVibrate" to record whether the interrupt is triggered, and dispose it in the loop() function. And the buzzer will be connected if the interrupt is triggered.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_20.1.1_Detect_Vibration/Sketch_20.1.1_Detect_Vibration.ino
    :linenos: 
    :language: c
    :lines: 22-28

Verify and upload the code and tap on the vibration switch, and then the buzzer will make a sound.