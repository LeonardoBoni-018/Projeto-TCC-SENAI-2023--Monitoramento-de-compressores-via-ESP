#include <ESP8266WiFi.h>

const char* ssid = "Bessegatto";
const char* password = "senaiteste";
const int serverPort = 80;

WiFiServer server(serverPort);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  
  Serial.println("Conectado ao WiFi");
  
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  
  if (client) {
    Serial.println("Cliente conectado");
    
    while (client.connected()) {
      if (client.available()) {
        String request = client.readStringUntil('\r');
        Serial.println(request);
        
        // Verifique se o comando foi recebido
        if (request.indexOf("POST /comando") != -1) {
          // O comando está presente na solicitação
          // Você pode adicionar lógica para processar o comando aqui
          
          // Enviar uma resposta ao cliente
          String response = "Comando recebido e processado.";
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/plain");
          client.println("Connection: close");
          client.println();
          client.println(response);
          client.println();
          Serial.write("A"); // Escreva "A" na porta serial
          break; // Encerra a conexão após processar o comando
        }
        else{
          Serial.write("B");
        }
      }
    }
    
    client.stop();
    Serial.println("Cliente desconectado");
  }
}
