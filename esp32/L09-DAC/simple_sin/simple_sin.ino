int sinusoide[256];

void setup() {
  Serial.begin(115200);
  delay(1000);

  float passo = (2.0 * PI) / 256.0;
  for (int i = 0; i < 256; i++) {
    float angolo = passo * (float)i;
    //Serial.println(angolo);  
    float val = (sin(angolo) * 127.0) + 128.0;
    sinusoide[i] = val;
    //Serial.println(val);  
  }

}

void loop() {
  for (int i = 0; i < 256; i++) {
    dacWrite(25, sinusoide[i]);
    delay(1); 
  }
}
