void setup() {
  // Inicializa a comunicação serial com a velocidade 9600 bps
  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(13, OUTPUT); // Configura o pino 13 como saída para o LED
}

void loop() {
  if (Serial1.available()) {
    char receivedChar = Serial1.read();
    if (receivedChar == "H") {
      Serial.print("UMIDADE:");
      Serial.println("%");
      Serial.print(DHT.humidity);//mostra os dados de umidade do cliente
      digitalWrite(13, HIGH); // Acende o LED

    } else if (receivedChar == "T") {
      Serial.print("TEMPERATURA:");
      Serial.print(DHT.temperature, 0);//mostra os dados de temperatura do cliente
      Serial.println("*C");
      digitalWrite(13, HIGH); // Acende o LED
    }
    else if(receivedChar == "E") {
      Serial.println("Erro ao ler resposta do cliente!");
      digitalWrite(13, LOW);
      delay(1500);
      digitalWrite(13, HIGH);
      delay(1500);
      digitalWrite(13, LOW);
      delay(1500);
      digitalWrite(13, HIGH);
      delay(1500);
      digitalWrite(13, LOW);
      delay(1500);
    }
  }
}
