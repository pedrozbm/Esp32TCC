// #include <Wire.h> //Biblioteca utilizada gerenciar a comunicação entre dispositicos através do protocolo I2C
#ifndef _LCD_H
#define _LCD_H
#include <LiquidCrystal_I2C.h> //Biblioteca controlar display 16x2 através do I2C


#define col  16 //Define o número de colunas do display utilizado
#define lin   2 //Define o número de linhas do display utilizado
#define ende  0x27 //Define o endereço do display

extern LiquidCrystal_I2C lcd; // Cria o objeto lcd passando como parâmetros o endereço, o nº de colunas e o nº de linhas

int menu();
void configLcd();

#endif