##############################################################################
Chapter Digital Display
##############################################################################

Digital display is a kind of device that can display one or several digits. We will learn how to use it in this chapter.

Project 1-digit 7-segment Display
***************************************************************

Frist, try to use the digit display that can display 1-digit number.

Component List
===============================================================

+-----------------------------------+-------------------------------------------------------------+
| Control board x1                  |  Breadboard x1                                              |
|                                   |                                                             |
|  |Chapter01_00|                   |   |Chapter01_01|                                            |
+-----------------------------------+------------------------+-------------------+----------------+
| USB cable x1                      | 74HC595 x1             | 1-digit 7-segment |Resistor        |
|                                   |                        |                   |                |
|  |Chapter01_02|                   |  |Chapter15_00|        |   display x1      |220Ω x8         |
+-----------------------------------+                        |                   |                |
| Jumper M/M x18                    |                        |  |Chapter17_00|   | |Chapter01_04| |
|                                   |                        |                   |                |
|  |Chapter01_06|                   |                        |                   |                |
+-----------------------------------+------------------------+-------------------+----------------+

.. |Chapter17_00| image:: ../_static/imgs/17_Digital_Display/Chapter17_00.png
.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED_Blink/Chapter01_01.png
    :width: 63%
.. |Chapter01_04| image:: ../_static/imgs/1_LED_Blink/Chapter01_04.png
.. |Chapter01_06| image:: ../_static/imgs/1_LED_Blink/Chapter01_06.png
.. |Chapter15_00| image:: ../_static/imgs/15_LED_Matrix/Chapter15_00.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png

Component Knowledge
===============================================================

1-digit 7-segment display
---------------------------------------------------------------

A 7-Segment Display is a digital electronic display device. There is a figure "8" and a decimal point represented, which consists of 8 LEDs. It can display numbers of 0~9 by lighting some of its LED segment. The LEDs have a Common Anode and individual Cathodes. Its internal structure and pin designation diagram is shown below:

.. image:: ../_static/imgs/17_Digital_Display/Chapter17_01.png
    :align: center

As we can see in the above circuit diagram, we can control the state of each LED separately. Also, by combining LEDs with different states of ON and OFF, we can display different characters (Numbers and Letters). For example, to display a “0”: we need to turn ON LED segments 7, 6, 4, 2, 1 and 9, and turn OFF LED segments 5 and 10.

.. image:: ../_static/imgs/17_Digital_Display/Chapter17_02.png
    :align: center

If we use a byte to show the state of the LEDs that connected to pin 5, 10, 9, 1, 2, 4, 6, 7, we can make 0 represent the state of ON and 1 for OFF. Then the number 0 can be expressed as a binary number 11000000, namely hex 0xc0.

The numbers and letters that can be display are shown below:

.. list-table:: 
    :width: 70%
    :align: center

    *   -   Schematic diagram
    *   -   |Chapter17_03|
    *   -   Hardware connection
    *   -   |Chapter17_04|

.. |Chapter17_03| image:: ../_static/imgs/17_Digital_Display/Chapter17_03.png
.. |Chapter17_04| image:: ../_static/imgs/17_Digital_Display/Chapter17_04.png

Sketch
===============================================================

Sketch 17.1.1
---------------------------------------------------------------

Now write code to control the 1-digit 7-segment display through 74HC595.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_17.1.1_1_Digit_7_Segment_Display/Sketch_17.1.1_1_Digit_7_Segment_Display.ino
    :linenos: 
    :language: c

We define an array to save and display the encoding of character 0-F in this code.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_17.1.1_1_Digit_7_Segment_Display/Sketch_17.1.1_1_Digit_7_Segment_Display.ino
    :linenos: 
    :language: c
    :lines: 14

Initialize the pin connected to 74HC595 in setup() function.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_17.1.1_1_Digit_7_Segment_Display/Sketch_17.1.1_1_Digit_7_Segment_Display.ino
    :linenos: 
    :language: c
    :lines: 16-21

Then in loop() function, send the encoding of 0-F to 74HC595 circularly.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_17.1.1_1_Digit_7_Segment_Display/Sketch_17.1.1_1_Digit_7_Segment_Display.ino
    :linenos: 
    :language: c
    :lines: 25-33

Verify and upload the code, then you will see the 1-digit 7-segment display show 0-F in a circular manner.

.. image:: ../_static/imgs/17_Digital_Display/Chapter17_05.png
    :align: center

Project 4-digit 7-segment Display
***************************************************************

+-----------------------------------+-------------------------------------------------------------+
| Control board x1                  |  Breadboard x1                                              |
|                                   |                                                             |
|  |Chapter01_00|                   |   |Chapter01_01|                                            |
+-----------------------------------+------------------------+-------------------+----------------+
| USB cable x1                      | 74HC595 x1             | 4-digit 7-segment |Resistor        |
|                                   |                        |                   |                |
|  |Chapter01_02|                   |  |Chapter15_00|        |   display x1      |220Ω x8         |
+-----------------------------------+                        |                   |                |
| Jumper M/M x21                    |                        |  |Chapter17_06|   | |Chapter01_04| |
|                                   |                        |                   |                |
|  |Chapter01_06|                   |                        |                   |                |
+-----------------------------------+------------------------+-------------------+----------------+

