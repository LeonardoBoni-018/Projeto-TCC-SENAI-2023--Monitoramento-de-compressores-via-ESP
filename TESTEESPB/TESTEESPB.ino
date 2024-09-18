#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* ssid = "Bessegatto";
const char* password = "senaiteste";
IPAddress ip(192, 168, 1, 101);  // Endereço IP fixo da Placa 2
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
const char* serverIP = "192.168.1.100";  // Substitua pelo IP do servidor

void setup() {
    Serial.begin(9600);
    delay(10);
    WiFi.begin(ssid, password);

    // Configurar o IP fixo
    WiFi.config(ip, gateway, subnet);
}

void loop() {
    WiFiClient client;
    if (client.connect(serverIP, 80)) {
        // Enviar uma mensagem para o servidor
        client.println("A");
    }
    else{
      client.println("B");
      Serial.write("B");
    }
}
