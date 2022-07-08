const int pinNum = 4;

void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  // pm out
  //dw high
  // delay
  // pinmode input

  pinMode(pinNum, OUTPUT);
  digitalWrite(pinNum, HIGH);
  delay();
  pinMode(pinNum, INPUT)
}
