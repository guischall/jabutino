//obrigatoriamente, deve-se fazer referência à biblioteca da placa
#include <AFMotor.h>

AF_DCMotor motorEsquerdo(1); //define o motor esquerdo na posição M1
AF_DCMotor motorDireito(2); //define o motor direito na posição M2

void setup(){
    //setSpeed = comando para definir a velocidade que o moter deverá girar
    //pode variar entre 0 (parado) a 255 (velocidade total)
    motorEsquerdo.setSpeed(200);
    motorDireito.setSpeed(200);
    
    //run = comando para mover/parar o motor
    //neste momento serve apenas pra inicializá-lo sem que gire
    motorEsquerdo.run(RELEASE);
    motorDireito.run(RELEASE);
}

void loop()
{
  //Gira o motor esquerdo "para frente" (sentido anti-horário)
  motorEsquerdo.run(FORWARD);
  
  //Gira o motor direito "para frente" (sentido horário)
  motorDireito.run(FORWARD);
}
