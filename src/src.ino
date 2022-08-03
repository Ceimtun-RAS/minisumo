#include "Sensor.h"
#include "SensorLinea.h"
#include "Motor.h"
#include "Minisumo.h"

// the setup routine runs once when you press reset:
Minisumo M1;


//    Sensor(int posx,int posy, int dirx, int diry, int pn);
void setup() {
  // initialize serial communication at 2000000 bits per second:
  Serial.begin(9600);
  M1.initt();
}

// the loop routine runs over and over again forever:
void loop() {
  
  M1.runn();
//  delay(2000);
 // M1.pruebaSensores();
  //M1.pruebaMotores();
  //  runn();

}
