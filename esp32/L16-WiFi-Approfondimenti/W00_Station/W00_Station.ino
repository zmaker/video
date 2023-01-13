#include <WiFi.h>
#include "parametri.h"

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("WiFi test");

  WiFi.mode(WIFI_STA);
  //WiFi.mode(WIFI_AP);
  //WiFi.mode(WIFI_STA_AP);

  WiFi.begin(MY_WIFI_SSID, MY_WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\n");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  delay(2000);
  WiFi.disconnect();
  Serial.println("scollegato");

  delay(2000);
  Serial.println("collegamento 2");
  WiFi.begin(MY_WIFI_SSID, MY_WIFI_PASS);
  
  delay(5000);  
  WiFi.disconnect();
  Serial.println("scollegato 2");

  delay(2000);
  WiFi.reconnect();
  Serial.println("collegamento 3");

  delay(5000);  
  WiFi.disconnect();
  Serial.println("scollegato 3");
}

void loop() {
  // put your main code here, to run repeatedly:

}
