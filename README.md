# Two-Wheeled_Bot
 Self balancing, two-wheeled, arduino-based, bot platform

## Project Overview
 
 

 ### References and Attributions

 


 ### Background Information
 Reference material I found useful in developing this version:
 - [RTC tutorial](https://howtomechatronics.com/tutorials/arduino/arduino-ds3231-real-time-clock-tutorial/)


## Files
Content of the project folders:
- **code** - Arduino code
- **physical** - STL Files
- **circuits** - electronic circuit design
- **media** - pictures and video of project

## Bill of Materials
- 1x Arduino nano
- 2x [12v 28BYJ-48 stepper motors](https://www.amazon.com/gp/product/B015RQ97W8/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)
- 4x [A4988 stepper motor drivers](https://www.amazon.com/gp/product/B09FQ3G5XQ/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)
- PLA cable for 3D printer
- hot glue gun and glue
- nylon spacers and nuts


## Installation
Instructions for building the printed components, electronics, software, and assembly of the 2-Wheeled Bot.

#### Printed Components
Print all components in PLA.

| Component  | Count | Color |
| ---------- | ----: | ----- |
| BaseA (1)  |     1 | black |


#### Electronics
1. Hack the stepper motors.  The 28BYJ-48 stepper motors are unipolar and the
A4988 driver only works with bipolar motors.  Take the red wire out of the connector,
cut it near the motor and discard.  Reorder the wires in the connector so that
are in order orange, yellow, pink, blue, reading left to right when looking at
the flat side of the connector.  More info on this step [here](https://www.instructables.com/28BYJ-48-5V-Stepper-Motor-and-A4988-Driver/)  I ignored adjusting
the current potentiometer.
2. Build prototype board based on circuit diagrams.  Pins.h matches the pin
configuration of the prototype circuit diagram.  Breadboard diagram used different pins.

#### Code
1. Vertical_Clock - Main folder for final product.  Move this folder to Arduino environment, compile, and upload.  You'll need to install into your Arduino environment all of the libraries referenced in the include files.
  - vertical_clock.ino - primary Arduino file
  - ClockDigit.h and ClockDigit.cpp - class files for controlling stepper motors
  - ClockState.h and ClockState.cpp - class files for managing system state of clock.
2. led_via_npn - folder containing code for breadboarding the led
3. rotary_and_rtc - folder containing code for testing rtc and rotary switch modules
4. stepper - folder containing code for testing stepper motors and clock digits

## Assembly
1. xxx
2. xxx

## Usage
Operating instructions

### Setup and calibration
- xxx
- xxxx


#### Operation
- xxxx
- xxxx


## Ideas for Future Enhancements
1. xxxx
2. xxxx


## Contributing
- Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
- Please make sure to test updates as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)