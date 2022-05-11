#ifndef Motor_h
#define Motor_h
#include <Arduino.h>;
  class Motor{
  public:
    Motor();
    Motor(int pn1,int pn2,int pnv);
    int pin[2];
    void giroHr(int vel){
      analogWrite(pinVel, vel); //control vel.
      Serial.println("horario  ");
      digitalWrite(pin[0], HIGH); 
      digitalWrite(pin[1], LOW);
      };
    void giroAhr(int vel){
      analogWrite(pinVel, vel); //control vel.
       Serial.println("Anthorario  ");
      digitalWrite(pin[0], LOW); 
      digitalWrite(pin[1], HIGH);
      };
    void detener(){
      analogWrite(pinVel, 0); //control vel.
      digitalWrite(pin[0], LOW); 
      digitalWrite(pin[1], LOW);
      };
  private:
   // int pin[2];
    int pinVel; 
  };

#endif
