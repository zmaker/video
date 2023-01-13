/*
 * PIN:  4 ,2, 15, 13, 12, 14, 27, 32, 33 (solo per arduino IDE)
 * Touch:0, 2,  3,  4,  5,  6,  7,  8,  9
 * 
 * PIN gpio 0 = touch 1: non accessibile
 * 
 */
int valmedio = 0;
int soglia = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Touch test");
  
  pinMode(4, OUTPUT);

  for (int i = 0; i < 10; i++) {
   valmedio += touchRead(2);  
  }
  valmedio = valmedio / 10;
  soglia = (int)((float)valmedio * 0.85);
  Serial.print("vmedio: ");Serial.println(valmedio);
  Serial.print("soglia: ");Serial.println(soglia);
}

void loop() {
  int v = touchRead(2);
  if (v < soglia) {
    digitalWrite(4, HIGH);  
  } else {
    digitalWrite(4, LOW);    
  }
}
