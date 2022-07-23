#include <Multiplex7Seg.h>

byte digitPins[] = {9, 10, 11, 12};         // LSB to MSB
byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8}; // Segment a to g
unsigned int adc;

void setup() {
  Multiplex7Seg::set(1, 4, digitPins, segmentPins);   // Initialize 
  // See the example in Multiplex7Seg library for initialization parameters
}

void loop() { 
  Multiplex7Seg::loadValue(millis() / 10);  // Display incrementing value
  delay(247);
}
