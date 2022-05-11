#ifndef SensorProx_h
#define SensorProx_h
#include "Sensor.h";
#include <Arduino.h>;


class SensorProx :public Sensor{
  public:
    SensorProx(int posx,int posy, int dirx, int diry, int pn);
    SensorProx();
    
    void leer();
    

 private:
    int estado = 0;
    int cons1 = 0;
    int cons2 = 0;
  };
  
 #endif
