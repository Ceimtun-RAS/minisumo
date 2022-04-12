#include <QTRSensors.h>
int Ld = A7;
int Li = A6; 

void setup() {
  // put your setup code here, to run once:
  pinMode(Ld,INPUT);
  pinMode(Li,INPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print("Ld:");
  Serial.println(analogRead(Ld));
  //delay(500);
  //Serial.print("Li:");
  //Serial.println(Li);
  delay(100);
}
