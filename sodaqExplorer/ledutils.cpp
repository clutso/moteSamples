
#include "ledutils.h"


void setLedRED() {
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_BLUE, HIGH);
}

void setLedGREEN() {
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, HIGH);
}

void setLedBLUE() {
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_BLUE, LOW);
}

void setLedMAGENTA() {
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_BLUE, LOW);
}

void setLedCYAN() {
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
}

void setLedYELLOW() {
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, HIGH);
}

void setLedWHITE() {
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
}

void setLedBLACK() {
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_BLUE, HIGH);
}

void setRGB() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
}

void enableBuiltInLed(bool on){
  pinMode(LED_BUILTIN, OUTPUT);
  on ? digitalWrite(LED_BUILTIN, HIGH): digitalWrite(LED_BUILTIN, LOW);
  
}


void setLedSYS_WARN(){
  setLedYELLOW();
}

void setLedSYS_ALARM(){
  setLedRED();
}

void solidLedRetryJoin(){
  
  setLedBLUE();
  
}

void flashLedRetryJoin(){
  for(int i=0;i<4; i++){
  setLedBLUE();
  delay(500);
  setLedBLACK();
  delay(500);
  }
}

void flashLedDataSent(){
  for(int i=0;i<6; i++){
  setLedCYAN();
  delay(500);
  setLedBLACK();
  delay(500);
  }
}

void flashLedForSuccess(){
  for(int i=0;i<4; i++){
  setLedGREEN();
  delay(500);
  setLedBLACK();
  delay(500);
  }
}

void flashLedForFail(){

  for(int i=0;i<3; i++){
  setLedRED();
  delay(500);
  setLedBLACK();
  delay(500);
  }
}
