/*
 Código original criado por Tom Igoe 

 Esse exemplo pode ser detalhado no link a seguir: 
 http://arduino.cc/en/Tutorial/Tone
 
 */
 
 //O Arquivo pitches.h possui todas as frequencias das notas musicais
 #include "pitches.h"

//Define as notas da melodia:
int melodia[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

//Define a duração das notas: 4 = 1/4, 8 = 1/8, etc.:
int duracoesNotas[] = { 4, 8, 8, 4, 4, 4, 4, 4 };

//Define o pino do Buzzer no pino 9
int pinoBuzzer = 9;

void setup() {
  //identifica automaticamente quantas notas existem na melodia
  int tamanhoMelodia = sizeof(melodia) / sizeof(int);
  //percorre as notas da melodia:
  for (int notaAtual = 0; notaAtual < tamanhoMelodia; notaAtual++) {
    /*
    para calcular a duração da nota
    vamos dividir 1 segundo pela duração da nota.
    1/4 = 1000 / 4, 1/8 = 1000/8, etc.
    */
    int duracao = 1000/duracoesNotas[notaAtual];
    tone(pinoBuzzer, melodia[notaAtual], duracao);

    /*
    para distinguir claramente o som das notas,
    vamos definir um pequeno intervalo entre elas
    a duração da nota mais 30% é um bom valor:
    */
    int pausaNotas = duracao * 1.20;
    delay(pausaNotas);
    
    // interrompe a melodia:
    noTone(pinoBuzzer);
  }
}

void loop() {
  //não repete a melodia.
}

/*
Você pode testar essa melodia abaixo :)
copie e cole por cima da outra definição de melodia (e duracao)

int melodia[] = { NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0, NOTE_G7, 0, 0, 0, NOTE_G6, 0, 0, 0, NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7, 0,NOTE_C7, NOTE_D7, NOTE_B6, 0, 0, NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7, 0,NOTE_C7, NOTE_D7, NOTE_B6, 0, 0 };
int duracoesNotas[] = { 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12 };
*/
