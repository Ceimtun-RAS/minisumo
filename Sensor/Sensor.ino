/*
* Sensor 
*
* Clase para caracterización y encapsulamiento de los 
* sensores de linea y distancia. 
*
* Author: Linda Méndez 
* date: 12-April-2022 v0.1
* Project: Minisumo
*
*/ 

class Sensor{
    public:
        void Sensor(); 
        int displayName(); 

    private: 
}; 

Sensor::Sensor(){
    Serial.print("me creaste");
}
int Sensor::displayName(){
  Serial.print("Display");
  return 1;
}

Sensor mySensor; 


// ---- setup -----
void setup(){
Serial.begin(9600); 
mySensor = new Sensor(); 
}


void loop(){
  mySensor.displayName(); 
}
}
