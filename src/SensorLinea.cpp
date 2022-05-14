#include "Sensor.h"
#include "SensorLinea.h"
#include <Arduino.h>;
SensorLinea::SensorLinea(int posx,int posy, int dirx, int diry, int pn):Sensor(posx,posy,dirx, diry, pn){};
SensorLinea::SensorLinea():Sensor(){};
void SensorLinea::leer(){
       //delay(100);
       estado = analogRead(getpin());
      //delay(100);
      Serial.print(((maximo-minimo)/2)-(maximo*sensibilidad/100));
      if (estado <(((maximo-minimo)/2)-(maximo*sensibilidad/100))) {
        Serial.print("blanco  ");
        Serial.println(estado);
        magnitud=-1000;
      }
      else {
        Serial.print("negro  ");
        Serial.println(estado);
        magnitud=0;
      }
    }
    
