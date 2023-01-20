/**
 * RX
 */
#include <WiFi.h>
#include <esp_now.h>

struct message {
  char msg[30];
  int n;
  float temp;
  bool led;
} myData;

void onDataRecv(const uint8_t *mac_addr, const uint8_t *dati, int len);

void setup() {
  pinMode(4, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW KO");
    while(1);  
  }

  esp_now_register_recv_cb(onDataRecv);
}

void loop() {
 
}

void onDataRecv(const uint8_t *mac_addr, const uint8_t *dati, int len){
  memcpy(&myData, dati, sizeof(myData));
  Serial.print("bytes: ");Serial.println(len);
  Serial.print("msg: ");Serial.println(myData.msg);
  Serial.print("n: ");Serial.println(myData.n);
  Serial.print("temp: ");Serial.println(myData.temp);
  digitalWrite(4, myData.led);
}
