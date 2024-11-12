#include <SPI.h> //biblioteca para comunicação do barramento SPI
#include <Wire.h> //Biblioteca utilizada gerenciar a comunicação entre dispositicos através do protocolo I2C
#include <LiquidCrystal_I2C.h> //Biblioteca controlar display 16x2 através do I2C
#include <Arduino.h>
#include ".\controller\Rfid\LerDados\Rfid.h"


#define col  16 //Define o número de colunas do display utilizado
#define lin   2 //Define o número de linhas do display utilizado
#define ende  0x27 //Define o endereço do display

// #define SS_PIN    21 //pino sda
// #define RST_PIN   22 // pino de reset

// #define SIZE_BUFFER     18 //tamanho do buffer
// #define MAX_SIZE_BLOCK  16

// #define pinVerde     12
// #define pinVermelho  32

LiquidCrystal_I2C lcd(ende,16,4); //Cria o objeto lcd passando como parâmetros o endereço, o nº de colunas e o nº de linhas

//esse objeto 'chave' é utilizado para autenticação
// MFRC522::MIFARE_Key key;
// //código de status de retorno da autenticação
// MFRC522::StatusCode status;

// // Definicoes pino modulo RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); 
MFRC522::MIFARE_Key key;
MFRC522::StatusCode status;
//teste
void setup() {
  // Inicia a serial
  Wire.begin(26, 25);
  lcd.init(); //Inicializa a comunicação com o display já conectado
  lcd.clear(); //Limpa a tela do display
  lcd.backlight(); //Aciona a luz de fundo do display

  Serial.begin(9600);
  SPI.begin(); // Init SPI bus

  pinMode(pinVerde, OUTPUT);
  pinMode(pinVermelho, OUTPUT);
  
  // Inicia MFRC522
  mfrc522.PCD_Init(); 
  // Mensagens iniciais no serial monitor
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();

}

// 
//menu para escolha da operação
int menu()
{
  Serial.println(F("\nEscolha uma opção:"));
  lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("Escolha uma opção:"); //Exibe a mensagem na primeira linha do display
  lcd.setCursor(0, 1); //Coloca o cursor do display na coluna 1 e linha 2
  Serial.println(F("0 - Leitura de Dados"));
  lcd.print("0 - Leitura de Dados");
  Serial.println(F("1 - Gravação de Dados\n"));

  //fica aguardando enquanto o usuário nao enviar algum dado
  while(!Serial.available()){};

  //recupera a opção escolhida
  int op = (int)Serial.read();
  //remove os proximos dados (como o 'enter ou \n' por exemplo) que vão por acidente
  while(Serial.available()) {
    if(Serial.read() == '\n') break; 
    Serial.read();

  }
  return (op-48);//do valor lido, subtraimos o 48 que é o ZERO da tabela ascii
}

void loop() 
{
   // Aguarda a aproximacao do cartao
   //teste
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Seleciona um dos cartoes
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  //chama o menu e recupera a opção desejada
  int opcao = menu();
  
  if(opcao == 0) 
    leituraDados();
  else if(opcao == 1) 
    gravarDados();
  else {
    Serial.println(F("Opção Incorreta!"));
    return;
  }
  // instrui o PICC quando no estado ACTIVE a ir para um estado de "parada"
  mfrc522.PICC_HaltA(); 
  // "stop" a encriptação do PCD, deve ser chamado após a comunicação com autenticação, caso contrário novas comunicações não poderão ser iniciadas
  mfrc522.PCD_StopCrypto1();  
}

