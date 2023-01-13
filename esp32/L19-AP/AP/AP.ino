#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

void setup() {
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  
  Serial.begin(115200);
  delay(2000);
  Serial.println("AP Server");

  WiFi.softAP("esp32wifi", "123Stella");
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(1000);

  server.on("/", pageIndex);
  server.on("/home", pageIndex);
  server.on("/on", ledOn);
  server.on("/off", ledOff);
  server.onNotFound(pageError);

  server.begin();
}

void loop() {
  server.handleClient();
  delay(2);
}

void pageIndex() {
  String str = "Hello Web Server ESP32\n";
  str += "URI: ";
  str += server.uri();
  str += " ARGS: ";
  str += server.args();
  str += "\n";

  for (int i = 0; i < server.args(); i++) {
    str += server.argName(i);
    str += "=";
    str += server.arg(i);
    str += "\n";
  }
  
  server.send(200, "text/plain", str);  
}
void ledOn() {
  digitalWrite(5, HIGH);    
  server.send(200, "text/plain", "OK");  
}
void ledOff() {
  digitalWrite(5, LOW);  
  server.send(200, "text/plain", "OK");  
}

void pageError() {
  String str = "Pagina non trovata\n";  
  server.send(404, "text/plain", str);    
}
