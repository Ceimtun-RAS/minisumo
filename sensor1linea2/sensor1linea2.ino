
int sensor1 = 1;
int sensor2 = 4;
double LDD;
double LDI;   
int AIN2 = 2;
int AIN1 = 3;
int BIN1 = 5;
int BIN2 = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor1,INPUT);
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
}


void lectura(){
  LDD = analogRead(sensor1);
  LDI = analogRead(sensor2);
  LDD = 85383 * pow(LDD, -1.383);
  LDI = 85383 * pow(LDI, -1.383);    
}

void motores(){
  digitalWrite(AIN1,1);
  digitalWrite(AIN2,0);        
}


void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(analogRead(sensor1));
  delay(100);
  lectura();
  motores();
  Serial.println("Lderecho:" );
  Serial.println(LDD);
  Serial.println("Lizquierdo:");
  Serial.println(LDI);
}
