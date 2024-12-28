##############################################################################
First Use
##############################################################################

Open the example sketch "Blink".

.. image:: ../_static/imgs/First_use/First_Use00.png
    :align: center

Select board "Arduino Uno". (Freenove control board is compatible with this board.)

.. image:: ../_static/imgs/First_use/First_Use01.png
    :align: center

Connect control board to your computer with USB cable.

.. image:: ../_static/imgs/First_use/First_Use02.png
    :align: center

Select the port.

.. note::
    
    Your port may be different from the following figure.
    
    On Windows: It may be COM4, COM5 (Arduino Uno) or something like that.
    
    On Mac: It may be /dev/cu.usbserial-710, /dev/cu.usemodem7101 (Arduino Uno) or something like that.
    
    On Linux: It may be /dev/ttyUSB0, /dev/ttyACM0 or something like that.

.. image:: ../_static/imgs/First_use/First_Use03.png
    :align: center

.. note::
    
    If there is more than one port and you cannot decide which one to choose, disconnect the USB cable and check the port. Then connect the USB cable and check the port again. The new one is the correct port.

If there is no COM port for control board, you may need to install a driver to your conputer.

- For blue board, reinstall the latest version of Arduino IDE. During installation, agree to install the driver.
- For black board, see “InstallDriver.pdf” in “Drivers” folder (in the folder contains this Tutorial.pdf).

:red:`Having problems?` Contact us for help! Send mail to: support@freenove.com

Click "Verify" button.

.. image:: ../_static/imgs/First_use/First_Use04.png
    :align: center

The following figure shows the code being compiled.

.. image:: ../_static/imgs/First_use/First_Use05.png
    :align: center

Wait a moment for the compiling to be completed. Figure below shows the code size and percentage of space occupation. If there is an error in the code, the compilation will fail and the details are shown here.

.. image:: ../_static/imgs/First_use/First_Use06.png
    :align: center

Click "Upload" button.

.. image:: ../_static/imgs/First_use/First_Use07.png
    :align: center

Figure below shows code are uploading. 

.. image:: ../_static/imgs/First_use/First_Use08.png
    :align: center

Wait a moment, and then the uploading is completed.

.. image:: ../_static/imgs/First_use/First_Use09.png
    :align: center

:red:`Having problems?` Contact us for help! Send mail to: support@freenove.com

After that, we will see the LED marked with "L" on the control board start blinking. It indicates that the code is running now!

.. image:: ../_static/imgs/First_use/First_Use10.png
    :align: center

So far, we have completed the first use. I believe you have felt the joy of it. Next, we will carry out a series of projects, from easy to difficult, taking you to learn programming and the building of electronic circuit.