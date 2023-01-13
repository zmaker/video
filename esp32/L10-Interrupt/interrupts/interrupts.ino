int volatile count = 0;

unsigned long t1;

void IRAM_ATTR conteggio() {
  count++;
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("interrupt test");

  attachInterrupt(digitalPinToInterrupt(2), conteggio, RISING);
  t1 = millis();
}

void loop() {
  if ((millis() - t1) >= 3000) {  
    Serial.print("count: ");
    Serial.println(count);
    count = 0;
    t1 = millis();
  }
  
}
