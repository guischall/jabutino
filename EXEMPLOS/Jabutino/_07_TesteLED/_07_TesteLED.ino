int pinoLED = 14; //define o LED no pino digital 14
//OBS: O pino digital 14 é o mesmo pino analogico A0

void setup() {
    pinMode(pinoLED, OUTPUT); //atribui o pino como saída
}

void loop() {
    digitalWrite(pinoLED, HIGH); //liga o LED (HIGH)
    delay(1000);                 //aguarda 1 segundo
    digitalWrite(pinoLED, LOW);  //desliga o LED
    delay(1000);                 //aguarda 1 segundo
}
