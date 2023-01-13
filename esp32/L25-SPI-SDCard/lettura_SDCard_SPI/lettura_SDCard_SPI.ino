#include <SPI.h>
#include "SD.h"
#include "FS.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Test SPI SDCard");

  if (!SD.begin(5)) {
    Serial.println("Errore SD");
    while(1);
  }
  Serial.println("SD: ok");

  File f = SD.open("/test.txt", FILE_WRITE);
  if (f) {
    Serial.println("SD: writing...");
    f.print("lettura sensore: ");
    int v = analogRead(34);
    f.println(v);
    f.close();
    Serial.println("SD: write ok");
  } else {
    Serial.println("Errore apertura file");
  }

  f = SD.open("/test.txt", FILE_READ);
  if (f) {
    Serial.println("\nSD: reading...");
    while (f.available()) {
      Serial.write(f.read());  
    }
    f.close();
    Serial.println("SD: read ok");
  } else {
    Serial.println("Errore apertura file");
  }
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
