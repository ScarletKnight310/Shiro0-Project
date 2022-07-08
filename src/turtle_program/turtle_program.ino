#include <Servo.h>
// Wheels
Servo left, right;

// Whiskers
const int WHIS_L = 2; 
const int WHIS_R = 4;

// Light Sensors
const int LS_L = A0;
const int LS_R = A1;

// Ambient Light
int ambientLight = 0;
bool useAmbientLight = true;
int alPadding = 5; // percentage %

// Other Const
const int repositionDelay = 500;
const int delaysBtw = 110;
const int lightChks = 100;

void setup() {
  pinMode(WHIS_L,INPUT);
  pinMode(WHIS_R,INPUT);
  left.attach(10, 1300, 1700);
  right.attach(11, 1300, 1700);

  // Calibration start
  if(useAmbientLight){
  // move in circle to collect more accurate data
  turn(200, 150, true);
  double sum = 0.0;
  for(int i = 0; i < lightChks; i++){
    double curLS_L = analogRead(LS_L);
    double curLS_R = analogRead(LS_R);
    
    sum += curLS_L - (curLS_L*(alPadding/100));
    sum += curLS_R - (curLS_R*(alPadding/100));
    delay(delaysBtw);
  }
  ambientLight = (int)((sum)/(2*lightChks));
  drive(0,0);
  }
  // Calibration end
}
 
void loop() {
  // Operation Mode
  // RECORD //
  int lr = digitalRead(WHIS_L) * 10 + digitalRead(WHIS_R);
  int vR = analogRead(LS_R);
  int vL = analogRead(LS_L);
  
  // DECIDE //
  // 00, 01, 10, 11
  int wLeft, wRight;
  bool usingLight;
  if(lr == 11){// LIGHT SENSORS ACTIVE
    //none, 
    //WLEFT USES RIGHT/ WRIGHT USES LEFT
    wLeft = map(vR,ambientLight,1023,0,200);
    wRight = map(vL,ambientLight,1023,0,200);
    usingLight = true;
  }
  else{// LIGHT SENSORS INACTIVE
    if(lr == 10){
      //right
      wLeft = 0;
      wRight = 200;
    }
    else if(lr == 1){
     //left
     wLeft = 200;
     wRight = 0;
    }
    else{
      //both
      wLeft = 200;
      wRight = -200;
    }
    // Move back
    line(-200);
    delay(repositionDelay);
    usingLight = false;
  }
  
  // ACT //
  if(usingLight){
    drive(wLeft, wRight);
  }
  else{
    // Move back
    line(-200);
    delay(repositionDelay);
    // Reposition
    drive(wLeft, wRight);
    delay(repositionDelay);
  }
}

///////////////////////////////////////////////////////////////////////////////
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
