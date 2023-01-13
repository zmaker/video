TaskHandle_t t1;
TaskHandle_t t2;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("multicore");
  Serial.print("core: ");
  Serial.println(xPortGetCoreID());

  xTaskCreatePinnedToCore(loop1, "loop1", 10000, NULL, 1, &t1, 0);
  xTaskCreatePinnedToCore(loop2, "loop2", 10000, NULL, 1, &t2, 1);
}

void loop() {}

void loop1(void * vParameters) {
  Serial.print("LOOP1 in esecuzione su..");  
  Serial.println(xPortGetCoreID());

  pinMode(15, OUTPUT);
  while(true) {
    digitalWrite(15, HIGH);
    delay(500);
    digitalWrite(15, LOW);
    delay(500);
  }
}

void loop2(void * vParameters) {
  Serial.print("LOOP2 in esecuzione su..");  
  Serial.println(xPortGetCoreID());

  pinMode(16, OUTPUT);
  while(true) {
    digitalWrite(16, HIGH);
    delay(100);
    digitalWrite(16, LOW);
    delay(500);
  }
}
