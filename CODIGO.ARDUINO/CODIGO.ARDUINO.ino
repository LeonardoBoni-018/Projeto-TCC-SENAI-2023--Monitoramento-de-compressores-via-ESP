int led=13;

void setup() {
  // Inicializa a comunicação serial com a velocidade 9600 bps
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(led, OUTPUT); // Configura o pino 13 como saída para o LED
}

void loop() {
  if (Serial1.available()) {
    char receivedChar = Serial1.read();
    if (receivedChar == "A") {
      digitalWrite(led, HIGH);
      
    } 
   else{
      digitalWrite(led,LOW);
      delay(1000);
      digitalWrite(led, HIGH);
      delay(1000);
    }
  }
}
