##############################################################################
Chapter Servo
##############################################################################

Earlier, we have used control board and L293D module to control the motor speed and steering. Now, we will use another motor, servo, which can rotate to a certain angle.

Project Servo Sweep
***************************************************************

First, let's get the servo to rotate.

+------------------------------------+---------------------------------+
|                                    | USB cable x1                    |
|  Control board x1                  |                                 |
|                                    |  |Chapter01_02|                 |
|    |Chapter01_00|                  +---------------------------------+
|                                    | Jumper M/M x3                   |
|                                    |                                 |
|                                    |  |Chapter01_06|                 |
|                                    +---------------------------------+
|                                    | Servo x1                        |
|                                    |                                 |
|                                    |  |Chapter11_00|                 |
+------------------------------------+---------------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png
.. |Chapter01_06| image:: ../_static/imgs/1_LED_Blink/Chapter01_06.png
.. |Chapter11_00| image:: ../_static/imgs/11_Servo/Chapter11_00.png

Component Knowledge
===============================================================


Servo
---------------------------------------------------------------

Servo is a compact package which consists of a DC Motor, a set of reduction gears to provide torque, a sensor and control circuit board. Most Servos only have a 180-degree range of motion via their “horn”. Servos can output higher torque than a simple DC Motor alone and they are widely used to control motion in model cars, model airplanes, robots, etc. Servos have three wire leads which usually terminate to a male or female 3-pin plug. Two leads are for electric power: Positive (2-VCC, Red wire), Negative (3-GND, Brown wire), and the signal line (1-Signal, Orange wire) as represented in the Servo provided in your Kit.

.. image:: ../_static/imgs/11_Servo/Chapter11_01.png
    :align: center

We will use a 50Hz PWM signal with a duty cycle in a certain range to drive the Servo. The lasting time 0.5ms-2.5ms of PWM single cycle high level corresponds to the Servo angle 0 degrees - 180 degree linearly. Part of the corresponding values are as follows:

.. list-table:: 
    :width: 100%
    :align: center

    *   -   High level time
        -   Servo angle

    *   -   0.5ms
        -   0 degree

    *   -   1ms
        -   45 degree

    *   -   1.5ms
        -   90 degree

    *   -   2ms
        -   135 degree

    *   -   2.5ms
        -   180 degree

When you change the servo signal, the servo will rotate to the designated position.

Circuit
===============================================================

Use pin 3 of the control board to drive the servo. 

Pay attention to the color of servo lead wire: VCC (red), GND (brown), and signal line (orange). The wrong connection can cause damage to servo.

.. list-table:: 
    :width: 100%
    :align: center

    *   -   High level time
        -   Servo angle

    *   -   |Chapter11_02|
        -   |Chapter11_03|

.. |Chapter11_02| image:: ../_static/imgs/11_Servo/Chapter11_02.png
.. |Chapter11_03| image:: ../_static/imgs/11_Servo/Chapter11_03.png

Sketch
===============================================================

Sketch 11.1.1
---------------------------------------------------------------

Now, write the code to control servo, making it sweep in the motion range continuously.

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_11.1.1_Servo_Sweep/Sketch_11.1.1_Servo_Sweep.ino
    :linenos: 
    :language: c

Servo uses the Servo library, like the following reference to Servo library:

.. code-block:: c

    #include <Servo.h>

Servo library provides the Servo class that controls it. Different from previous Serial class, the Servo class must be instantiated before you use it: 

.. code-block:: c

    Servo myservo;              // create servo object to control a servo

The code above defines an object of Servo type, myservo.

.. py:function:: Servo Class

    Servo class must be instantiated when used, that is, define an object of Servo type, for example:
    
    Servo myservo;
    
    Most other boards can define 12 objects of Servo type, namely, they can control up to 12 servos.
    
    The function commonly used in the servo class is as follows: 
    
    myservo.attach(pin): Initialize the servo, the parameter is the port connected to servo signal line;
    
    myservo.write(angle): Control servo to rotate to the specified angle; parameter here is to specify the angle.

After the Servo object is defined, it can refer to the function, such as initializing the servo:

.. code-block:: c

    myservo.attach(servoPin); // attaches the servo on servoPin to the servo object

After initializing the servo, you can control the servo to rotate to a specific angle: 

.. code-block:: c

    myservo.write(pos);              // tell servo to go to position in variable "pos"

In the loop () function, we use the loop to control the servo to rotate from 0 degrees to 180 degrees, and then from 180 degrees to 0 degrees, then repeat the cycle all the time.

Verify and upload the code, the servo starts to sweep continuously. 

.. image:: ../_static/imgs/11_Servo/Chapter11_04.png
    :align: center

Project Control Servo with Potentiometer
***************************************************************

In the previous section, we've made the servo sweep continuously. Now, we will use a potentiometer to control the servo’s angle.

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
|  Rotary potentiometer x1           | Servo x1                        |
|                                    |                                 |
|  |Chapter07_00|                    |  |Chapter11_00|                 |
+------------------------------------+---------------------------------+

.. |Chapter07_00| image:: ../_static/imgs/7_ADC/Chapter07_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED_Blink/Chapter01_01.png

Circuit
===============================================================

Use pin A0 of the control board to detect the voltage of rotary potentiometer, and pin 3 to drive the servo.

.. list-table:: 
    :width: 100%
    :align: center

    *   -   Schematic diagram
        -   Schematic diagram

    *   -   |Chapter11_05|
        -   |Chapter11_06|

.. |Chapter11_05| image:: ../_static/imgs/11_Servo/Chapter11_05.png
.. |Chapter11_06| image:: ../_static/imgs/11_Servo/Chapter11_06.png

Sketch

Sketch 11.2.1

Now, write the code to detect the voltage of rotary potentiometer, and control servo to rotate to a different angle according to that. 

.. literalinclude:: ../../../freenove_17_Kit/Sketches/Sketch_11.2.1_Control_Servo_by_Potentiometer/Sketch_11.2.1_Control_Servo_by_Potentiometer.ino
    :linenos: 
    :language: c

In the code, we obtain the ADC value of pin A0, and map it to the servo angle.

Verify and upload the code, turn the potentiometer shaft, then the servo will rotate to a corresponding angle.

.. image:: ../_static/imgs/11_Servo/Chapter11_07.png
    :align: center
