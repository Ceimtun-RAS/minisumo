
class Sensor{
  public:
  double r;
  byte pin;
  Sensor(byte pin){
    this->pin = pin;
    init();    
  }
  void init(){
    pinMode(pin,INPUT);
  }
  double getr(){
    return r;
  }
  void setr(double r){
    this->r = r;
  }
  double mag(){
    double magni = analogRead(pin);
    magni = 85383 * pow(magni, -1.383);
    return  magni;
  }
};
byte pinesProx[4] = {0,1,2,3};
  Sensor PLD(pinesProx[0]);//Sensor proximidad delantero izquierdo
  Sensor PDD(pinesProx[1]);
  Sensor PDI(pinesProx[2]);
  Sensor PLI(pinesProx[3]);
double r1,r2,r3,r4;
  
void posEnemigo(){  
 // Sensor PDD((5,5),);
 double posCh[4][2] = {{8,9},{5,5},{-5,5},{-5,0}}; //trae las posiciones de los sensores con respecto al chasis
 double uni[4][2] = {{1,0},{0,1},{0,1},{-1,0}}; //trae los vectores de cada 
 Sensor sensores[4] = {PLD,PDD,PDI,PLI};
  PLD.setr(PLD.mag());
  r1 = PLD.getr();
  PDD.setr(PDD.mag());
  r2 = PDD.getr(); 
  PDI.setr(PDI.mag());
  r3 = PDI.getr();
  PLI.setr(PLI.mag());
  r4 = PLI.getr();
  double magnitudes[4] = {r1,r2,r3,r4};
  
  double re[2]; 
  re[0] = (posCh[0][0] + posCh[1][0] + posCh[2][0] + posCh[3][0] + r3 - r4);
  re[1] = (posCh[0][1] + posCh[1][1] + posCh[2][1] + posCh[3][1] + r1 + r2 );
  double mag_re = sqrt(pow(re[0], 2) + pow(re[1],2));
  double ang = 0;
  
  Serial.println();
  delay(1000);
  //Serial.println(a);
  //double posE[2] = {0,0};
  //for (int i = 0; i < 4 ; i++){
  //  posE = posE + sensores[i].posicion(); 
  //}
}

void loop() {
  posEnemigo(); 
}

void setup(){
  Serial.begin(9600);
}


/*class Sensor{
  public:
  double posx;
  double posy;
  double vecx;
  double vecy;
  
  byte pin;
  Sensor(double posx,double posy,double vecx, double vecy,byte pin){
    this->pin = pin;
    this->posicion[2] = posicion[2];
    this->vector[2] = vector[2];
    init();    
  }
  void init(){
    pinMode(pin,INPUT);
  }
  double getPosicionX(){
    return posicion;
  }
  double magnitud(byte pin){
    double mag = analogRead(pin);
    mag = 85383 * pow(mag, -1.383);
    return  mag;
  }
};

void Main(){  
 // Sensor PDD((5,5),);
 double posChasis[4][2] = {{8,9},{5,5},{-5,5},{-5,0}}; //trae las posiciones de los sensores con respecto al chasis
 double vectores[4][2] = {{1,0},{0,1},{0,1},{-1,0}}; //trae los vectores de cada 
 byte pines[4] = {1,2,3,4};
  Sensor PLD(posChasis[0],vectores[0],pines[0]); //Sensor proximidad delantero izquierdo
  Sensor PDD(posChasis[1],vectores[1],pines[1]);
  Sensor PDI(posChasis[2],vectores[2],pines[2]);
  Sensor PLI(posChasis[3],vectores[3],pines[3]);
  // Serial.println(a[1][0]);
  Sensor sensores[4] = {PLD,PDD,PDI,PLI};

  double a = PLD.getPosicionX();
  
  Serial.println(a);
  //double posE[2] = {0,0};
  //for (int i = 0; i < 4 ; i++){
  //  posE = posE + sensores[i].posicion(); 
  //}
}
*/ 
