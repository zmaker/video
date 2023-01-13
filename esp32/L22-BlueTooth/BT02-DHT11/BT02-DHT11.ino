#include "BluetoothSerial.h"
#include <SimpleDHT.h>

BluetoothSerial bt;

SimpleDHT11 dht11(15);

unsigned long t1;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("BT DHT11");

  bt.begin("ESP32-Bt");

}

void loop() {
  if ((millis()-t1) > 3000) {
     byte temp = 0;
     byte hum = 0;
     dht11.read(&temp, &hum, NULL);
     String msg = "t: " + String(temp) + "C h:" + String(hum) + "%";
     bt.println(msg);
     t1 = millis();  
  }
}
