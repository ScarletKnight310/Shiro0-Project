/*
 * EEPROM Read
 *
 * read values from all of EEPROM
 */

#include <EEPROM.h>

// -- number of items to be read is stored in EEPROM address 0
int count = 0;

// -- data starts at address 1
int address = 1;

void setup() 
{
  Serial.begin(9600);
  
  // -- Arduno Duemilanove: 512b EEPROM storage.
  // -- Arduino Uno:        1kb EEPROM storage.
  // -- Arduino Mega:       4kb EEPROM storage.
  // -- EEPROM.length provides the above values

  // -- read the number of items in the EEPROM from location 0
  count = EEPROM.read(0);
  Serial.print(count);
  Serial.println();

  //-- read and assemble the data items from EEPROM
  for (int i = 0; i < i < EEPROM.length(); ++i) {

    // -- read the high byte of the data value (big endian format)
    int high = EEPROM.read(address);
    ++address;
    // -- read the low byte of the data value
    int low = EEPROM.read(address);
    ++address;

    // -- assemble the values
    int value = high * 256 + low;
    Serial.print(" ");
    Serial.print(high);
    Serial.print(", ");
    Serial.print(low);
    Serial.println();
    Serial.print(value);
    Serial.println();
  }
  
}

void loop() {

}

void clear(){
  for(int i = 0; i < EEPROM.length(); i++){
      
  }
}
