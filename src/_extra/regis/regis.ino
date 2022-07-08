#include <Servo.h>

Servo left;
Servo right;

void setup() {
  left.attach(13);
  right.attach(12);

  left.writeMicroseconds(1500);
  right.writeMicroseconds(1500);
}

void loop() {
  // put your main code here, to run repeatedly:

}
