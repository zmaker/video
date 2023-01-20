#include "WiFi.h"

void setup() {
  Serial.begin(115200);
  delay(2000);
  WiFi.mode(WIFI_MODE_STA);
  Serial.println(WiFi.macAddress());

}

void loop() {
  // put your main code here, to run repeatedly:

}
