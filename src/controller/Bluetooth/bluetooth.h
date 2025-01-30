#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "BluetoothSerial.h"

extern BluetoothSerial SerialBT;

void configBluetooth();
void enviarBluetooth(String dadoEnviar);
String leituraBluetooth();

#endif