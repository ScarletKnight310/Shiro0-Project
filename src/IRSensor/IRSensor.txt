#include <Servo.h> // Include servo library

Servo servoLeft; // Declare left and right servos
Servo servoRight;

// -- IR sensor 1
const int IRLED_L = 13;
const int IRDETECT_L = 12;

// -- IR sensor 2
const int IRLED_R = 2;
const int IRDETECT_R = 3;

const int setpointL = 2; // Target distances
const int setpointR = 2;
const int kpl = -10; // Proportional control constants
const int kpr = -50;

void setup() // Built-in initialization block
{
  pinMode(IRLED_L, OUTPUT); 
  pinMode(IRDETECT_L, INPUT);

  pinMode(IRLED_R, OUTPUT); 
  pinMode(IRDETECT_R, INPUT);
  
  tone(4, 3000, 1000); // Play tone for 1 second
  delay(1000); // Delay to finish tone
  servoLeft.attach(10); // Attach left signal to pin 13
  servoRight.attach(11); // Attach right signal to pin 12
}

void loop() // Main loop auto-repeats
{
  int irLeft = irDistance(IRLED_L, IRDETECT_L); // Measure left distance
  int irRight = irDistance(IRLED_R, IRDETECT_R); // Measure right distance

  // Left and right proportional control calculations
  int driveLeft = (setpointL - irLeft) * kpl;
  int driveRight = (setpointR - irRight) * kpr;

  maneuver(driveLeft, driveRight, 20); // Drive levels set speeds
}

// IR distance measurement function
int irDistance(int irLedPin, int irReceivePin)
{
   int distance = 0;
   for(long f = 41500; f <= 42000; f += 125) {////////////////////////////////////////////////////////////////////
   distance += irDetect(irLedPin, irReceivePin, f);
   }
   return distance;
}

// IR Detection function
int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, 8); 
  delay(1); // Wait 1 ms
  int ir = digitalRead(irReceiverPin); // IR receiver -> ir variable
  delay(1); // Down time before recheck
  return ir; // Return 1 no detect, 0 detect
}

void maneuver(int speedLeft, int speedRight, int msTime)
{
 // speedLeft, speedRight ranges: Backward Linear Stop Linear Forward
 // -200 -100......0......100 200
 servoLeft.writeMicroseconds(1500 + speedLeft); // Left servo speed
 servoRight.writeMicroseconds(1500 - speedRight); // Right servo speed
 if(msTime==-1) // If msTime = -1
 {
 servoLeft.detach(); // Stop servo signals
 servoRight.detach();
 }
 delay(msTime); // Delay for msTime
} 
