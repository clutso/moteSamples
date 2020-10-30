#include <Arduino.h>
#include <Sodaq_RN2483.h>


#define debugSerial SerialUSB
#define loraSerial Serial2

String getTemperature();
String getSensor();
