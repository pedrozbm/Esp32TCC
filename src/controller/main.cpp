#include <Arduino.h>
#include ".\controller\Rfid\LerDados\Rfid.h"
#include ".\controller\lcd\lcd.h"
#include ".\controller\Bluetooth\bluetooth.h"

LiquidCrystal_I2C lcd(ende, 20, 4); // Cria o objeto lcd passando como parâmetros o endereço, o nº de colunas e o nº de linhas
BluetoothSerial SerialBT;

// // Definicoes pino modulo RC522
MFRC522 mfrc522(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
MFRC522::StatusCode status;

void setup()
{
  // Inicia a serial
  configLcd();
  configBluetooth();
  rfidConfig();
  Serial.begin(9600);
 
}

void loop()
{
  // Aguarda a aproximacao do cartao
  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Seleciona um dos cartoes
  if (!mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  // chama o menu e recupera a opção desejada
  int opcao = menu();

  if (opcao == 0)
    leituraDados();
  else if (opcao == 1)
    gravarDados();
  else
  {
    Serial.println(F("Opção Incorreta!"));
    return;
  }
  // instrui o PICC quando no estado ACTIVE a ir para um estado de "parada"
  mfrc522.PICC_HaltA();
  // "stop" a encriptação do PCD, deve ser chamado após a comunicação com autenticação, caso contrário novas comunicações não poderão ser iniciadas
  mfrc522.PCD_StopCrypto1();

}
