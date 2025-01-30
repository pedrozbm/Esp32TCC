#include "..\src\include\aplication.h"

void configBluetooth()
{
    SerialBT.begin("SISTEMA BR"); // Nome do dispositivo Bluetooth
    Serial.println("Bluetooth iniciado");
}

String leituraBluetooth()
{
    if (SerialBT.available())
    {
        return SerialBT.readStringUntil('\n');
    }
    return "Sem dados";
}

void enviarBluetooth(String dadoEnviar)
{
    if (SerialBT.available())
    {
        SerialBT.println(dadoEnviar);
    }
}

