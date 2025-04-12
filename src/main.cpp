#include "../src/include/aplication.h"

MFRC522 mfrc522; 
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
