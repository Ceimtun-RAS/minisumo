#include "Sensor.h"
#include "SensorProx.h"
#include <Arduino.h>;
SensorProx::SensorProx(int posx,int posy, int dirx, int diry, int pn, int cons1, int cons2):Sensor(posx,posy,dirx, diry, pn){
  cons1  = cons1;
  cons2  = cons2;
  };
SensorProx::SensorProx():Sensor(){};
void SensorProx::leer(){
       //delay(100);
       lectura = analogRead(getpin());
      //delay(100);

      magnitud = getcons1() * pow(lectura, getcons2());
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
