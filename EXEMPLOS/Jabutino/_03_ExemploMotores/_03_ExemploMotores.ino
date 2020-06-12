//deve-se obrigatoriamente fazer referência à biblioteca da placa
#include <AFMotor.h>
/*
  Esta biblioteca facilita bastante a programação para controlar os motores,
  pois ela já faz todo trabalho complexo.
  
  Basta informar através de instruções simples o que deseja exatamente que ela faça,
  por exemplo, se desejar que ela controle o motor Direito para frente,
  basta digitar em seu programa o comando "motorDireito.run(FORWARD);",
  desde que os fios do motor estejam inseridos de forma correta na placa.
  
  Se não fosse por esta biblioteca,
  precisaríamos de muitas linhas de codificação para obter o mesmo resultado.
*/
 
// Devemos criar os dois objetos que representarão os motores no código
AF_DCMotor motorEsquerdo(1); // define o motor esquerdo no terminal M1 da placa
AF_DCMotor motorDireito(2); //define  o motor direito no terminal M2 da placa
/*
  Nas duas linhas acima, criamos um objeto que representará os nossos motores em tempo de execução (programa rodando no robô),
  desta forma para enviar uma instrução para o motor esquerdo,
  basta passar a instrução desejada para o objeto correspondente:
  
  Exemplo,
  "gire o motor esquerdo com metade da velocidade média..." deve ser codificada assim:
  
  motorEsquerdo.setSpeed(127); //define a velocidade entre 0 (mínima) e 255 (máxima)
  motorEsquerdo.run(BACKWARD); //Motor roda em sentido anti-horário
   
*/

void setup() { 
  //liga o motor esquerdo
  motorEsquerdo.setSpeed(255); // define a velocidade máxima dos motores (0 indica velocidade nula, 255 indica velocidade máxima)
  motorEsquerdo.run(RELEASE);  // garante que o motor fica parado, pois no momento queremos apenas atribuir a velocidade a ser desenvolvida.
 
  //liga o motor direito
  motorDireito.setSpeed(255);
  motorDireito.run(RELEASE); 
}


void loop() {
  //ANDAR PRA FRENTE
  motorEsquerdo.run(FORWARD); //dois motores para frente
  motorDireito.run(FORWARD);
  delay(2000); //aguarda 2 segundos = 2000 milisegundos
 
  //ANDAR PRA TRÁS
  motorEsquerdo.run(BACKWARD); //dois motores para trás
  motorDireito.run(BACKWARD);
  delay(2000); //aguarda 2 segundos = 2000 milisegundos
  
  //GIRAR PRA ESQUERDA
  motorEsquerdo.run(BACKWARD); //esquerdo para trás
  motorDireito.run(FORWARD); //direito para frente
  delay(2000); //aguarda 2 segundos = 2000 milisegundos
 
  //GIRAR PARA DIREITA
  motorEsquerdo.run(FORWARD); //esquerdo para frente
  motorDireito.run(BACKWARD); //direito para trás
  delay(2000); //aguarda 2 segundos = 2000 milisegundos
}

