#include <MFRC522.h>/biblioteca responsável pela comunicação com o módulo RFID-RC522
#include "Global.h"

#define col 16     //Define o número de colunas do display utilizado
#define lin 2      //Define o número de linhas do display utilizado
#define ende 0x27  //Define o endereço do display

#define SS_PIN 21   //pino sda
#define RST_PIN 22  // pino de reset

#define SIZE_BUFFER 18  //tamanho do buffer
#define MAX_SIZE_BLOCK 16

#define PINO_BOTAO 13   // Pino D2 conectado ao botão
#define PINO_BOTAO2 15  // Pino D2 conectado ao botão

#define pinVerde 12
#define pinVermelho 32

bool estadoAnteriorBotao = HIGH;  // Variável para armazenar o estado anterior do botão
bool estadoAnteriorBotao2 = HIGH;

LiquidCrystal_I2C lcd(ende, 16, 4);  //Cria o objeto lcd passando como parâmetros o endereço, o nº de colunas e o nº de linhas

//esse objeto 'chave' é utilizado para autenticação
MFRC522::MIFARE_Key key;
//código de status de retorno da autenticação
MFRC522::StatusCode status;

// Definicoes pino modulo RC522
MFRC522 mfrc522(SS_PIN, RST_PIN);
String device_name = "ESP32-BT-Slave";

BluetoothSerial SerialBT;



void setup() {
  // Inicia a serial
  // pinMode(PINO_BOTAO, INPUT_PULLUP);
  // pinMode(PINO_BOTAO2, INPUT_PULLUP);

  Wire.begin(26, 25);
  lcd.init();                   //Inicializa a comunicação com o display já conectado
  lcd.clear();                  //Limpa a tela do display
  lcd.backlight();              //Aciona a luz de fundo do display
  SerialBT.begin(device_name);  //Bluetooth device name


  Serial.begin(9600);
  SPI.begin();  // Init SPI bus

  pinMode(pinVerde, OUTPUT);
  pinMode(pinVermelho, OUTPUT);

  // Inicia MFRC522
  mfrc522.PCD_Init();
  // Mensagens iniciais no serial monitor
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();
}
void loop() {
  // Aguarda a aproximacao do cartao


  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Seleciona um dos cartoes
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  //chama o menu e recupera a opção desejada
  int opcao = menu();

  Serial.println(opcao);
  if (opcao == 0)
   {
      leituraDados();
    } else if (opcao == 1) {
      gravarDados();
    }
  else {
    Serial.println(F("Opção Incorreta!"));
    return;
  }


  // instrui o PICC quando no estado ACTIVE a ir para um estado de "parada"
  mfrc522.PICC_HaltA();
  // "stop" a encriptação do PCD, deve ser chamado após a comunicação com autenticação, caso contrário novas comunicações não poderão ser iniciadas
  mfrc522.PCD_StopCrypto1();
}
