#ifndef SensorProx_h
#define SensorProx_h
#include "Sensor.h";
#include <Arduino.h>;


class SensorProx :public Sensor{
  public:
    SensorProx(int posx,int posy, int dirx, int diry, int pn, int cons1, int cons2);
    SensorProx();
    
    void leer();
    int getcons1(){
      return cons1;
      }
    int getcons2(){
      return cons2;
    }
 private:
    int lectura = 0;
    int cons1 = 0;
    int cons2 = 0;
  };
  
 #endif
