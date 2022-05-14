
#ifndef InitSensor_h
#define InitSensor_h
 
#include "Arduino.h"

class InitSensor{
  public:
    InitSensor(int test, int allowable); 
    bool getAllowable(); 
    bool continueReading(); 

  private:
    bool state;
    int allowablePin;   
    int testPin;   
};

#endif
