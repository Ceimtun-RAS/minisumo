//Sensores de proximidad 
int DD=0; //Delantero Derecho
int DI=3; //Delantero Izquierdo
//Lectura sensores de proximidad 
double LDD = 0;
double LDI = 0;
//Sensores de linea
int sensor = A1;
int aviso = 13;
int estado = 0;
int maximo = 1;
int minimo = 1300;
int sensibilidad=30;//valor entre 1-100; recomndacion menor a 40
//motores
boolean caerD = false;
boolean caerI = false;
boolean caerAtras = false; //se vuelve true cuando se detecta linea blanca en el sensor de atras
int Ld;
int Li;

void leer_proximidad(){
  //LECTURA INICIAL DE LOS SENSORES
   LDD = analogRead(DD);
   LDD = 85383 * pow(LDD, -1.383);
   LDI = analogRead(DI);
   LDI = 85383 * pow(LDI, -1.383);
   //Serial.println(LDD);
   //delay(1000);
   Serial.println(LDI);
   delay(1000);
}
void leer_linea() {
  delay(100);
  estado = analogRead(sensor);
  delay(100);
  if (estado <(((maximo-minimo)/2)-maximo*sensibilidad/100)) {
    Serial.println("blanco ");
    Serial.print(estado);
    caerAtras = true;
  }
  else {
    Serial.println("negro  ");
    Serial.print(estado);
    caerAtras = false; 
  }
}
void calibrar() {
  digitalWrite(aviso, 1);
  delay(1000);
  unsigned long tiempo = millis();
  digitalWrite(aviso, 0);
  while (millis() < tiempo + 5000) {
    estado = analogRead(sensor);
    if (estado > maximo) {
      maximo = estado;
    }
    else if (estado < minimo) {
      minimo = estado;
    }
  }
  digitalWrite(aviso, 1);
  delay(1000);
  tiempo = millis();
  digitalWrite(aviso, 0);
  while (millis() < tiempo + 5000) {
    estado = analogRead(sensor);
    if (estado > maximo) {
      maximo = estado;
    }
    else if (estado < minimo) {
      minimo = estado;
    }
  }
  digitalWrite(aviso, 1);
  delay(100);
  digitalWrite(aviso, 0);
  delay(100);
  digitalWrite(aviso, 1);
  delay(100);
  digitalWrite(aviso, 0);
  delay(100);
  digitalWrite(aviso, 1);
  delay(100);
  digitalWrite(aviso, 0);
    
  Serial.println(maximo);
  Serial.println(minimo);
}
void adelante(){
  analogWrite(6, 40);
  analogWrite(5, 40);
  digitalWrite(4, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
}
void giro_izq () {
  analogWrite(6, 40); //control velocidad
  analogWrite(5, 40); //control vel.
  digitalWrite(4, LOW); //motor 1
  digitalWrite(9, HIGH);
  digitalWrite(7, HIGH); //motor 2
  digitalWrite(8, LOW);     
}

void giro_der () {
  analogWrite(6, 255); //control velocidad
  analogWrite(5, 255); //control vel.
  digitalWrite(4, HIGH); //motor 1
  digitalWrite(9, LOW);
  digitalWrite(7,LOW); //motor 2
  digitalWrite(8,HIGH);     
}

void atras(){
  analogWrite(6, 255);
  analogWrite(5, 255);
  digitalWrite(4, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
}

void detener(){
   analogWrite(6, 0);
  analogWrite(5, 0);
  digitalWrite(4, LOW);
  digitalWrite(9, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //sensores de proximidad
  pinMode(DD, INPUT);
  pinMode(DI, INPUT);
  //sensores de linea
  pinMode(sensor, INPUT);
  pinMode(aviso, OUTPUT);
  calibrar();

  //motores
  pinMode(A6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(A7,INPUT);
  pinMode(A6,INPUT);
}

void logica(){
  //leer_proximidad();
  //leer_linea();
  if(caerAtras){
    adelante(); 
}else{
    detener();
  }



  delay(1000);
}

void loop() {
  
}
