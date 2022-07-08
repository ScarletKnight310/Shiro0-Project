#include <Servo.h>

Servo left, right;
bool iwheel = true;
void setup() {
  left.attach(10, 1300, 1700);
  right.attach(11, 1300, 1700);
}

void loop() { 
  line(200);
  delay(2230);
  circle(200, 180, iwheel);
  delay(6000);
  iwheel = !iwheel;
}

// gives equal rotation to both wheels
void line(int spd){
  drive(spd, spd);
}

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
