# LPC214X Microcontroller Code

This repository contains code written in C for the LPC214X microcontroller. 
The code demonstrates how to control the output pins of the LPC214X microcontroller to set them to a high or low state with specific delays.

# Prerequisites
To run this code, you will need:

* LPC214X microcontroller
* Development environment for LPC214X (e.g., Keil uVision)

Getting Started
* Clone this repository to your local machine or download the source code files.
* Open the project in your preferred development environment (e.g., Keil uVision).
* Make sure you have the necessary toolchain and target settings configured.
* Build and flash the code onto your LPC214X microcontroller.
  
# Code Description
The main code sets the direction and state of specific pins on the LPC214X microcontroller. Here's a breakdown of the code:

* The stop(int z) function is defined to introduce a delay. It uses nested loops to achieve the desired delay.
* The main() function is where the main functionality of the code resides.
* The direction of pins P0.0 to P0.3 is set as output using the IODIR0 register.
* All pins P0.0 to P0.3 are set to a high state using the IOSET0 register.
* A delay of 14 milliseconds is introduced using the stop() function.
* Pins P0.0 and P0.2 are set to a low state using the IOCLR0 register.
* Another delay of 14 milliseconds is introduced using the stop() function.
