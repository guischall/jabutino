//**************************************************************************
//**************************************************************************
//**
//**  Código fonte desenvolvido pela Jabuti Robótica
//**  A reprodução sem a devida autorização é proibida
//**  Salvador, Bahia, 2012
//** 
//**  Data 03/02/2013  v1.5
//**
//**  http://jabuti.cc
//**  contato@jabuti.cc
//**
//**************************************************************************
//**************************************************************************

#include <QTRSensors.h>
#include <AFMotor.h>

#define VEL_MAXIMA 200
#define VEL_MEDIA 150
#define VEL_BAIXA 100

#define NUMERO_SENSORES          6  // número de sensores da placa
#define NUM_AMOSTRAS_POR_SENSOR  4  // média de 4 amostras analógicas em cada leitura
#define PINO_EMISSOR             10 // pino LEDON, para economizar energia

QTRSensorsAnalog placaRefletancia
  (
    (unsigned char[]) {A0, A1, A2, A3, A4, A5},
    NUMERO_SENSORES,
    NUM_AMOSTRAS_POR_SENSOR,
    PINO_EMISSOR
  );
  
int FAIXA_ERRO = 250;

AF_DCMotor motorEsquerda(1, MOTOR12_2KHZ);
AF_DCMotor motorDireita(2, MOTOR12_2KHZ);
  
void setup()
{
  //Calibra os sensores automaticamente
  //Motores girando em torno de si mesmo para passar pela faixa preta e áres clara
  motorEsquerda.setSpeed(VEL_MAXIMA);
  motorDireita.setSpeed(VEL_MAXIMA);
  motorEsquerda.run(FORWARD);
  motorDireita.run(BACKWARD);
  
  for (int i = 0; i < 250; i++) // Aproximadamente 3 a 4 segundos de calibração
  {
    placaRefletancia.calibrate();
    delay(20);
  } 
}
 
void loop()
{
  unsigned int valores[NUMERO_SENSORES];
  int posicao = placaRefletancia.readLine(valores) - 2500;

  if((posicao >= -FAIXA_ERRO) && (posicao <= FAIXA_ERRO)) 
  {
    //PRA FRENTE
    moverPraFrente();
  }
  else if(posicao < -FAIXA_ERRO)
  {
    //CORRIGE DIREITA
    corrigaDireita(posicao);
  }
  else if(posicao > FAIXA_ERRO)
  {
    //CORRIGE ESQUERDA
    corrigeEsquerda(posicao);
  }
  
  delay(20);
}

void moverPraFrente()
{
  motorEsquerda.setSpeed(VEL_MAXIMA);
  motorDireita.setSpeed(VEL_MAXIMA);
  motorEsquerda.run(FORWARD);
  motorDireita.run(FORWARD);
}

void corrigeEsquerda(int posicao)
{
  motorDireita.setSpeed(VEL_MAXIMA);
  motorDireita.run(FORWARD);
  
  if(posicao <= 500 + FAIXA_ERRO)
  {
    motorEsquerda.setSpeed(VEL_MEDIA);
    motorEsquerda.run(FORWARD);
  }
  else if(posicao <= 1000 + FAIXA_ERRO)
  {
    motorEsquerda.setSpeed(VEL_BAIXA);
    motorEsquerda.run(FORWARD);
  }
  else if(posicao <= 2500 + FAIXA_ERRO)
  {
    motorEsquerda.setSpeed(VEL_MAXIMA);
    motorEsquerda.run(BACKWARD);
  }
}

void corrigaDireita(int posicao)
{
  motorEsquerda.setSpeed(VEL_MAXIMA);
  motorEsquerda.run(FORWARD);
  
  posicao *= -1; //torna o valor positivo
  
  if(posicao <= 500 + FAIXA_ERRO)
  {
    motorDireita.setSpeed(VEL_MEDIA);
    motorDireita.run(FORWARD);
  }
  else if(posicao <= 1000 + FAIXA_ERRO)
  {
    motorDireita.setSpeed(VEL_BAIXA);
    motorDireita.run(FORWARD);
  }
  else if(posicao <= 2500 + FAIXA_ERRO)
  {
    motorDireita.setSpeed(VEL_MAXIMA);
    motorDireita.run(BACKWARD);
  }
} 
