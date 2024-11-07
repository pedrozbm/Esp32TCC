#include <Wire.h> //Biblioteca utilizada gerenciar a comunicação entre dispositicos através do protocolo I2C
#include <LiquidCrystal_I2C.h> //Biblioteca controlar display 16x2 através do I2C
#include "BluetoothSerial.h" // lib para o bluetooth


#define col  16 //Define o número de colunas do display utilizado
#define lin   2 //Define o número de linhas do display utilizado
#define ende  0x27 //Define o endereço do display

LiquidCrystal_I2C lcd(ende,16,4); //Cria o objeto lcd passando como parâmetros o endereço, o nº de colunas e o nº de linhas

void setup() {
  Wire.begin(26, 25);
  lcd.init(); //Inicializa a comunicação com o display já conectado
  lcd.clear(); //Limpa a tela do display
  lcd.backlight(); //Aciona a luz de fundo do display


}

void loop() {
lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("----SISTEMA-----"); //Exibe a mensagem na primeira linha do display
  lcd.setCursor(0, 1); //Coloca o cursor do display na coluna 1 e linha 2
  lcd.backlight();
  lcd.print("BRASILEIRO");  //Exibe a mensagem na segunda linha do display
}