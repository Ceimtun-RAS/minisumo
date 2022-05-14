#ifndef Minisumo_h
#define Minisumo_h
#include "Sensor.h"
#include "SensorLinea.h"
#include "SensorProx.h"
#include "Motor.h"
#include <Arduino.h>;

class Minisumo {
  public:

    Minisumo();

    void initt() {
      //SensorProx(int posx,int posy, int dirx, int diry, int pn, int cons1, int cons2)
      SensorLinea S1(1, 1, 1, 1, A1); //derecha
      SensorLinea S2(-1, 1, -1, 1, A2);
      //SensorProx DD(2,2,0,1,A3,11438,-1.173);
      //SensorProx DI(-2,2,0,1,A4,6943,0.953);
      //SensorProx LD(3,0,1,0,A5,4692,0.9929);
      //SensorProx LI(-3,0,-1,0,A6);
      
      Sen[0] = S1;
     Sen[1] = S2;
     // SenP[0] = DD;
     // SenP[1] = DI;
     // SenP[2] = LD;
     // SenP[3] = LI;
      
      Motor m1(4, 9, 6);
      Motor m2(7, 8, 5);
      Mot[0] = m1;
      Mot[1] = m2;
    }
    void runn() {
      leerSensores();
      Serial.print(enemy[0]);
      Serial.print("     ");
      Serial.println(enemy[1]);
      if (enemy[0] < -10) {
        retroceder(vel);
          delay(100);
        girarIzq(vel);
        delay(500);
      }
      else if (enemy[0] > 10) {
        retroceder(vel);
          delay(100);
        girarDer(vel);
        delay(500);
      }
      else {
        if (enemy[1] < 0) {

          retroceder(vel);
          delay(100);
          girarDer(vel);
          delay(500);
          
        }
        else {
          
       avanzar(vel);
        }
      }
    }

    void pruebaMotores() {
      avanzar(100);
      delay(5000);
      girarDer(100);
      delay(5000);
      girarIzq(100);
      delay(5000);

    }

    void pruebaSensores() {

      delay(2000);
      leerSensores();
      Serial.print(enemy[0]);
      Serial.print("     ");
      Serial.println(enemy[1]);
    }



    void leerSensores() {
      enemy[0] = 0;
      enemy[1] = 0;
      int *e;
      
      for (int i = 0; i < 2; i++) {
        Sen[i].leer();
        e = Sen[i].getenemy();
        enemy[0] = enemy[0] + e[0];
        enemy[1] = enemy[1] + e[1];
      }
     /* for (int i = 0; i < 4; i++) {
        SenP[i].leer();
        e = SenP[i].getenemy();
        enemy[0] = enemy[0] + e[0];
        enemy[1] = enemy[1] + e[1];
      }*/

    }
    void girarDer(int vel) {
      Mot[0].giroAhr(vel);
      Mot[1].giroHr(vel);
    }
    void girarIzq(int vel) {
      Mot[0].giroHr(vel);
      Mot[1].giroAhr(vel);
    }
    void avanzar(int vel) {
      for (int i = 0; i < 2; i++) {
        Mot[i].giroHr(vel);
      }
    }
    void retroceder(int vel) {
      for (int i = 0; i < 2; i++) {
        Mot[i].giroAhr(vel);
      }
    }
    void detener() {
      for (int i = 0; i < 2; i++) {
        Mot[i].detener();
      }
    }
  private:
    SensorLinea Sen[2];
    SensorProx SenP[4];
    Motor Mot[2];
    int vel = 120;
    int enemy[2];

};

#endif
