#include <Servo.h>

Servo left;
Servo right;

void setup() {
  left.attach(13);
  right.attach(12);
  drive(0, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  drive(0, 0);
}
/*
* assumes Servo LEFT and RIGHT are globally defined and attached
* leftpw and rightpw are pulsewaves
* -200 <= leftpw, rightpw <= 200
* -200 reverse 200 
*/
void drive(int leftpw, int rightpw){
  left.writeMicroseconds(1500 + leftpw);
  right.writeMicroseconds(1500 - rightpw);
}
