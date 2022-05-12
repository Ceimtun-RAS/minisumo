#ifndef Minisumo_h
#define Minisumo_h
#include "Sensor.h"
#include "SensorLinea.h"
#include "Motor.h"
#include <Arduino.h>;
class Minisumo {
  public:

    Minisumo();

    void initt() {
      SensorLinea S1(1, 1, 1, 1, A1);
      SensorLinea S2(-1, 1, -1, 1, A2);
      Sen[0] = S1;
      Sen[1] = S2;
      Motor m1(4, 9, 5);
      Motor m2(7, 8, 6);
      Mot[0] = m1;
      Mot[1] = m2;
    }
    void runn() {
      leerSensores();
      if (enemy[0] < -10) {
        girarIzq(200);
        delay(1000);
      }
      else if (enemy[0] > 10) {
        girarDer(200);
        delay(1000);
      }
      else {
        if (enemy[1] > 10) {
          avanzar(200);
        }
        else {
          retroceder(200);
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
    Motor Mot[2];
    int enemy[2];

};

#endif
