void setup() {
  Serial.begin(9600);
}

void loop() {
  int vR = analogRead(A1);
  int vL = analogRead(A0);
  delay(500);
  Serial.print("Left: ");
  Serial.println(map(vL,0,1023,0,200));
  Serial.print("Right: ");
  Serial.println(map(vR,0,1023,0,200));
}
