#include <Servo.h>

Servo left, right;
const int PIN1L = 7;
const int PIN2R = 4;
const int spd = 200;

void setup() {
  Serial.begin(9600);
  pinMode(PIN1L,INPUT);
  pinMode(PIN2R,INPUT);
  left.attach(10, 1300, 1700);
  right.attach(11, 1300, 1700);
}

void loop() {
  // record
  //int l = digitalRead(PIN1L);
  //int r = digitalRead(PIN2R);
  int lr = digitalRead(PIN1L) * 10 + digitalRead(PIN2R);
  
  // decide + act
  // 00, 01, 10, 11
  if(lr == 11){
    //none
    Serial.println("none");
    //line(200);
  }
  else if(lr == 10){
    //right
    Serial.println("right"); /*
    line(-200);
    delay(500);
    turn(200,150,0);
    delay(500);
    */
  }
  
  else if(lr == 1){
    //left
    Serial.println("left");
    /*
    line(-200);
    delay(500);
    turn(200,200,1);
    delay(500);
    */
  }
  else{
    //both or left
    Serial.println("both");
    /*
    line(-200);
    delay(500);
    turn(200,400,0);
    delay(500);
    */
  }
}

void line(int spd){
  drive(spd, spd);
}

void turn(int spd, int reducAmt, bool innerWheel){
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
