#include <Servo.h>

Servo left, right;

void setup() {
  left.attach(10, 1300, 1700);
  right.attach(11, 1300, 1700);

  circle(200, 150, true);
}

void loop() { 
  
}

// parameters:  integer for max speed, 
//              integer for how much the second wheel will be reduced,
//              boolean for which wheel will be reduced (true == right/ false == left)
void circle(int spd, int reducAmt, bool innerWheel){
  if(innerWheel == true){
    drive(spd, spd - reducAmt);
  }
  else{
    drive(spd - reducAmt, spd);
  }
}

void drive(int leftpw, int rightpw){
  left.writeMicroseconds(1500 + leftpw);
  right.writeMicroseconds(1500 - rightpw);
}
