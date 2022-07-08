// -- IR sensor 1
const int IRLED_L = 13;
const int IRDETECT_L = 12;

// -- IR sensor 2
const int IRLED_R = 3;
const int IRDETECT_R = 2;

// peak frequency for highest sensor sensitivity
long peakFreq = 38000;
int toneTime = 8;

// -- Red LEDs (servo motors on pin 10 and 11)
//const int LEDPIN1 = 12;
//const int LEDPIN2 = 13;

void setup() {
  Serial.begin(9600);
  pinMode(IRLED_L, OUTPUT); 
  pinMode(IRDETECT_L, INPUT);

  pinMode(IRLED_R, OUTPUT); 
  pinMode(IRDETECT_R, INPUT);
  
 // pinMode(LEDPIN1, OUTPUT);
  //pinMode(LEDPIN2, OUTPUT);
}

// 0 = something in front of it
// 1 = nothing in front of it
void loop() {
  //int distL = irDistance(IRLED_L, IRDETECT_L);
  int distR = irDistance(IRLED_R, IRDETECT_R);
  //Serial.print("L: ");
  //Serial.print(distL);
  //Serial.print(" R: ");
  Serial.print(distR);
  Serial.println("");
}

int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, toneTime); // modulate IR LED at specified frequency for at least 1 ms
  delay(1); // Wait 1 ms
  int ir = digitalRead(irReceiverPin); // IR receiver -> ir variable
  delay(1); // Down time before recheck
  return ir; // Return 1 no detect, 0 detect
}

// default
/*
int irDistance(int irLedPin, int irReceiverPin)
{
  int distance = 0;
  for(long f = 38000; f <= 42000; f += 1000) {
    distance += irDetect(irLedPin, irReceiverPin, f);
  }
  return distance;
}
*/
int irDistance(int irLedPin, int irReceiverPin)
{
  return irDistance(irLedPin, irReceiverPin, peakFreq, 42000, 500); // dec.
}

int irDistance(int irLedPin, int irReceiverPin, long minFreq, long maxFreq, long intervals)
{
  int distance = 0;
  for(long f = minFreq; f <= maxFreq; f += intervals) {
    distance += irDetect(irLedPin, irReceiverPin, f);
  }
  return distance;
}
