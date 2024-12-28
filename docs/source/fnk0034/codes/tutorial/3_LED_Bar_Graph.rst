##############################################################################
Chapter LED Bar Graph
##############################################################################

We have learned previously how to control 1 or 2 LEDs through Sketch on the control board and learned some basic knowledge of programming. Now let us try to control 10 LEDs and learn how to simplify the code.

Project LED Bar Graph Display
***************************************************************

Let us use control board to control a bar graph LED consisting of 10 LEDs.

Component List
===============================================================

+-----------------------------------+---------------------------------------+
| Control board x1                  |  Breadboard x1                        |
|                                   |                                       |
|  |Chapter01_00|                   |   |Chapter01_01|                      |
+-----------------------------------+-------------------+-------------------+
| USB cable x1                      | LED bar graph x1  | Resistor 220Ω x10 |
|                                   |                   |                   |
|  |Chapter01_02|                   |  |Chapter03_00|   |  |Chapter01_04|   |
+-----------------------------------+                   |                   |
| Jumper M/M x11                    |                   |                   |
|                                   |                   |                   |
|  |Chapter01_06|                   |                   |                   |
+-----------------------------------+-------------------+-------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED_Blink/Chapter01_01.png
    :width: 85%
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png
.. |Chapter03_00| image:: ../_static/imgs/3_LED_Bar_Graph/Chapter03_00.png
.. |Chapter01_04| image:: ../_static/imgs/1_LED_Blink/Chapter01_04.png
.. |Chapter01_06| image:: ../_static/imgs/1_LED_Blink/Chapter01_06.png

Component Knowledge
===============================================================

Let us learn about the basic features of components to use them better.

LED bar graph
---------------------------------------------------------------

LED bar graph is a component integration consisting of 10 LEDs.  At the bottom of the LED bar graph, there are two rows of pins, corresponding to positive and negative pole separately. If the LED bar graph cannot work in the circuit, it is probably because the connection between positive and negative pole is wrong. Please try to reverse the LED bar graph connection.

.. image:: ../_static/imgs/3_LED_Bar_Graph/Chapter03_01.png
    :align: center

Code Knowledge
===============================================================

This section will use new code knowledge.

Array
---------------------------------------------------------------

Array is used to record a set of variables. An array is defined as below:

.. code-block:: c

    int a[10];

"int" is the type of the array and "10" represents the amount of elements of the array. This array can store 10 int types of elements as below.

.. code-block:: c

    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

Or there is another form that the number of elements is the size of the array:

.. code-block:: c

    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

We can reference elements of an array as below:

.. code-block:: c

    int i, j;
    i = a[0];
    j = a[1];
    a[0] = 0;

Among them, "[]" is the array index, with a[0] as the first elements in the array.

For example, now we define an array b[] below:

.. code-block:: c

    int b[] = {5, 6, 7, 8};

The value of each element in array b[] is as follows:

.. list-table:: 
    :width: 20%
    :align: center

    *   -   b[0]
        -   b[1]
        -   b[2]
        -   b[3]

    *   -   5
        -   6
        -   7
        -   8

This is just the use of one-dimensional array. And there are two-dimensional arrays, three-dimensional arrays, and multi-dimensional arrays. Readers interested of this part can develop your own learning.

Loop
The loop statement is used to perform repetitive work such as the initialization to all the elements of an array.

.. code-block:: c

    while(expression)
    functionX();

When there is more than one statement to be executed, the form is as follows:

.. code-block:: c

    while(expression){
        functionX();
        functionY();
    }

The first step of the execution is judging the expression inside "()". If the result is false, the statements inside "{}" will not be executed; if result is true, the statements will be executed.

.. code-block:: c

    int i = 0;
    while (i < 2)
    i = i + 1;
    i = 5;

First time: i<2, i=0 is tenable, execute i=i+1, then i=1;

Second time: i<2, i=1 is tenable, execute i=i+1, then i=2;

Third time: i<2, i=2 is not tenable, execution of loop statements is completed. Statement i=5 will be executed next. 

"do while" and "while" is similar. The difference is that the loop statements of "do while" is executed before judging expression. The result of the judgment will decide whether or not to go on the next execution:

