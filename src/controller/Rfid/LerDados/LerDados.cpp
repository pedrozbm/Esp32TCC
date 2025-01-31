#include "..\src\include\aplication.h"

void rfidConfig()
{
  // Inicia MFRC522
  mfrc522.PCD_Init();
  // Mensagens iniciais no serial monitor
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();
  SPI.begin(); // Init SPI bus
  pinMode(pinVerde, OUTPUT);
  pinMode(pinVermelho, OUTPUT);
}

String leituraDados()
{
  // imprime os detalhes tecnicos do cartão/tag
  mfrc522.PICC_DumpDetailsToSerial(&(mfrc522.uid));

  // Prepara a chave - todas as chaves estão configuradas para FFFFFFFFFFFFh (Padrão de fábrica).
  for (byte i = 0; i < 6; i++)
    key.keyByte[i] = 0xFF;

  // buffer para COLUNAocar os dados ligos
  byte buffer[SIZE_BUFFER] = {0};

  // bloco que faremos a operação
  byte bloco = 1;
  byte tamanho = SIZE_BUFFER;

  autenticacaoCartao(bloco);
  return leituraBloco(bloco, buffer, tamanho);
  // faz a leitura dos dados do bloco
}

void autenticacaoCartao(byte &bloco)
{
  // faz a autenticação do bloco que vamos operar
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, bloco, &key, &(mfrc522.uid)); // line 834 of MFRC522.cpp file
  if (status != MFRC522::STATUS_OK)
  {
    Serial.print(F("Authenticacao 1 falhou "));
    Serial.print(F("Tentando novamente..."));
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, bloco, &key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK)
    {
      Serial.print(F("Authentication failed: "));
      Serial.println(mfrc522.GetStatusCodeName(status));
      digitalWrite(pinVermelho, HIGH);
      delay(1000);
      digitalWrite(pinVermelho, LOW);
      return;
    }
  }
}

String leituraBloco(byte &bloco, byte (&buffer)[SIZE_BUFFER], byte &tamanho)
{
  status = mfrc522.MIFARE_Read(bloco, buffer, &tamanho);
  if (status != MFRC522::STATUS_OK)
  {
    Serial.print(F("Reading failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    digitalWrite(pinVermelho, HIGH);
    delay(1000);
    digitalWrite(pinVermelho, LOW);
    return "ERRO";
  }
  else
  {
    digitalWrite(pinVerde, HIGH);
    delay(1000);
    digitalWrite(pinVerde, LOW);
  }

  Serial.print(F("\nDados bloco ["));
  Serial.print(bloco);
  Serial.print(F("]: "));
  String dadosEnviar = "";
  // imprime os dados lidos
  for (uint8_t i = 0; i < MAX_SIZE_BLOCK; i++)
  {
    // lcd.setCursor(i, 3);
    // lcd.print(buffer[i]);
    Serial.write(buffer[i]);
    dadosEnviar += (char)buffer[i];
    // std::string print = (char *)buffer[i];
  }
  Serial.println(" ");
  lcd.setCursor(0, 3);
  lcd.print(dadosEnviar);
  return dadosEnviar;
}
