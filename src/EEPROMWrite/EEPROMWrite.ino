/*
 * EEPROM Write
 *
 * writes sequential values to all of EEPROM
 */

#include <EEPROM.h>

// -- data will be written to the EEPROM starting at address 1
//    address 0 will hold the number of items written (assume < 256)
int address = 1;

// -- number of values written
int count = 0;

void setup() 
{
  Serial.begin(9600);
  // -- Arduno Duemilanove: 512b EEPROM storage.
  // -- Arduino Uno:        1kb EEPROM storage.
  // -- Arduino Mega:       4kb EEPROM storage.
  // -- EEPROM.length provides the above values

  // -- simulate the test/measurement system
  Serial.println("EEPROM Write");
  for (int i = 0; i < 5; ++i) {
    // -- read the starting time in milliSeconds (1/1000 seconds)
    unsigned long start = millis();
    // -- delay for 10 seconds to simulate sensor reading
    delay(5000);
    // -- read the ending time in milliSeconds (1/1000 seconds)
    unsigned long end = millis();

    // -- calulate the elapsed time from start to end
    unsigned long diff = end - start;

    // -- split the elapsed time into two values to facilitate writing to EEPROM
    unsigned long high = (unsigned long)(diff / 256);
    unsigned long low = (unsigned long)(diff % 256);

    Serial.println(diff);
    Serial.print(" ");
    Serial.print(high);
    Serial.print(" ");
    Serial.print(low);
    Serial.println();
     Serial.println("EEPROM Write");
    // -- write the values to EEPROM in high/low order. This is called "big endian"
    EEPROM.write(address, high); 
    ++address;
    EEPROM.write(address, low);
    ++address;

    // -- increment the number of items written
    ++count;
    
    Serial.print(end - start);
    Serial.print(" ");
    Serial.print(high);
    Serial.print(" ");
    Serial.print(low);
    Serial.println();
  }

  // -- write the count to EEPROM location 0
  EEPROM.write(0, count);

  Serial.println("done");
  
}

void loop() {


}
