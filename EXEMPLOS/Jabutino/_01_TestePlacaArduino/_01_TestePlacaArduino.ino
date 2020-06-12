/*
  Liga o LED presente na placa por um segundo,
  em seguida desliga ele por mais um segundo e repete.
 */
 
// O Pino 13 est� diretamente conectado a um LED
// na maioria das placas Arduino.
int led = 13;

// a rotina "setup" executa apenas uma vez sempre que a placa � reiniciada:
void setup() {                
  // indica que o pino � uma sa�da.
  pinMode(led, OUTPUT);
}

// a rotina "loop" executa infinitamente:
void loop() {
  digitalWrite(led, HIGH);   // Liga o LED (HIGH � o n�vel de tens�o)
  delay(1000);               // aguarda 1 segundo
  digitalWrite(led, LOW);    // desliga o LED colocando o n�vel de tens�o LOW
  delay(1000);               // aguarda 1 segundo
}
