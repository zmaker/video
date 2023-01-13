// https://github.com/Aircoookie/Espalexa
#include <Espalexa.h>
#include "secrets.h"
#include <WiFi.h>

Espalexa espalexa;

void lampChanged(uint8_t lum);

void setup() {
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  
  Serial.begin(115200);
  delay(1000);
  Serial.println("Simple Alexa LED");

  WiFi.disconnect(true);

  WiFi.begin(MY_WIFI_SSID, MY_WIFI_PASS);
  Serial.println("mi connetto...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  delay(1000);

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nconnesso");
    Serial.print("IP: ");Serial.println(WiFi.localIP());    
    espalexa.addDevice("espled", lampChanged);
    espalexa.begin();
  } else {
    Serial.println("\nnon connesso");
    while(1);
  }

}

void loop() {
  espalexa.loop();
  delay(1);
}

void lampChanged(uint8_t lum){
  Serial.print("l: ");
  Serial.println(lum);

  if (lum) {
    digitalWrite(5, HIGH);
    Serial.println("ON");
  } else {
    digitalWrite(5, LOW);
    Serial.println("OF");
  }
}
