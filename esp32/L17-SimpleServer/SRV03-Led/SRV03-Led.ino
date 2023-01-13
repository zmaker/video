#include <WiFi.h>
#include "parametri.h"

WiFiServer server(80);

void setup() {
  pinMode(5, OUTPUT);
  
  Serial.begin(115200);
  delay(2000);
  Serial.println("Simple Server");

  WiFi.disconnect(true);  
  WiFi.mode(WIFI_STA);
  WiFi.begin(MY_WIFI_SSID, MY_WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\n");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("new req");
    String line = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        //Serial.print(c);  
        if (c == '\n') {

          if (line.indexOf("GET /ledon") >= 0) {
            digitalWrite(5, HIGH);  
          }
          if (line.indexOf("GET /ledoff") >= 0) {
            digitalWrite(5, LOW);  
          }
          
          if (line.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("");
            client.println("<html>");
            client.println("<head><title>Hello LED ESP32</title>");
            client.println("</head>");            
            client.println("<body>");
            client.println("<h1>Hello ESP32</h1>");
            client.println("<p>LED:");
            int v = digitalRead(5);
            client.println(v);
            client.println("</p>");
            client.println("<a href='http://192.168.1.106/ledon'>ON</a>");
            client.println("</body>");
            client.println("</html>");
            break;
          }
          line = "";
          
        } else if (c != '\r') {          
          line += c;
        }
        
      }
    }
    client.stop();
    Serial.println("client scollegato");
  }
}
