#ifndef Sensor_h
#define Sensor_h
#include <Arduino.h>;
  class Sensor{
  public:

    Sensor();
    Sensor(int posx,int posy, int dirx, int diry, int pn);
    int getpin(){
      return pin;
      }
    int getmagnitud(){
      return magnitud;
      };

    int* getpos(){
      return posicion;
      };
    int* getenemy(){ 
      for (int i = 0; i<2; i++) {
      int a=getmagnitud();
      enemy[i]=posicion[i]+(direccion[i]*a);
      /*Serial.print("enm     :");
      Serial.println(enemy[i]);
      Serial.print("mag     :");
      Serial.println(a);
      Serial.print("pos     :");
      Serial.println(posicion[i]);
      Serial.print("dir     :");
      Serial.println(direccion[i]);*/
      }
      return enemy;
      };
    virtual void leer();
    
  private:
    int posicion[2];
    int direccion[2];
    int pin;
    int enemy[2];
  protected:
    int magnitud;
  };

#endif
