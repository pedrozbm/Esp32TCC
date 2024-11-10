#include <MFRC522.h>/biblioteca responsável pela comunicação com o módulo RFID-RC522
#include <SPI.h> //biblioteca para comunicação do barramento SPI
#include <Wire.h> //Biblioteca utilizada gerenciar a comunicação entre dispositicos através do protocolo I2C
#include "BluetoothSerial.h" // lib do bluetooth
#include <LiquidCrystal_I2C.h> //Biblioteca controlar display 16x2 através do I2C


#define SIZE_BUFFER     18 //tamanho do buffer
#define MAX_SIZE_BLOCK  16

//esse objeto 'chave' é utilizado para autenticação
MFRC522::MIFARE_Key key;
//código de status de retorno da autenticação
MFRC522::StatusCode status;

MFRC522 mfrc522(SS_PIN, RST_PIN); 
