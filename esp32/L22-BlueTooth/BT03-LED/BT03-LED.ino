#include "BluetoothSerial.h"

BluetoothSerial bt;
String line = "";

void setup() {
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  
  Serial.begin(115200);
  delay(1000);
  Serial.println("BT LED");
  bt.begin("ESP32-Bt");
}

void loop() {
  if (bt.available()) {
    char ch = bt.read();
    if (ch == '\n') {
      Serial.print("cmd: ");
      Serial.println(line);
      if (line == "on"){
        digitalWrite(5, HIGH);
        Serial.println("LED ON");  
      } else if (line == "off"){
        digitalWrite(5, LOW);  
        Serial.println("LED OFF");  
      }
      line = "";  
    } else if (ch != '\r') {
      line += ch;
    } 
  }
}
