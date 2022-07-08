#include <Servo.h>
#include <EEPROM.h>

Servo left, right;

const int reciPIN = 2;
const int ledPIN = 3;

const int whiskPIN = 4;
const int verifyCompleteLED = 13;

void setup() {
  left.attach(10, 1300, 1700);// left wheel
  right.attach(11, 1300, 1700);// right wheel

  pinMode(reciPIN, INPUT); // Infrared Reciver
  pinMode(ledPIN, OUTPUT); // Infrared LED
    
  pinMode(whiskPIN,INPUT); // whisker
  
  pinMode(verifyCompleteLED,OUTPUT); // LED to tell me bpfVerify(); is finished
  delay(10000);
  
  bpfVerify();
}

void bpfVerify(){

  int c = 0;
  int address = 1;
  for (long freq = 34000; freq <= 42000; freq += 1000) {
      for (int meas = 1; meas <= 3; meas += 1) {
        moveLine(200);
        while(digitalRead(whiskPIN) == 1){}//delay until whisker touches wall
        moveLine(0);
        delay(200);

        moveLine(-200);
        while(digitalRead(whiskPIN) == 0){}//delay until whisker stops touching wall
        moveLine(0);
        delay(200);
      
        unsigned long start = millis();
        moveLine(-200);
        while(irDetect(ledPIN, reciPIN, freq, 8) == 0){}// delay until wall can't be seen
        delay(500);
        unsigned long fin = millis();
        unsigned long diff = fin - start;
        
        unsigned long high = (unsigned long)(diff / 256);
        unsigned long low = (unsigned long)(diff % 256);
        
        EEPROM.write(address, high); 
        address++;
        EEPROM.write(address, low);
        address++;

        c++;
      }
    }
     EEPROM.write(0, c);
}

void loop() {
  digitalWrite(verifyCompleteLED, HIGH);
}
  
int irDetect(int irLedPin, int irReceiverPin, long frequency, int toneTime)
{
  tone(irLedPin, frequency, toneTime); // modulate IR LED at specified frequency for at least 1 ms
  delay(1); // Wait 1 ms
  int ir = digitalRead(irReceiverPin); // IR receiver -> ir variable
  delay(1); // Down time before recheck
  return ir; // Return 1 no detect, 0 detect
}

void moveLine(int spd){
  drive(spd, spd);
}

void drive(int leftpw, int rightpw){
  left.writeMicroseconds(1500 + leftpw);
  right.writeMicroseconds(1500 - rightpw);
}
