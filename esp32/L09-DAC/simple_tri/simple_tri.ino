void setup() {
  // put your setup code here, to run once:

}

void loop() {
  for (int i = 0; i < 256; i++) {
    dacWrite(25, i);
    delay(1);
  }
  for (int i = 255; i >= 0; i--) {
    dacWrite(25, i);
    delay(1);
  }

}
