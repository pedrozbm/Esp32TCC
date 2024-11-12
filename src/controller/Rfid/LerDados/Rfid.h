#include <MFRC522.h> //biblioteca responsável pela comunicação com o módulo RFID-RC522
#include <SPI.h>  //biblioteca para comunicação do barramento SPI

#define SIZE_BUFFER     18 //tamanho do buffer
#define MAX_SIZE_BLOCK  16

#define pinVerde     12
#define pinVermelho  32

#define SS_PIN    21 //pino sda
#define RST_PIN   22 // pino de reset

//esse objeto 'chave' é utilizado para autenticação
extern MFRC522 mfrc522; 
extern MFRC522::MIFARE_Key key;
// //código de status de retorno da autenticação
extern MFRC522::StatusCode status;

void leituraDados();
void gravarDados();
void rfidConfig();