.. code-block:: c

    do {
    functionX();
    } while (expression);

"for" is another loop statement, and its form is as follows:

.. code-block:: c

    for (expression1; expression2; expression 3)
    functionX();

When there is more than one statement to be executed, the form is as follows:

.. code-block:: c

    for (expression 1; expression 2; expression 3) {
        functionX();
        functionY();
    }

Expression 1 is generally used to initialize variables; expression 2 is a judgement which is used to decide whether or not to execute loop statements; the expression 3 is generally used to change the value of variables.

For example:

.. code-block:: c

    int i = 0, j = 0;
    for (i = 0; i < 2; i++)
        j++;
    i = 5;

First time: i=0, i<2 is tenable, execute j++, and execute i++, then i=1, j=1;

Second time: i=1, i<2 is tenable, execute j++, and execute i++, then i=2, j=2;

Third time: i<2 is tenable, i=2 is not tenable. The execution of loop statements is completed. Statement i=5 will be executed next.

.. list-table:: 
    :width: 50%
    :align: center

    *   -   :orange:`Operator ++, --`
    *   -   "i++" is equivalent to "i=i+1". And "i--" equivalent to "i=i-1".

Circuit
===============================================================

Let us use pin 4, 5, 6, 7, 8, 9, 10, 11, 12 of the control board to drive LED bar graph.

.. list-table:: 
    :width: 100%
    :align: center

    *   -   Schematic diagram
        -   Hardware connection

    *   -   |Chapter03_02|
        -   |Chapter03_03|

.. |Chapter03_02| image:: ../_static/imgs/3_LED_Bar_Graph/Chapter03_02.png
.. |Chapter03_03| image:: ../_static/imgs/3_LED_Bar_Graph/Chapter03_03.png

Sketch
===============================================================

Now let us complete the sketch to control LED bar graph.

Sketch 3.1.1
---------------------------------------------------------------

First, write a sketch to achieve the LED light water.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_3.1.1_LED_bar_graph_Display/Sketch_3.1.1_LED_bar_graph_Display.ino
    :linenos: 
    :language: c

Firstly, let us define a read-only variable to record the number of LEDs as the number of times in the loop.

.. code-block:: c

    const int ledCount = 10;    // the number of LEDs in the bar graph

.. list-table:: 
    :width: 50%
    :align: center

    *   -   :orange:`Read-only variable`
    *   -   "const" keyword is used to define read-only variables, 
         
            which is called in the same way as other variables.
        
            But read-only variables can only be assigned once.

Then we define an array used to store the number of pins connected to LED bar graph. So it is convenient to manipulate arrays to modify the pin number.

.. code-block:: c

    // an array of pin numbers to which LEDs are attached
    int ledPins[] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

Use loop statement to set the pins to output mode in function setup().

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_3.1.1_LED_bar_graph_Display/Sketch_3.1.1_LED_bar_graph_Display.ino
    :linenos: 
    :language: c
    :lines: 14-19

Define a function to turn ON a certain LED on the LED bar graph and turn OFF the other LEDs.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_3.1.1_LED_bar_graph_Display/Sketch_3.1.1_LED_bar_graph_Display.ino
    :linenos: 
    :language: c
    :lines: 28-37

Finally, when the above function is called cyclically, there will be a formation of flowing water lamp effect in LED bar graph.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_3.1.1_LED_bar_graph_Display/Sketch_3.1.1_LED_bar_graph_Display.ino
    :linenos: 
    :language: c
    :lines: 21-26

Verify and upload the code, then you will see the LED bar graph flashing like flowing water.

.. image:: ../_static/imgs/3_LED_Bar_Graph/Chapter03_04.png
    :align: center

Sketch 3.1.2
---------------------------------------------------------------

Then modify the code to create a reciprocating LED light water.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_3.1.2_LED_bar_graph_Display/Sketch_3.1.2_LED_bar_graph_Display.ino
    :linenos: 
    :language: c

We have modified the code inside the function loop() to make the LED bar graph light up in one direction, and then in a reverse direction repeatedly.

Verify and upload the code, then you will see a reciprocating LED water light on LED bar graph.

.. image:: ../_static/imgs/3_LED_Bar_Graph/Chapter03_05.png
    :align: center