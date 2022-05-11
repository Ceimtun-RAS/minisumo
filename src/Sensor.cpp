#include "Sensor.h"

Sensor::Sensor(){
    posicion[0]=0;
    direccion[0]=0;
    posicion[1]=0;
    direccion[1]=0;
    pin=0;
};
Sensor::Sensor(int posx,int posy, int dirx, int diry, int pn){
    posicion[0]=posx;
    direccion[0]=dirx;
    posicion[1]=posy;
    direccion[1]=diry;
    pin=pn;
};
void Sensor::leer(){
  magnitud=0;
  }
