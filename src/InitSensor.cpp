#include "Arduino.h"
#include "InitSensor.h"

InitSensor::InitSensor(int test, int allowable){
  allowablePin = allowable; 
  testPin = test; 

  pinMode(allowablePin,INPUT); 
  pinMode(allowablePin, INPUT); 
}

bool InitSensor::getAllowable(){ 
  return state;  
}

bool InitSensor::continueReading(){
  state = digitalRead(allowablePin); 
  return true;
}
