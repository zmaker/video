/**
 * RTX
 */
#include <WiFi.h>
#include <esp_now.h>

#define BOARD 1
#if BOARD == 1
uint8_t rxaddr[] = {0x58, 0xBF, 0x25, 0x93, 0x27, 0x48};
#endif
#if BOARD == 2
uint8_t rxaddr[] = {0x3C, 0x71, 0xBF, 0xFD, 0x80, 0x20};
#endif

esp_now_peer_info_t peerinfo;

struct message {
  char msg[30];
  int n;
  float temp;
  bool led;
} myData;

void onDataSend(const uint8_t *mac_addr, esp_now_send_status_t status);
void onDataRecv(const uint8_t *mac_addr, const uint8_t *dati, int len);

unsigned long t1, tmax;

void setup() {
  pinMode(4, OUTPUT);
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

  esp_now_register_recv_cb(onDataRecv);

  myData.led = LOW;
  #if BOARD == 1
  tmax = 2000;
  strcpy(myData.msg, "1 -> 2");
  #endif
  #if BOARD == 2
  tmax = 3000;
  strcpy(myData.msg, "2 -> 1");
  #endif
  
}

void loop() {
  if ((millis() - t1) > tmax) {
    myData.n++;
    myData.temp = 12.3;
    myData.led = !myData.led;

    esp_err_t ret = esp_now_send(rxaddr, (uint8_t *) &myData, sizeof(myData));
    if (ret == ESP_OK) {
      Serial.println("TX ok");
    } else {
      Serial.println("TX KO");
    }
    t1 = millis();
  }
}

void onDataSend(const uint8_t *mac_addr, esp_now_send_status_t status){
  Serial.println("TX callback");
  if (status == ESP_NOW_SEND_SUCCESS) {
    Serial.println("Dato ricevuto");
  } else {
    Serial.println("Dato non ricevuto");
  }
}

void onDataRecv(const uint8_t *mac_addr, const uint8_t *dati, int len){
  memcpy(&myData, dati, sizeof(myData));
  Serial.print("bytes: ");Serial.println(len);
  Serial.print("msg: ");Serial.println(myData.msg);
  Serial.print("n: ");Serial.println(myData.n);
  Serial.print("temp: ");Serial.println(myData.temp);
  digitalWrite(4, myData.led);
}
