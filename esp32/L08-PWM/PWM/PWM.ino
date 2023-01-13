void setup() {
  int ch = 0;
  int freq = 1000;
  int res = 8;
  ledcSetup(ch, freq, res);

  int ch2 = 1;
  int freq2 = 3000;
  int res2 = 8;
  ledcSetup(ch2, freq2, res2);

  int pin1 = 4;
  ledcAttachPin(pin1, ch);

  int pin2 = 5;
  ledcAttachPin(pin2, ch2);
  ledcWrite(1, 10);
}

void loop() {
  for (int i = 0; i < 256; i++) {
    ledcWrite(0, i);
    delay(5);  
  }
  for (int i = 255; i >= 0; i--) {
    ledcWrite(0, i);
    delay(5);  
  }

}
