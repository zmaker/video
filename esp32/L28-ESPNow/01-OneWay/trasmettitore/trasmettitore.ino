/**
 * TX
 */
#include <WiFi.h>
#include <esp_now.h>

uint8_t rxaddr[] = {0x58, 0xBF, 0x25, 0x93, 0x27, 0x48};

esp_now_peer_info_t peerinfo;

struct message {
  char msg[30];
  int n;
  float temp;
  bool led;
} myData;

void onDataSend(const uint8_t *mac_addr, esp_now_send_status_t status);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW KO");
    while(1);  
  }

  esp_now_register_send_cb(onDataSend);

  memcpy(peerinfo.peer_addr, rxaddr, 6);
  peerinfo.channel = 0;
  peerinfo.encrypt = false;
  if (esp_now_add_peer(&peerinfo) != ESP_OK) {
    Serial.println("ESP-NOW add peer ko");
    while(1); 
  }

  myData.led = LOW;
  strcpy(myData.msg, "hello world");
}

void loop() {
  myData.n++;
  myData.temp = 12.3;
  myData.led = !myData.led;

  esp_err_t ret = esp_now_send(rxaddr, (uint8_t *) &myData, sizeof(myData));
  if (ret == ESP_OK) {
    Serial.println("TX ok");
  } else {
    Serial.println("TX KO");
  }
  delay(2000);
}

void onDataSend(const uint8_t *mac_addr, esp_now_send_status_t status){
  Serial.println("TX callback");
  if (status == ESP_NOW_SEND_SUCCESS) {
    Serial.println("Dato ricevuto");
  } else {
    Serial.println("Dato non ricevuto");
  }
}
