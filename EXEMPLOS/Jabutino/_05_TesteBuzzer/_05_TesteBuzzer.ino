//define o pino em que o buzzer está conectado
int pinoBuzzer = 9;

void setup() {
  //não é necessário código de inicialização
}

void loop() {
    tone(pinoBuzzer, 440); //envia um sinal de 440Hz para o pino 9
    delay(100);            //aguarda 0,1 segundo
    noTone(pinoBuzzer);    //interrompe o som no pino 9
    delay(1000);           //aguarda 1 segundo
}

