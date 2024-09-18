#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "Bessegatto";
const char *password = "senaiteste";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

   Serial.println(WiFi.localIP());
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/plain", "Olá, ESP-01!");
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
