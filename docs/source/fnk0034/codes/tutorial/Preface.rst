##############################################################################
Preface
##############################################################################

If you want to make some interesting projects or want to learn electronics and programming, this document will greatly help you.

Projects in this document usually contains two parts: the circuit and the code. No experience at all? Don't worry, this document will show you how to start from scratch.

If you encounter any problems, please feel free to send us an email, we will try our best to help you.

Support email: support@freenove.com

To complete these projects, you need to use a control board and software to program it, as well as some commonly used components.

Control Board
****************************************************************

The control board is the core of a circuit. After programming, it can be used to control other components in the circuit to achieve intended functions.

There are multiple versions of Freenove control board. Your purchase may be one of the following:

.. list-table:: 
    :width: 100%
    :align: center

    *   -   Freenove Control Board (Black)
        -   Freenove Control Board (Blue)
    
    *   -   |Preface00|
        -   |Preface01|

.. |Preface00| image:: ../_static/imgs/Preface/Preface00.png
.. |Preface01| image:: ../_static/imgs/Preface/Preface01.png


.. note::
    
    Although the colors and shapes of these control boards are somewhat different, their ports and functions are the same. They can be replaced with each other, and there is no difference in their usages.

.. note::
    
    Only the black control board is used to display the hardware connection in this document.

The hardware connection of the blue control board is the same.

Diagram of the Freenove control board is shown below:

.. image:: ../_static/imgs/Preface/Preface02.png
    :align: center

- Digital I/O ports is used to connect to other components or modules, to receive an input signal, or to send a control signal. Usually, we name it by adding a "D" in front of the number, such as D13 (pin 13).
- USB interface is used to provide power, upload code or communicate with PC. 
- LED L is connected to digital I/O port 13 (pin 13).
- LED TX, RX is used to indicate the state of the serial communication. 
- DC interface is connected DC power to provide power for the board.
- Power ports can provide power for electronic components and modules.
- Analog I/O ports can be used to measure analog signals. 
- LED ON is used to indicate the power state.

Programming Software
****************************************************************

We use Arduino® IDE to write and upload code for the control board, which is a free and open source.

(Arduino® is a trademark of Arduino LLC.)

Arduino IDE uses C/C++ programming language. Don't worry if you have never used it, because this document contains programming knowledge and detailed explanation of the code.

First, install Arduino IDE. Visit https://www.arduino.cc/en/software. Scroll down and find Legacy IDE (1.8.X). Then select and download corresponding installer according to your operating system. If you are a windows user, please select the "Windows Installer".

- :red:`! Do not download “Arduino IDE 2.x.x” unless you are familiar with it, or you may encounter problems.`
- :red:`! “Windows app” is not recommended. It is reported that it sometimes fails to work properly.`

.. image:: ../_static/imgs/Preface/Preface03.png
    :align: center

After the downloading completes, run the installer. For Windows users, there may pop up an installation dialog box of driver during the installation process. When it is popped up, please allow the installation.

After installation is completed, an shortcut will be generated in the desktop.

.. image:: ../_static/imgs/Preface/Preface04.png
    :align: center

Run it. The interface of the software is as follows:

.. image:: ../_static/imgs/Preface/Preface05.png
    :align: center

Programs written with Arduino IDE are called sketches. These sketches are written in a text editor and are saved with the file extension.ino. The editor has features for cutting/pasting and for searching/replacing text. The message area gives feedback while saving and exporting and also displays errors. The console displays text output by the Arduino IDE, including complete error messages and other information. The bottom right-hand corner of the window displays the configured board and serial port. The toolbar buttons allow you to verify and upload programs, create, open, and save sketches, and open the serial monitor.

.. list-table:: 
    :width: 80%
    :widths: 20 70
    :align: center

    *   -   |Preface06|
        -   Verify - Checks your code for errors compiling it. 

    *   -   |Preface07|
        -   Upload - Compiles your code and uploads it to the configured board. 
    
    *   -   |Preface08|
        -   New - Creates a new sketch.  

    *   -   |Preface09|
        -   Open - Presents a menu of all the sketches in your sketchbook. 
         
            Clicking one will open it within the current window overwriting its content.   

    *   -   |Preface10|
        -   Save - Saves your sketch.  

    *   -   |Preface11|
        -   Serial Monitor - Opens the serial monitor. 

.. |Preface06| image:: ../_static/imgs/Preface/Preface06.png
.. |Preface07| image:: ../_static/imgs/Preface/Preface07.png
.. |Preface08| image:: ../_static/imgs/Preface/Preface08.png
.. |Preface09| image:: ../_static/imgs/Preface/Preface09.png
.. |Preface10| image:: ../_static/imgs/Preface/Preface10.png
.. |Preface11| image:: ../_static/imgs/Preface/Preface11.png

Additional commands are found within five menus: File, Edit, Sketch, Tools, Help. The menus are context sensitive, which means only those items relevant to the work currently being carried out are available.