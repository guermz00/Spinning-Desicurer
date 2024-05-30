# Spinning Desicurer Control Scripts

This repository contains a collection of Arduino scripts developed for controlling different components of the Spinning Desicurer, a device used in the post-processing of 3D printed microfluidic chips.

## Contents

- `led_controller_test` - A script to test and control the LED.
- `motor_controller_test` - A script to test the motor controller.
- `button_push_mode` - A script to manage the operation of the motor and LED through button inputs.

## Installation

To use these scripts, upload them to an Arduino microcontroller using the Arduino IDE. Ensure that your hardware setup corresponds to the pin configurations defined in each script.

## Schematic Diagram and Connection Table

Below is the schematic diagram (Figure S2A) and the corresponding connection table (Figure S2B) for the Spinning Desicurer setup:

![Schematic Diagram and Connection Table](/images/figure_S3.png "Schematic Diagram and Connection Table")

## Usage

### LED Controller Test

The `led_controller_test` script turns on an LED at full brightness and then gradually dims it to off, providing a way to ensure the LED is functioning correctly.

#### Hardware Setup

- Ensure that your LED is connected to an LED driver board. We employed a LD24AJTA adjustable LED Driver Board sourced from Amazon. Be sure to obtain a power supply suited for your LED of choice specifications. 
- We employed a CHANZON High Power Led Chip 10W Purple Ultraviolet (UV 395nm / 900mA / DC 9V - 11V / 10 Watt) with a 12V 10A DC Universal Regulated Switching Power Supply (SMPS). Additionally, we employed a 60-degree lens with a heatsink and a fan as the LED holder. These three items were sourced from Amazon. 
- Connect your LED driver PWM pin to pin 5 on the Arduino. Connect driver GND to Arduino GND.

### Motor Controller Test

The `motor_controller_test` script is designed to test the functionality and speed control of a DC motor using an H-bridge, allowing the motor to run for a set duration. The script utilizes an H-bridge L293D motor driver to control both the direction and the speed of the motor.

#### Hardware Setup

- Connect your motor's control terminals to the motor driver's output pins.
- Connect the motor driver inputs to pins 2 and 3 on the Arduino (to control the direction).
- Connect the PWM control signal from the motor driver to pin 9 on the Arduino (to control the speed).

The H-bridge allows for direction control of the motor by alternating the HIGH and LOW signals through pins 2 and 3. The enable pin (pin 9), which uses PWM, manages the speed of the motor. This setup offers the flexibility to reverse the motor's direction electronically and control its speed via the PWM signal.

Ensure that the motor driver is appropriately powered by an external power supply that is capable of providing sufficient current for your motor of choice. We used a 5V power supply and a an electric motor with a CD holder. Remember to connect the ground of the motor power supply to the ground of the Arduino to complete the circuit.

### Button Push Mode

The `button_push_mode` script combines the functionalities of the LED controller and the motor controller. It provides a simple interface for toggling the LED and the motor on or off with the use of push buttons. This allows for manual control without the need for sending commands through the Arduino IDE's serial monitor.

#### Hardware Setup

- Follow the wiring diagram provided in Figure S2 to connect the L293D motor driver, ensuring the correct setup for directional and speed control of the motor.
- Connect the motor's control inputs to pins 2 and 3 on the Arduino, as these will determine the motor's direction.
- Connect the LED to pin 5 on the Arduino to control its brightness through PWM.
- Attach push buttons to pins 7 and 8 on the Arduino. The button connected to pin 7 will control the motor, and the button connected to pin 8 will control the LED.

The script will check the state of the buttons in the main loop and toggle the corresponding motor or LED state accordingly. The motor's speed can be adjusted by changing the value in the `analogWrite` function for the `enablePin`, and the LED's brightness can be controlled by adjusting the `analogWrite` value for the `ledPin`.

## Support

If you encounter any issues or have questions, feel free to send an email to guillermo.ramirez@utsa.edu.


## License

These scripts are provided under the MIT License. 
