#ifndef SensorLinea_h
#define SensorLinea_h
#include "Sensor.h";
#include <Arduino.h>;
class SensorLinea :public Sensor{
  public:
    SensorLinea(int posx,int posy, int dirx, int diry, int pn);
    SensorLinea();
    void calibrar() {
   //   maximo = 1;
    //  minimo = 1300;
      unsigned long tiempo = millis();
      while (millis() < tiempo + 5000) {
        estado = analogRead(getpin());
        if (estado > maximo) {
          maximo = estado;
        }
        else if (estado < minimo) {
          minimo = estado;
        }
      }
    }
    void leer();/*{
       //delay(100);
       estado = analogRead(getpin());
      //delay(100);
      if (estado <(((maximo-minimo)/2)-maximo*sensibilidad/100)) {
        //Serial.println("blanco  ");
        //Serial.print(estado);
        magnitud=-1000;
      }
      else {
        //Serial.println("negro  ");
        //Serial.print(estado);
        magnitud=0;
      }
    }*/
    

 private:
    int estado = 0;
    int maximo = 1300;
    int minimo = 1;
    int sensibilidad=11;//valor entre 1-100; recomndacion menor a 40
 
  
  };

  #endif
