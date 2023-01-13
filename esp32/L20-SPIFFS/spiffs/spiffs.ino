// https://github.com/me-no-dev/arduino-esp32fs-plugin/releases/

#include "SPIFFS.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("spiffs test");

  if (!SPIFFS.begin(true)) {
    Serial.println("spiffs error");
    while(1);
  }

  File file = SPIFFS.open("/test.txt");
  if (file) {
    while (file.available()) {
      Serial.write(file.read());  
    }
    file.close();
  } else {
    Serial.println("file non trovato");   
  }

  //test scrittura
  file = SPIFFS.open("/test.txt", "a"); //"w" sostituisce
  if (file) {
    file.println("test scrittura"); 
    file.close(); 
  } else {
    Serial.println("file non trovato 2");   
  }

  file = SPIFFS.open("/test.txt");
  if (file) {
    while (file.available()) {
      Serial.write(file.read());  
    }
    file.close();
  } else {
    Serial.println("file non trovato");   
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
