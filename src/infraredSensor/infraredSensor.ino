int t = 8;
int ledPIN = 3;
int reciPIN = 2;
int ledCPIN = 13;
long freqe = 38000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPIN, OUTPUT);
  pinMode(reciPIN, INPUT);
  pinMode(ledCPIN, OUTPUT);
}

void loop() {
  int irLeft = irDetect(ledPIN, reciPIN, freqe);
  Serial.println(irLeft);
  if(irLeft == 0){
    digitalWrite(ledCPIN, HIGH);  
  }
  else{
    digitalWrite(ledCPIN, LOW);
  }
  
  delay(100);
}

// 0 = something in front of it
// 1 = nothing in front of it
int irDetect(int irLED, int irRecive, long freq){
  tone(irLED, freq, t);
  delay(1);
  int ir = digitalRead(irRecive);
  delay(1);
  return ir;
}

int irDistance(int irLedPin, int irReceiverPin)
{
  int distance = 0;
  for(long f = 38000; f <= 42000; f += 1000) {
    distance += irDetect(irLedPin, irReceiverPin, f);
  }
  return distance;
}
