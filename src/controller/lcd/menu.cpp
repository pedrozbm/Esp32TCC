#include ".\controller\Rfid\LerDados\Rfid.h"
#include ".\controller\lcd\lcd.h"

void configLcd()
{
  Wire.begin(26, 25);
  lcd.init();      // Inicializa a comunicação com o display já conectado
  lcd.clear();     // Limpa a tela do display
  lcd.backlight(); // Aciona a luz de fundo do display
}

int menu()
{
  Serial.println(F("\nEscolha uma opção:"));
  lcd.setCursor(0, 0);             // Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("Escolha uma opção:"); // Exibe a mensagem na primeira linha do display
  lcd.setCursor(0, 1);             // Coloca o cursor do display na coluna 1 e linha 2
  Serial.println(F("0 - Leitura de Dados"));
  lcd.print("0 - Leitura de Dados");
  Serial.println(F("1 - Gravação de Dados\n"));

  // fica aguardando enquanto o usuário nao enviar algum dado
  while (!Serial.available())
  {
  };

  // recupera a opção escolhida
  int op = (int)Serial.read();
  // remove os proximos dados (como o 'enter ou \n' por exemplo) que vão por acidente
  while (Serial.available())
  {
    if (Serial.read() == '\n')
      break;
    Serial.read();
  }
  return (op - 48); // do valor lido, subtraimos o 48 que é o ZERO da tabela ascii
}