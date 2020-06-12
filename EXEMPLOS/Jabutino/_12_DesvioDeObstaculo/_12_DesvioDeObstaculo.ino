//**************************************************************************
//**************************************************************************
//**
//**  Código fonte desenvolvido pela Jabuti Robótica
//**  A reprodução sem a devida autorização é proibida
//**  Salvador, Bahia, 2012
//**
//**  http://jabuti.cc
//**  contato@jabuti.cc
//**
//**
//**   05/09/2012 Programa desenvolvido por Guilherme Levita
//**
//**************************************************************************
//**************************************************************************

#include <Servo.h>
#include <AFMotor.h>  // Biblioteca para a PONTE-H da Ada Fruit

//Instancia o objeto referente aos motores DC
AF_DCMotor motorEsquerdo(1); //Motor esquerdo na conexão "M1"
AF_DCMotor motorDireito(2); //Motor direito na conexão "M2"

//Definições de velocidade em PWM de 0 a 255
const char VELOCIDADE_MAXIMA = 255;

//Pinos para controle do Ultrassom HC-SR04
//usar as portas analógicas A0 e A1 como digitais
const int pinoTrigger = 14; // A0 = 14
const int pinoEcho = 15; // A1 = 15

//Servo Motor
Servo _meuServo;
const int pinoSinalServo = 9; //o pino 9 é o pino de sinal da conexão "SERVO_2"

//Define as posicoes de calibragem do servo
//Valores para conseguir um melhor alinhamento do servo, cada motor responde de forma diferente.
//Os valores devem variar de 0 a 180 graus, ajuste de acordo com seu motor na tentativa e erro.
const int ESQUERDA = 180;
const int DIREITA = 0;
const int FRENTE = 90;

//Método obrigatório
//Realiza as definições dos pinos e faz a inicialização da biblioteca de servo.
void setup(void)
{
  // Inicializa os motores com velocidade máxima
  motorEsquerdo.setSpeed(VELOCIDADE_MAXIMA);
  motorDireito.setSpeed(VELOCIDADE_MAXIMA);
  
  //atribui os pinos do ultrassom
  pinMode(pinoTrigger, OUTPUT);
  pinMode(pinoEcho, INPUT);

  //inicia o Servo
  _meuServo.attach(pinoSinalServo);
  //Coloca o servo virado para posicao frontal
  _meuServo.write(POSICAO_FRENTE);
}


//Corpo principal do programa, repete infinitamente
void loop(void)
{
  //Iicia andando para frente
  andarParaFrente(VELOCIDADE_MAXIMA);

  //Enquanto não encontrar um obstáculo a menos de 10 centímetros
  while(calcularDistancia() > 10)
  {
    delay(100);  //Faz uma leitura da distancia a cada 0,1 segundo
  }

  //Se encontrou um obstáculo recua por 1 segundo e pára
  andarParaTras(VELOCIDADE_MEDIANA);
  delay(1000);
  pararMotores();

  //Verifica qual lado tem maior distância até um obstáculo
  int _esquerda = 0, _direita = 0;

  _meuServo.write(POSICAO_ESQUERDA); //vira o servo para a esquerda
  delay(500); //aguarda o servo completar o movimento
  _esquerda = calcularDistancia(); //mede a distancia na esquerda

  _meuServo.write(POSICAO_DIREITA); //vira o servo para a direita
  delay(500); //aguarda o servo completar o movimento
  _direita = calcularDistancia(); //mede a distancia na direita

  _meuServo.write(POSICAO_FRENTE); //olha pra frente novamente
  delay(500); //aguarda o servo completar o movimento

  if(_esquerda > _direita)
  { //se a distancia do obstáculo na esquerda for maior que na direita
    //vira para esquerda
    girarParaEsquerda(VELOCIDADE_MAXIMA);
  }
  else
  { // se a distancia do obstaculo na direita for maior ou igual que na esquerda
    //vira para a direita
    girarParaDireita(VELOCIDADE_MAXIMA);
  }
  //Aguarda alguns instantes para o robô virar
  delay(500); //<< modifique esse tempo se desejar que ele vire por mais ou menos tempo
}

boolean verificarObstaculo(int distancia)
{
  if medirDistancia() > distancia
  {
    return false
  }
  else
  {
    return true
  }
}

//Utiliza o sensor de Ultrassom HC-SR04 para medir a distancia em centímetros
int medirDistancia()
{
  //Garante que o pino de Trigger está LOW
  digitalWrite(pinoTrigger, LOW);
  delayMicroseconds(2);

  //cria um pulso de 5 microssegundos no Trigger
  digitalWrite(pinoTrigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(pinoTrigger, LOW);

  //aguarda o echo
  long microssegundos = pulseIn(pinoEcho, HIGH);

  // A velocidade do som é 340 m/s ou aproximadamente 29 microssegundos por centimetro.
  // O pulso faz uma viagem de ida e volta do sensor até o obstáculo
  // assim, para calcular a distancia temos que dividir esse tempo pela metade
  // desta forma...
  return int(microssegundos / 29 / 2);
}

//Gira as duas rodas para frente
//Como os motores estão virados para lados opostos eles devem
//girar em sentidos opostos para que as rodas girem na mesma direção
void andarParaFrente()
{
  motorEsquerdo.run(FORWARD);
  motorDireito.run(BACKWARD);
}

//Gira as duas rodas para trás
//Como os motores estão virados para lados opostos eles devem
//girar em sentidos opostos para que as rodas girem na mesma direção
void andarParaTras(char velocidade)
{
  motorEsquerdo.run(BACKWARD);
  motorDireito.run(FORWARD);
}

//Gira as duas rodas em sentido inverso, girando no próprio eixo
void girarParaEsquerda (char velocidade)
{
  motorEsquerdo.run(BACKWARD);
  motorDireito.run(BACKWARD);
}

//Gira as duas rodas em sentido inverso, girando no próprio eixo
void girarParaDireita(char velocidade)
{
  motorEsquerdo.run(FORWARD);
  motorDireito.run(FORWARD);
}

//Pára os motores definindo os dois pinos Enable em estado Low
void pararMotores()
{
  motorEsquerdo.run(RELEASE);
  motorDireito.run(RELEASE);
}
