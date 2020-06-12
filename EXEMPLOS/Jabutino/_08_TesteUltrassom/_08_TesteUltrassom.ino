//Pinos para controle do Ultrassom HC-SR04
const int pinoTrigger = 14; //Trigger
const int pinoEcho = 15; //Echo

void setup(){
    //inicia a comunicação serial
    Serial.begin (9600);
    //atribui os pinos do ultrassom
    pinMode(pinoTrigger, OUTPUT); //Trigger é saída
    pinMode(pinoEcho, INPUT); //Echo é entrada
}

void loop(){
    
    //Garante que o pino de Trigger está LOW
    digitalWrite(pinoTrigger, LOW); 
    delayMicroseconds(2);
    
    //cria um pulso de 5 microssegundos no Trigger
    digitalWrite(pinoTrigger, HIGH); //primeiro ativa o sinal
    delayMicroseconds(5); //aguarda um curto período de tempo
    digitalWrite(pinoTrigger, LOW); //depois interrompe o sinal
  
    //aguarda o retorno do eco
    //o tempo é retornado em microssegundos = 0,000001s
    long tempoTotal = pulseIn(pinoEcho, HIGH); 
    
    //transforma o tempo de ida e volta em distancia
    //convertida para cm/microssegundo e
    //divide a distancia total por 2 para ter a medida correta
    float distObstaculo = 0.0343 * tempoTotal / 2;

    //imprime a distância lida no terminal serial
    Serial.print("Distancia: ");
    Serial.print(distObstaculo);
    Serial.println("cm");
    
    delay(500); //aguarda meio segundo para repetir
}
