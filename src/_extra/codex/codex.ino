const int LEDPIN = 12;
const int SPEAKPIN = 5;
void setup() {
  // Serial.begin(9600);
  pinMode(LEDPIN,OUTPUT);
  digitalWrite(LEDPIN,HIGH);
  tone(SPEAKPIN, 0, 8);
}

void loop() {
  delay(500);
  digitalWrite(LEDPIN,LOW);
  tone(SPEAKPIN, 0, 8);
  
  delay(500);
  digitalWrite(LEDPIN,HIGH);
  tone(SPEAKPIN, 500, 8);
}
