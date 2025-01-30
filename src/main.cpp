#include <Arduino.h>
#include "..\src\include\aplication.h"

// Criação de nossos objetos globais

MFRC522 mfrc522(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
MFRC522::StatusCode status;

BluetoothSerial SerialBT;

LiquidCrystal_I2C lcd(ende, 20, 4);

// put function declarations here:
void setup()
{
  // Iniciando serial e configs

  Serial.begin(115200);
  rfidConfig();
  configBluetooth();
  configLcd();
}

void loop()
{
  if (leituraBluetooth() == "a")
  {
    enviarBluetooth(leituraDados());
  }
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}
