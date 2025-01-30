#include <Arduino.h>
#include "..\src\include\aplication.h"

MFRC522 mfrc522(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
MFRC522::StatusCode status;

BluetoothSerial SerialBT;

LiquidCrystal_I2C lcd(ende, 20, 4); // Cria o objeto lcd passando como parâmetros o endereço, o nº de colunas e o nº de linhas

// put function declarations here:
void setup()
{
  // put your setup code here, to run once:
  // int result = myFunction(2, 3);

  rfidConfig();
  configBluetooth();
  rfidConfig();
  Serial.begin(9600);
  
}

void loop()
{
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}
