#include "sensorutils.h"

String getTemperature()
{
  //10mV per C, 0C is 500mV
  float mVolts = (float)analogRead(A6) * 3300.0 / 1023.0;
  float temp = (mVolts - 500.0) / 10.0;

  return String(temp);
}

String getSensor()
{
  //10mV per C, 0C is 500mV
  float mVolts = (float)analogRead(A0) ;
  return String(mVolts);
}
