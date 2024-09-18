#include <ESP8266WiFi.h>

const char* ssid = "Bessegatto";
const char* password = "senaiteste";
const char* serverAddress = "172.20.10.2"; // Endereço IP da ESP Servidor
const int serverPort = 80;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  
  Serial.println("Conectado ao WiFi");
  
  enviarComandoParaServidor();
}

void loop() {
  // O loop pode ser deixado vazio ou usado para outras tarefas, se necessário
}

void enviarComandoParaServidor() {
  WiFiClient client;

  if (client.connect(serverAddress, serverPort)) {
    // Construa a solicitação HTTP POST com o comando
    String requestBody = "comando=ligar"; // Substitua "ligar" pelo comando desejado
    String request = "POST /comando HTTP/1.1\r\n";
    request += "Host: " + String(serverAddress) + "\r\n";
    request += "Content-Type: application/x-www-form-urlencoded\r\n";
    request += "Content-Length: " + String(requestBody.length()) + "\r\n\r\n";
    request += requestBody;

    // Envie a solicitação HTTP POST
    client.print(request);

    // Espere pela resposta do servidor (opcional)
    while (client.connected()) {
      if (client.available()) {
        String line = client.readStringUntil('\r');
        Serial.print(line);
      }
    }
    
    client.stop();
    Serial.println("Comando enviado para o servidor.");

    // Verifique se a conexão com o servidor está ativa após o envio do comando
    if (client.connected()) {
      Serial.println("Conectado ao servidor.");
      Serial.write("A");
    } else {
      Serial.println("Desconectado do servidor.");
    }
  } else {
    Serial.println("Falha na conexão com o servidor.");
    Serial.write("B");
  }
}
