const int PIN1L = 2;
const int PIN2R = 4;

void setup() {
  Serial.begin(9600);
  pinMode(PIN1L,INPUT);
  pinMode(PIN2R,INPUT);
}

void loop() {
  int l = digitalRead(PIN1L);
  int r = digitalRead(PIN2R);

  int all = l * 10 + r;
  // 0, 1, 10, 11
  if(all == 11){
    Serial.println("none");
  }
  else if(all == 10){
    Serial.println("right");
  }
  else if(all == 1){
    Serial.println("left");
  }
  else{
    Serial.println("both");
  }
  delay(100);
}
