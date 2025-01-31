#include "../src/include/aplication.h"

void sdInit()
{
    if (!SD.begin(PINO_SDCARD, SPI, 80000000, "/sd", 5, false))
    {
        Serial.println("Falha ao inicializar o SD!");
        return;
    }
    // se chegou aqui é porque o cartão foi inicializado corretamente
    Serial.println("Cartão inicializado.");
}

void escreverDadosSD(String conteudoEscreverSD)
{
    File arquivo = SD.open("/dados.txt", FILE_WRITE);
    if (arquivo)
    {
        arquivo.println(conteudoEscreverSD);
        arquivo.close();
    }
    else
    {
        Serial.println("Erro ao guardar info.");
    }
}

void leituraDadosSD()
{
    File arquivo = SD.open("/dados.txt");
    if (arquivo)
    {
        if (arquivo.available())
        {
            String linha = arquivo.readStringUntil('\n');
            Serial.println(linha);
        }
        arquivo.close();
    }else{
        Serial.println("Erro ao abrir arquivo");
    }    
}
