#include <WiFi.h>
#include <WiFiMulti.h>
#include "parametri.h"

WiFiMulti wifimulti;
unsigned long t1;

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("WiFi Multi test");
  
  //WiFi.disconnect(true);

  wifimulti.addAP(MY_WIFI1_SSID, MY_WIFI1_PASS);
  wifimulti.addAP(MY_WIFI2_SSID, MY_WIFI2_PASS);

  WiFi.mode(WIFI_STA);

  while (wifimulti.run() != WL_CONNECTED) {
    Serial.print(".");    
    delay(1000);    
  }

  Serial.print("\n");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  t1 = millis();
}

void loop() {
  if (wifimulti.run(5000) == WL_CONNECTED) {
    Serial.print(WiFi.SSID());
    Serial.print(" pot: ");
    Serial.println(WiFi.RSSI());
  } else {
    Serial.println("non connesso");  
  }
  delay(1000);
}
