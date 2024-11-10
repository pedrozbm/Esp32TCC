void setupRfid()
{
    Serial.begin(9600);
    SPI.begin(); // Init SPI bus

    pinMode(pinVerde, OUTPUT);
    pinMode(pinVermelho, OUTPUT);

    // Inicia MFRC522
    mfrc522.PCD_Init();
    // Mensagens iniciais no serial monitor
    Serial.println("Aproxime o seu cartao do leitor...");
    Serial.println();

}