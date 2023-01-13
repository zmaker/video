void setup() {
  pinMode(5, OUTPUT);

}

void loop() {
  digitalWrite(5, HIGH);
  delay(300);
  digitalWrite(5, LOW);
  delay(300);
}
