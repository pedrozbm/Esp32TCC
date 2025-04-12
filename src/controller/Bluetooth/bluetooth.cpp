#include "../src/include/aplication.h"

BluetoothSerial SerialBT;

void configBluetooth()
{
    Serial.begin(115200);
    SerialBT.begin("ESP32_BT"); // Nome do dispositivo Bluetooth
    Serial.println("Bluetooth Started! Waiting for pairing...");
}

// void loop() {
//   if (SerialBT.available()) {
//     String received = SerialBT.readStringUntil('\n');

//     Serial.print("Received: ");
//     Serial.println(received);

//     // Enviar dados de volta, por exemplo, um OK:
//     SerialBT.println("OK");
//   }

//   delay(100);
// }
