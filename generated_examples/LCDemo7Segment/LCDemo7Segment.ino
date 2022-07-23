// //We always have to include the library
// #include "LedControl.h"

// /*
//  Now we need a LedControl to work with.
//  ***** These pin numbers will probably not work with your hardware *****
//  pin 12 is connected to the DataIn 
//  pin 11 is connected to the CLK 
//  pin 10 is connected to LOAD 
//  We have only a single MAX72XX.
//  */
// LedControl lc=LedControl(2,1);

// /* we always wait a bit between updates of the display */
// unsigned long delaytime=250;

// void setup() {
//   /*
//    The MAX72XX is in power-saving mode on startup,
//    we have to do a wakeup call
//    */
//   lc.shutdown(0,false);
//   /* Set the brightness to a medium values */
//   lc.setIntensity(0,8);
//   /* and clear the display */
//   lc.clearDisplay(0);
// }


// /*
//  This method will display the characters for the
//  word "Arduino" one after the other on digit 0. 
//  */
// void writeArduinoOn7Segment() {
//   lc.setChar(0,0,'a',false);
//   delay(delaytime);
//   lc.setRow(0,0,0x05);
//   delay(delaytime);
//   lc.setChar(0,0,'d',false);
//   delay(delaytime);
//   lc.setRow(0,0,0x1c);
//   delay(delaytime);
//   lc.setRow(0,0,B00010000);
//   delay(delaytime);
//   lc.setRow(0,0,0x15);
//   delay(delaytime);
//   lc.setRow(0,0,0x1D);
//   delay(delaytime);
//   lc.clearDisplay(0);
//   delay(delaytime);
// } 

// /*
//   This method will scroll all the hexa-decimal
//  numbers and letters on the display. You will need at least
//  four 7-Segment digits. otherwise it won't really look that good.
//  */
// void scrollDigits() {
//   for(int i=0;i<13;i++) {
//     lc.setDigit(0,3,i,false);
//     lc.setDigit(0,2,i+1,false);
//     lc.setDigit(0,1,i+2,false);
//     lc.setDigit(0,0,i+3,false);
//     delay(delaytime);
//   }
//   lc.clearDisplay(0);
//   delay(delaytime);
// }

// void loop() { 
//   // writeArduinoOn7Segment();
//   scrollDigits();
// }

#include <LedControl.h>

/* REFERENCES
* https://hastebin.com/axovofapag.coffee
* http://www.kevindarrah.com/download/arduino_code/MAX7219_DEMO.ino
* https://github.com/ozhantr/DigitLedDisplay
* https://github.com/wayoda/LedControl
*/

#define DIN 5
#define CS 5
#define CLK 7
#define NUM_DISPLAYS 1

// OPCODES
#define OP_DECODE 0x09
#define OP_INTENSITY 0x0A
#define OP_SCANLIMIT 0x0B
#define OP_SHUTDOWN 0x0C
#define OP_DISPLAYTEST 0x0F

// DECODE modes
#define DECODE_ALL 0x0F
#define DECODE_NONE 0x00
#define DECODE_FIRST 0x01
#define DECODE_HALF 0x0F

unsigned long counterValue = 0;
unsigned long counterValue2 = 9899;
byte digits[8];
byte digits2[8];

LedControl lc = LedControl(CS, NUM_DISPLAYS);

void initialize()
{
    digitalWrite(CS, HIGH);
    pinMode(DIN, OUTPUT);
    pinMode(CS, OUTPUT);
    pinMode(CLK, OUTPUT);

    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT);
}

void output(byte address, byte data)
{
    digitalWrite(CS, LOW);
    shiftOut(DIN, CLK, MSBFIRST, address);
    shiftOut(DIN, CLK, MSBFIRST, data);
    digitalWrite(CS, HIGH);
}

void setDisplayTest(bool state)
{
    output(OP_DISPLAYTEST, state);
}

void setShutdown(bool state)
{
    output(OP_SHUTDOWN, state);
}

void setIntensity(byte value)
{
    output(OP_INTENSITY, value);
}

void setScanLimit(byte value)
{
    output(OP_SCANLIMIT, value);
}

void setDecode(byte state)
{
    output(OP_DECODE, state);
}

void loop()
{
    // int pin = digitalRead(3);
    // if (pin == LOW)
    //     counterValue = 0;
    // if (digitalRead(4) == HIGH)
    //     counterValue2 = 0;

    counterValue++;
    counterValue2++;
    convertToDigits(digits, counterValue);
    // convertToDigits(digits2, counterValue2);
    displayNumber(0, digits);
    // displayNumber(1, digits2);

    // Serial.println(pin);
    delay(1);
}

void setup()
{
    Serial.begin(9600);
    // initialize();
    // setDisplayTest(false);
    // setIntensity(0);
    // setScanLimit(0x07);
    // setDecode(DECODE_ALL);
    // for (int i = 1; i < 9; i++)
    // {
    //     output(i, 1);
    // }
    // setShutdown(true);
    // output(0x0c, 0x01);

    for (int i = 0; i < NUM_DISPLAYS; i++)
    {
        lc.shutdown(i, false);
        lc.clearDisplay(i);
        lc.setIntensity(i, 0);
        lc.setScanLimit(i, 8);
    }
}

void displayNumber(int addr, byte data[])
{
    for (int i = 0; i < 8; i++)
    {
        // output(i + 1, digits[i]);

        lc.setDigit(addr, i, data[i], false);
    }
}

void convertToDigits(byte output[], unsigned long value)
{
    unsigned long digitsCounter = value;

    for (int i = 0; i < 8; i++)
    {
        output[i] = digitsCounter % 10;

        // if (digitsCounter < pow(10, i)) // 1, 10, 100, 1000....
        //     output[i] = 0x0F;          // set the data to something out of range so the chip doesn't display anything on that digit -- set to 0x00 to pad with 0s (or any other valid value)

        digitsCounter /= 10;
    }
}