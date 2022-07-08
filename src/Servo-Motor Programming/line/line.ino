#include <Servo.h>

Servo left, right;

void setup() {
  left.attach(10, 1300, 1700);
  right.attach(11, 1300, 1700);

  line(200);
  // delays for 6 seconds
  delay(6000);
  line(0);
}

void loop() { 
}

// gives equal rotation to both wheels
void line(int spd){
  drive(spd, spd);
}

void drive(int leftpw, int rightpw){
  left.writeMicroseconds(1500 + leftpw);
  right.writeMicroseconds(1500 - rightpw);
}
