boolean caerD = false;
boolean caerI = false;
int Ld;
int Li;
void setup() {
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(A7,INPUT);
  pinMode(A6,INPUT);
  Serial.begin(9600);
}
void adelante(){
  analogWrite(6, 255);
  analogWrite(5, 255);
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

void linea(){
  //Serial.println(analogRead(Ld));
  //Serial.println(analogRead(Li));
  Li = analogRead(A7);
  Ld = analogRead(A6);
  if (Li > 1){
    caerI = true;
  }else{
    caerI = false;
  }
  if (Ld > 1){
    caerD = true;
  }else{
    caerD = false;
  }
}

void loop() {
  linea();
  if(caerI && caerD){
    atras();
    linea();
    delay(500);     
  }
  if(caerI && !caerD){
    giro_der();
    linea();
    delay(500);  
  }
  if(caerD && !caerI){
    giro_izq();
    linea();  
    delay(500);
  }
  if(!caerD && !caerI){
    adelante();
    linea();
    delay(500);
  }
  Serial.println(Ld);
  Serial.println(Li);
  //adelante();
  delay(500);
}
