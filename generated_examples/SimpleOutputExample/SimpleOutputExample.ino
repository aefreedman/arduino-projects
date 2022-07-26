#include <Shifty.h>

// Declare the shift register
Shifty shift; 

void setup() {
  // Set the number of bits you have (multiples of 8)
  shift.setBitCount(8);

  // Set the clock, data, and latch pins you are using
  // This also sets the pinMode for these pins
  shift.setPins(2, 3, 4); 

  shift.batchWriteBegin();
  for (int i = 1; i < 8; i++)
  {
    shift.writeBit(i, HIGH);
  }
  shift.batchWriteEnd();
}

void loop() {
  // // writeBit works just like digitalWrite
  // shift.writeBit(1, HIGH);
  // delay(500);
  // shift.writeBit(3, HIGH);
  // delay(500);
  // shift.writeBit(1, LOW);
  // delay(500);
  // shift.writeBit(3, LOW);
 
  // delay(500);
}
