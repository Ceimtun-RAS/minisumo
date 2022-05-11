#include "Sensor.h"
#include "SensorProx.h"
#include <Arduino.h>;
SensorProx::SensorProx(int posx,int posy, int dirx, int diry, int pn):Sensor(posx,posy,dirx, diry, pn){};
SensorProx::SensorProx():Sensor(){};
void SensorProx::leer(){
       //delay(100);
       estado = analogRead(getpin());
      //delay(100);
      magnitud = estado;
    }

/*
void leer_proximidad(){
  //LECTURA INICIAL DE LOS SENSORES
   LDD = analogRead(DD);
   LDD = 85383 * pow(LDD, -1.383);
   LDI = analogRead(DI);
   LDI = 85383 * pow(LDI, -1.383);
   //Serial.println(LDD);
   //delay(1000);
   Serial.println(LDI);
   delay(1000);
}

*/
