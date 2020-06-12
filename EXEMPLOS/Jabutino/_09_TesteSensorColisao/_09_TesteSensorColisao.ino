/*
  Esse exemplo demonstra a utilização da
  entrada digital do Arduino como INPUT_PULLUP.
  Isso fará com que o pino digital seja internamente conectado
  à fonte +5V (ou HIGH) através de um resistor de 20kOhms
  
  Toda vez que o circuito entre o pino digital e GND 
  estiver fechado (conectado), a leitura será 0V (ou LOW).
  
  Quando o circuito entre o pino digital e GND estiver aberto (sem conexão)
  o resistor pullup permitirá que a leitura seja +5V (ou HIGH)
  
  Essa lógica seria normalmente inversa, mas o sensor do Jabutino
  é fabricado no modo NC (Normally Closed, ou normalmente fechado).
  Isso significa que quando ele não estiver pressionado,
  o circuito está fechado e a leitura será LOW.
  Quando ele for pressionado, o circuito abre e a leitura será HIGH.
  
  Na pratica, isso faz com que a lógica seja revertida
  novamente para o raciocínio tradicional.
  Quando o sensor estiver solto a leitura será LOW
  e quando for pressionado a leitura será HIGH
 */
 
// define o pino que vai conectar a chave
int pinoChave = 14;
// variável para monitorar as mudanças na leitura
int leituraAnterior = LOW;

void setup()
{
  // inicia a comunicação serial
  Serial.begin(9600);
  // define o pino como entrada
  // ligando um resistor pullup a ele
  pinMode(pinoChave, INPUT_PULLUP); // MUITO IMPORTANTE
}

void loop()
{
  // faz a leitura do sensor
  int leitura = digitalRead(pinoChave);
  
  // verifica se a leitura é diferente da leitura anterior
  // para imprimir na serial apenas quando mudar
  if (leitura != leituraAnterior)
  {
    //imprime o valor
    if(leitura == HIGH)
    {
      Serial.println("PRESSIONOU");
    }
    else
    {
      Serial.println("SOLTOU");
    }
        
    // armazena o valor lido para monitorar as próximas mudanças
    leituraAnterior = leitura;      
    // aguarda minimamente para eliminar ruidos
    delay(5);
  }
}
