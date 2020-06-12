// faz referência à biblioteca
#include <QTRSensors.h>

// define os parâmetros do sensor
#define NUMERO_SENSORES          6  // número de sensores da placa
#define NUM_AMOSTRAS_POR_SENSOR  4  // média de 4 amostras analógicas em cada leitura
#define PINO_EMISSOR             10 // pino LEDON, para economizar energia

// cria um objeto, com todos os parametros
// para representar sua placa de sensores
QTRSensorsAnalog placaRefletancia
  (
    (unsigned char[]) {A0, A1, A2, A3, A4, A5}, // ver comentário abaixo
    NUMERO_SENSORES,
    NUM_AMOSTRAS_POR_SENSOR,
    PINO_EMISSOR
  );

/*
 para definir os pinos analógicos em que cada sensor da placa será conectado
 usar: (unsigned char[]) {A0, A1, A2, A3, A4, A5}
 sendo que sensor 1 = "A0", sensor 2 = "A1", ..., sensor 6 = "A5"
 
 maiores informações podem ser encontradas aqui:
 http://www.pololu.com/docs/0J12/all
*/ 

// cria um vetor para armazenar os valores lidos por cada sensor da placa
unsigned int leituras[NUMERO_SENSORES];

void setup()
{
  // inicia a comunicação serial para exibir as leituras no computador
  Serial.begin(9600);
  Serial.println("Calibrando...");
  
  // faz a calibração dos sensores
  for (int i = 0; i < 250; i++) // a calibração vai durar uns 5 segundos
  {
    // executa o comando de calibragem da placa
    placaRefletancia.calibrate(QTR_EMITTERS_ON);
    // aguarda um pouco para repetir
    delay(20);
  }   
  
  Serial.println("Calibragem concluida.");
}

void loop()
{
  // executa uma leitura de linha
  int posicao = placaRefletancia.readLine(leituras, QTR_EMITTERS_ON, false);
  
  // imprime os valores lidos
  // formato --> "POSICAO = [valor 1] [valor 2] [valor 3] [valor 4] [valor 5] [valor 6]
  Serial.print(posicao);
  Serial.print(" = ");
  for (int i = 0; i <= 5; i++)
  {
    Serial.print("[");
    Serial.print(leituras[i]);
    Serial.print("] ");
  }
  Serial.println();
  
  // aguarda meio segundo para repetir a leitura
  delay(500);
}
