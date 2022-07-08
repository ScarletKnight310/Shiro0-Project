#include <EEPROM.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Start");
  clear();
  Serial.println("Done");
}

void clear(){
  for(int i = 0; i < EEPROM.length(); i++){
      EEPROM.write(i, 0);
  }
}
