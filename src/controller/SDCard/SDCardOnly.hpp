#ifndef SDCARDONLY_H
#define SDCARDONLY_H
#include "SD.h"

#define PINO_SDCARD 8

void sdInit();
void escreverDadosSD(String conteudoEscreverSD);
void leituraDadosSD();

#endif