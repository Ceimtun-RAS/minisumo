#include "Motor.h"

Motor::Motor(){
  pin[0]=0;
  pin[1]=0;
  pinVel=0;
};
Motor::Motor(int pn1,int pn2, int pnv){
  pin[0]=pn1;
  pin[1]=pn2;
  pinVel=pnv;
};
