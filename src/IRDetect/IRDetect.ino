// -- IR sensor
const int IRLED = 2; // emitter pin (IR LED)
const int IRDETECT = 3; // detector pin (IR DETECTOR)

// -- Red LED
const int LEDPIN = 13;


long freq = 38000;

void setup() {
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT); // -- Red LED
  pinMode(IRLED, OUTPUT); // -- IR LED
  pinMode(IRDETECT, INPUT); // -- IR Detector
}

void loop() {
  int ir = irDetect(IRLED, IRDETECT, freq);
  Serial.print(ir);
  Serial.print(" ");
  
  delay(5);
  int dist = irDistance(2, 1);
  if (ir == 1) {
    digitalWrite(LEDPIN, LOW);
  }
  else {
    digitalWrite(LEDPIN, HIGH);
  }

  Serial.println(dist);
  delay(100);
}

int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, 8); // modulate IR LED at specified frequency for at least 1 ms
  delay(1); // Wait 1 ms
  int ir = digitalRead(irReceiverPin); // IR receiver -> ir variable
  delay(1); // Down time before recheck
  return ir; // Return 1 no detect, 0 detect
}

int irDistance(int irLedPin, int irReceiverPin)
{
  int distance = 0;
  for(long f = 38000; f <= 42000; f += 1000) {
    distance += irDetect(irLedPin, irReceiverPin, f);
  }
  return distance;
}
