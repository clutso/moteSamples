#include <Sodaq_RN2483.h>
#include "lorautils.h"
#include "ledutils.h"
#include "sensorutils.h"
#include "loracredentials.h"

bool DEBUGG_MODE= false;
bool TURN_BUILTINLED_ON= false;
bool IS_JOINNED= false;
uint8_t DevEUI[8];
uint8_t AppEUI[8];
uint8_t AppKey[16];


void setup()
{  
  TURN_BUILTINLED_ON ? enableBuiltInLed(true):enableBuiltInLed(false) ;
  setRGB();
  setLedBLACK();
  initModule();
  //using OTAA by default Use your own keys
  
  char strDev[]= DEVEUI;
  char strApp[]= APPEUI;
  char strAKey[]=APPKEY;
  
  hexDecode(strDev,strlen(strDev),DevEUI );
  hexDecode(strApp,strlen(strApp),AppEUI );
  hexDecode(strAKey,strlen(strAKey),AppKey );
  IS_JOINNED=setOTAA(DevEUI, AppEUI, AppKey);
  IS_JOINNED? flashLedForSuccess():flashLedForFail();
}

void loop()
{ //NOTE: this SHOULD be a byte array 
  //using string to ease academic porpouses
   String reading = getTemperature();
 
   if(DEBUGG_MODE)
      debugSerial.println(reading) ;
    switch (LoRaBee.send(1, (uint8_t*)reading.c_str(), reading.length()))
    {
    case NoError:
      flashLedDataSent();
      break;
    case NoResponse:
      setLedSYS_ALARM();
      break;
    case Timeout:
      setLedSYS_WARN();//Connection timed-out. Check your serial connection to the device! Sleeping for 20sec.
      delay(20000);
      break;
    case PayloadSizeError:
      setLedSYS_ALARM();
      break;
    case InternalError:
      setLedSYS_ALARM();
      IS_JOINNED=setOTAA(DevEUI, AppEUI, AppKey);
      IS_JOINNED? flashLedForSuccess():flashLedForFail();
      break;
    case Busy:
      setLedSYS_WARN();//The device is busy. Sleeping for 10 extra seconds.
      delay(10000);
      break;
    case NetworkFatalError:
      setLedSYS_ALARM();
      IS_JOINNED=setOTAA(DevEUI, AppEUI, AppKey);
      IS_JOINNED? flashLedForSuccess():flashLedForFail();
      break;
    case NotConnected:
      solidLedRetryJoin();
      IS_JOINNED=setOTAA(DevEUI, AppEUI, AppKey);
      IS_JOINNED? flashLedForSuccess():flashLedForFail();      //debugSerial.println("The device is not connected to the network. The program will reset the RN module.");
      break;
    case NoAcknowledgment:
      setLedSYS_WARN();
      break;
    default:
      setLedMAGENTA();
      break;
    }
    // Delay between readings // send every 5 seconds in debugging mode  every 2:30 minutes when not // 60 000 = 1 minute    
    if (IS_JOINNED)
      DEBUGG_MODE ? delay(5000): delay(150000); 
}
