
const int PINO_LED = 15;   // Pino D15 conectado ao LED
const int PINO_BOTAO = 13;  // Pino D2 conectado ao botão
bool estadoAnteriorBotao = HIGH; // Variável para armazenar o estado anterior do botão
bool estadoLed = false;    // Variável para armazenar o estado do LED
void setup() {
  pinMode(PINO_LED, OUTPUT);     // Define o PINO do LED como saída
  pinMode(PINO_BOTAO, INPUT); // Define o PINO do botão como entrada com resistor de pull-up interno
  Serial.begin(9600);
}
void loop() {
  int botaoPressionado = digitalRead(PINO_BOTAO); // Lê o estado do botão
  // Verifica se o botão foi pressionado (LOW é pressionado devido ao resistor de pull-up)
  if (botaoPressionado == LOW && estadoAnteriorBotao == HIGH) {
    // estadoLed = !estadoLed;// Inverte o estado do LED
    digitalWrite(PINO_LED, estadoLed); // Liga ou desliga o LED conforme o estado atual
    Serial.print("Apertou");
  }
  estadoAnteriorBotao = botaoPressionado; // Atualiza o estado anterior do botão
}
//bool -> abreviação de "boolean" que refere-se ao estado da variavel em questão seja alto/baixo ou verdadeiro/falso.
//if/else -> "IF" refere-se a uma condição "SE" tal ação acontecer faça isso. Por sua vez "ELSE" realizará no caso de "SE NÃO" acontecer a ação esperada faça aquilo.