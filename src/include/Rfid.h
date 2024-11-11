#include <MFRC522.h> //biblioteca responsável pela comunicação com o módulo RFID-RC522

#define SIZE_BUFFER     18 //tamanho do buffer
#define MAX_SIZE_BLOCK  16

#define pinVerde     12
#define pinVermelho  32

#define SS_PIN    21 //pino sda
#define RST_PIN   22 // pino de reset

MFRC522::MIFARE_Key key;
//código de status de retorno da autenticação
MFRC522::StatusCode status;

// Definicoes pino modulo RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); 