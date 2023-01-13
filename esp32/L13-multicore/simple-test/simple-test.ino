void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("multicore");
  Serial.print("core: ");
  Serial.println(xPortGetCoreID());

}

void loop() {
  // put your main code here, to run repeatedly:

}
