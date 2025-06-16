#define RELE 7
bool bomba_activada = false;
unsigned long tiempo_inicio = 0;

void setup() {
  pinMode(RELE, OUTPUT);
  digitalWrite(RELE, HIGH);  // Lógica inversa: HIGH = apagado
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char comando = Serial.read();

    if (comando == '1' && !bomba_activada) {
      digitalWrite(RELE, LOW);  // Lógica inversa: LOW = encendido
      tiempo_inicio = millis();
      bomba_activada = true;
    }
  }

  // Apagar la bomba después de 5 segundos
  if (bomba_activada && (millis() - tiempo_inicio >= 5000)) {
    digitalWrite(RELE, HIGH);  // Lógica inversa: HIGH = apagado
    bomba_activada = false;
  }
}
