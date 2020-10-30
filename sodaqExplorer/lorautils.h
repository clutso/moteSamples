#include <Arduino.h>
#include <Sodaq_RN2483.h>


#define debugSerial SerialUSB
#define loraSerial Serial2


#define NIBBLE_TO_HEX_CHAR(i) ((i <= 9) ? ('0' + i) : ('A' - 10 + i))
#define HIGH_NIBBLE(i) ((i >> 4) & 0x0F)
#define LOW_NIBBLE(i) (i & 0x0F)

uint8_t* hexDecode(const char*, size_t,uint8_t*);
void initModule();
bool setOTAA(uint8_t* ,uint8_t* , uint8_t*);
void resetModule();
