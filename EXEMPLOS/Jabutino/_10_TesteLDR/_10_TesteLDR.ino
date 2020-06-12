void setup ()
{
  Serial.begin(9600); 
}

void loop ()
{
  int pinoSensor = 14; // define o pino em que conectou o sensor
  int valorMaximo = 30000; // define o valor máximo da leitura
  
  // efetua a leitura do sensor
  int leitura = LeituraLDR(pinoSensor, valorMaximo);
  
  // imprime o resultado
  Serial.print ("Valor lido: ");
  if (leitura == valorMaximo)
  {
    Serial.println("[atingiu o limite]");
  }
  else
  {
    Serial.println(leitura);
  }
  
  // aguarda um pouco para efetuar outra leitura
  delay(500);
}

int LeituraLDR(int pinoSensor, int valorMaximo)
{
  int valor = 0;  // inicia com 0
 
  // define o pino como saída (OUTPUT)
  pinMode(pinoSensor, OUTPUT);
  // coloca a tensão  baixa (GND) para esvaziar o capacitor
  digitalWrite(pinoSensor, LOW);
 
  // agora define o pino como entrada (INPUT)
  pinMode(pinoSensor, INPUT);
  
  // enquanto o capacitor não ficar cheio
  while (digitalRead(pinoSensor) == LOW)
  {
    valor++;  // incrementa o valor
    
    if (valor == valorMaximo)
    {
      // se o valor ficou muito alto é possível que não esteja conectado
      break; // interrompe a repetição
    }
  }
  
  // se chegou até aqui atingiu o valor máximo
  // ou atingiu a contagem correta
  // então retorna o resultado
  return valor;
}
