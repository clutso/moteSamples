#include <Arduino.h>
#include <Sodaq_RN2483.h>

void setLedRED();
void setLedGREEN();
void setLedBLUE();
void setLedMAGENTA();
void setLedYELLOW();
void setLedCYAN();
void setLedWHITE();
void setLedBLACK();
void setRGB();
void enableBuiltInLed(bool);
void flashLedForSuccess();
void flashLedForFail();
void flashLedDataSent();
void flashLedRetryJoin();
void setLedSYS_ALARM();
void setLedSYS_WARN();
void solidLedRetryJoin();