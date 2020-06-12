//Faz a referência obrigatória à biblioteca Servo.h
#include <Servo.h>

//Define um objeto para referenciar o servomotor
Servo meuServo;

void setup() {
    meuServo.attach(9); //define o servomotor no pino 10
    Serial.begin(9600); //inicia a comunicação serial
}

void loop() {
    if (Serial.available() > 0){ //se existem dados disponíveis
        int angulo = Serial.parseInt(); //transforma em número
        meuServo.write(angulo); //posiciona o eixo no angulo
        delay(500); //aguarda o servomotor completar o movimento
        Serial.find("\n"); //termina de ler o buffer
    }
}
