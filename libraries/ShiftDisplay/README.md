# ShiftDisplay
_by MiguelPynto_

Arduino library for driving multiple-digit 7-segment LED displays using 74HC595 shift registers

- Show numbers and text
- Concatenate multiple displays as one, for a maximum of 8 digits
- Compatible with common cathode and common anode
- Only 3 pins used on Arduino

![breadboard](https://raw.githubusercontent.com/MiguelPynto/ShiftDisplay/master/extras/foobar.jpg)


## Hardware

- 1x (or more) 7-segment LED display
- 2x 74HC595 shift register
- 8x (per display) 220 Ohm resistor


## Install

1. Start the Arduino IDE
1. Open Library Manager (Menu > Sketch > Include Library > Manage Libraries)
2. Search for ShiftDisplay library (Filter your search > shiftdisplay)
3. Select it and click install


## Wiring

1. Connect Arduino to shift registers:
![input](https://raw.githubusercontent.com/MiguelPynto/ShiftDisplay/master/extras/input.png)

2. Connect shift registers to display(s):
![output](https://raw.githubusercontent.com/MiguelPynto/ShiftDisplay/master/extras/output.png)


## Reference

### Constructors

* __ShiftDisplay()__
  * ShiftDisplay led(displayType, displaySize)
  * ShiftDisplay led(latchPin, clockPin, dataPin, displayType, displaySize)

  Creates ShiftDisplay object, initializes the library with the interface pins, and sets up with the display properties.

  `led`: is a variable of type ShiftDisplay.

  `latchPin`, `clockPin`, `dataPin`: are the number of the Arduino digital pins connected to the shift registers latch, clock and data pins;
  optional; if not defined, the default pins are 6, 7 and 5 respectively.

  `displayType`: is a constant `COMMON_CATHODE` or `COMMON_ANODE`, depending on the type of your display(s).

  `displaySize`: is the quantity of digits on all displays combined.

### Functions

* __set()__
  * led.set(value)
  * led.set(value, alignment)
  * led.set(value, decimalPlaces)
  * led.set(value, decimalPlaces, alignment)

  Saves a value to buffer for printing latter.

  `led`: is a variable of type ShiftDisplay.

  `value`: is the value to save;
  can be a number (int, long, float, double) or text (char, char array, String object);
  for text, valid characters are 0-9 a-z A-Z - space.

  `alignment`: is the alignment of the value on the display;
  optional, constant `ALIGN_LEFT`, `ALIGN_RIGHT` or `ALIGN_CENTER`;
  if not defined, the default is ALIGN_RIGHT for numbers and ALIGN_LEFT for text.

  `decimalPlaces`: is the number of digits following the decimal point;
  optional and only available if the value is a float or double number;
  if not defined, the default is 2.

* __insertPoint()__
  * led.insertPoint(index)

  Insert point in buffer.

  `index`: is the position on the display to insert point, starting at 0 for the leftmost.

* __removePoint()__
  * led.removePoint(index)

  Remove point from buffer.

  `index`: is the position on the display to remove point, starting at 0 for the leftmost.

* __show()__
  * led.show()
  * led.show(time)

  Shows buffer value on the display.

  `led`: is a variable of type ShiftDisplay.

  `time`: is the time in milliseconds for the value to be shown on the display;
  has to be >= 10;
  optional; if not defined, the value is shown for a single iteration;
  exact time showing will be an aproximation.

* __print()__
  * led.print(time, value)
  * led.print(time, value, alignment)
  * led.print(time, value, decimalPlaces)
  * led.print(time, value, decimalPlaces, alignment)

  Saves a value to buffer and shows it on the display.

  `led`: is a variable of type ShiftDisplay.

  `time`: is the time in milliseconds for the value to be shown on the display;
  has to be >= 10;
  exact time showing will be an aproximation.

  `value`: is the value to save and show;
  can be a number (int, long, float, double) or text (char, char array, String object);
  for text, valid characters are 0-9 a-z A-Z - space.

  `alignment`: is the alignment of the value on the display;
  optional, constant `ALIGN_LEFT`, `ALIGN_RIGHT` or `ALIGN_CENTER`;
  if not defined, the default is ALIGN_RIGHT for numbers and ALIGN_LEFT for text.

  `decimalPlaces`: is the number of digits following the decimal point;
  optional and only available if the value is a float or double number;
  if not defined, the default is 2.

### Constants

- ALIGN_LEFT
- ALIGN_RIGHT
- ALIGN_CENTER
- COMMON_ANODE
- COMMON_CATHODE


## Example

```c
#include <ShiftDisplay.h>

// Arduino pin 6 connected to shift register latch, pin 7 to clock and pin 5 to data
// common cathode display with 3 digits
ShiftDisplay led(6, 7, 5, COMMON_CATHODE, 3);

void setup() {
	for (int i = 3; i > 0; i--) {
		led.print(400, i, ALIGN_CENTER); // save number and show it for 400ms
		led.insertPoint(1); // add dot to saved number
		led.show(400); // show number with dot for 400ms
	}
	led.set("GO"); // save "GO" to buffer
}

void loop() {
	led.show(); // show "GO." while in loop
}
```


## Changelog

- 3.3.3 (30/3/2017)
  - Change: updated contact details
- 3.3.2 (6/1/2017)
  - Change: faster show() function
  - Bugfix: better non-Arduino support (eg. attiny)
- 3.3.1 (18/12/2016)
  - Bugfix: Countdown example
- 3.3.0 (18/12/2016)
  - Feature: insertPoint() function
  - Feature: removePoint() function
  - Change: removed punctuation characters
- 3.2.3 (26/11/2016)
  - Bugfix: decimal point not showing in common anode displays
- 3.2.2 (25/11/2016)
  - Documentation: website
- 3.2.1 (24/11/2016)
  - Documentation: explain examples
- 3.2.0 (22/11/2016)
  - Bugfix: default alignments
  - Change: float/double function alignment without decimalPlaces obligation
- 3.1.0 (21/11/2016)
  - Bugfix: float/double functions problems with 0.x and -0.x
  - Bugfix: common anode display initiates unclear
  - Feature: new constructor with default pins
  - Feature: punctuation characters
  - Change: small improvements
- 3.0.1 (19/11/2016)
  - Bugfix: float/double functions not working
  - Bugfix: show/print functions exceeding time
- 3.0.0 (17/11/2016)
  - Code rewriting: performance and behavior improvement
  - Change: function signatures
  - Feature: buffer
  - Documentation: new examples
  - Documentation: updated images
- 2.2.0 (14/07/2015)
  - Feature: minimal print function
  - Feature: exit left/right animation
- 2.1.0 (03/07/2015)
  - Feature: center alignment
- 2.0.0 (23/06/2015)
  - Code refactoring
  - Full and lightweight versions
  - Feature: left and right alignment
- 1.0.0 (26/05/2015)
  - Initial release


## TODO

- [x] All done


## Contacts

miguelpynto@outlook.com

https://miguelpynto.github.io/ShiftDisplay/
