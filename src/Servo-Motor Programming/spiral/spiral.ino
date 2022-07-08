#include <Servo.h>

Servo left, right;
int raCH = 160;

void setup() {
  left.attach(10, 1300, 1700);
  right.attach(11, 1300, 1700);
}

void loop() { 
  delay(500);
  circle(200, raCH, true);
  raCH++;
  if(raCH >= 200){
    drive(0,0);
    fin();
  }
}

void fin(){
  fin();  
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