.. |Chapter17_06| image:: ../_static/imgs/17_Digital_Display/Chapter17_06.png

Component Knowledge
===============================================================

4-digit 7-segment display
---------------------------------------------------------------

A 4 Digit 7-segment display integrates four 7-Segment Displays into one module, therefore it can display more characters. All of the LEDs contained have a Common Anode and individual Cathodes. Its internal structure and pin designation diagram is shown below:

.. image:: ../_static/imgs/17_Digital_Display/Chapter17_07.png
    :align: center

The internal electronic circuit is shown below, and all eight LED cathode pins of each 1-digit 7-segment display are connected together.

.. image:: ../_static/imgs/17_Digital_Display/Chapter17_08.png
    :align: center

Display method of 4 Digit 7-segment display is similar to 1 Digit 7-segment display. The difference between them is that the 4-Digit displays each Digit is visible in turn, one by one and not together. We need to first send high level to the common end of the first Digit Display, and send low level to the remaining three common ends, and then send content to 8 LED cathode pins of the first Digit Display. At this time, the first 7-Segment Display will show visible content and the remaining three will be OFF.

Similarly, the second, third and fourth 7-Segment Displays will show visible content in turn by scanning the display. Although the four number characters are displayed in turn separately, this process is so fast that it is unperceivable to the naked eye. This is due to the principle of optical afterglow effect and the vision persistence effect in human sight. This is how we can see all 4 number characters at the same time. However, if each number character is displayed for a longer period, you will be able to see that the number characters are displayed separately. 

Circuit
===============================================================

Use pin 11, 12, 13 on control board to control the 74HC595, and connect it to the 4-digit 7-segment display. Use pin 7, 6, 5, 4 to control the 4 common ports.

.. list-table:: 
    :width: 70%
    :align: center

    *   -   Schematic diagram
    *   -   |Chapter17_09|
    *   -   Hardware connection
    *   -   |Chapter17_10|

.. |Chapter17_09| image:: ../_static/imgs/17_Digital_Display/Chapter17_09.png
.. |Chapter17_10| image:: ../_static/imgs/17_Digital_Display/Chapter17_10.png

Sketch
===============================================================

Sketch 17.2.1
---------------------------------------------------------------

Now, write code to control 4-digit 7-segment display to display 4 numbers.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_17.2.1_4_Digit_7-Segment_Display/Sketch_17.2.1_4_Digit_7-Segment_Display.ino
    :linenos: 
    :language: c

Besides the similarity with the previous section, the difference is that this code is to output content to the four 7-segment display continuously. Write a function to select a common port.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_17.2.1_4_Digit_7-Segment_Display/Sketch_17.2.1_4_Digit_7-Segment_Display.ino
    :linenos: 
    :language: c
    :lines: 39-46

Write a function to send data to 74HC595.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_17.2.1_4_Digit_7-Segment_Display/Sketch_17.2.1_4_Digit_7-Segment_Display.ino
    :linenos: 
    :language: c
    :lines: 48-55

First select a common port and then output the content, which will be displayed by the 7-segment display connected to common port, to 74HC595 when operating. Clear the display content after a period of time to avoid ghosting phenomenon.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_17.2.1_4_Digit_7-Segment_Display/Sketch_17.2.1_4_Digit_7-Segment_Display.ino
    :linenos: 
    :language: c
    :lines: 29-35

Use cycle command in loop() function to output content to the four 7-segment display.

  for (int i = 0; i < 4; i++) {
    ...
  }

Repeat this operation continuously.

Verify and upload the code, and then you will see number 0123 shown by 4 digit 7-segment display.

.. image:: ../_static/imgs/17_Digital_Display/Chapter17_11.png
    :align: center

Sketch 17.2.2
---------------------------------------------------------------

Now write code to control 4-digit 7-segment display to display dynamic numbers.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_17.2.2_4_Digit_7-Segment_Display/Sketch_17.2.2_4_Digit_7-Segment_Display.ino
    :linenos: 
    :language: c

Frist set a timer with a cycle of 1s

.. code-block:: c

    FlexiTimer2::set(1000, timerInt);  // configure the timer and interrupt function
    FlexiTimer2::start();              // start timer

In the timer interrupt function, make the variable second plus 1

.. code-block:: c

    void timerInt() {
        second++;       // second plus 1
    }

In function loop(), The first Digit is used for displaying single digits of "dec", the second Digit is for tens, the third for hundreds and fourth for thousands respectively.

.. code-block:: c

    byte bit[4];
    bit[0] = second % 10;
    bit[1] = second / 10 % 10;
    bit[2] = second / 100 % 10;
    bit[3] = second / 1000 % 10;

Then display the value of each bit.

.. code-block:: c

    writeData(num[bit[3 - i]]);

Verify and upload the code, then you will see the dymaic number shown by 4 digit 7-segment display.