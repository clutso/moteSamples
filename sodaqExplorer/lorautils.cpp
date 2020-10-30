#include "lorautils.h"


uint8_t* hexDecode(const char *in, size_t len,uint8_t *out)
{
        unsigned int i, t, hn, ln;

        for (t = 0,i = 0; i < len; i+=2,++t) {

                hn = in[i] > '9' ? in[i] - 'A' + 10 : in[i] - '0';
                ln = in[i+1] > '9' ? in[i+1] - 'A' + 10 : in[i+1] - '0';

                out[t] = (hn << 4 ) | ln;
        }

        return out;
}


void initModule(){
  delay(1000);
  while ((!debugSerial) && (millis() < 10000))
  debugSerial.begin(57600);
  loraSerial.begin(LoRaBee.getDefaultBaudRate());
  LoRaBee.setDiag(debugSerial);
  LoRaBee.init(loraSerial, LORA_RESET);
}

bool setOTAA( uint8_t devEUI[8], uint8_t appEUI[8], uint8_t appKey[16]){  
  bool response=false;
  if (LoRaBee.initOTA(loraSerial, devEUI, appEUI, appKey, true))
    response=true;
 LoRaBee.setSpreadingFactor(9);
 return response;
}

void resetModule(){
  LoRaBee.init(loraSerial, LORA_RESET);
}


/*
//targetted for deletion? 
void setupLoRa(){

  if (setOTAA(DevEUI, AppEUI, AppKey))
    debugSerial.println("Network connection successful.");
  else
    debugSerial.println("Network connection failed!");
}
*/