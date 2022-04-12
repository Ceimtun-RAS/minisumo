}//MIDE DE 10CM A 78CM


//en este lado se cambian los pines del analogo 
int DD=4; //Delantero Derecho
int DI=5; //Delantero Izquierdo
int LD=7; //Lateral Derecho
int LI=6; //Lateral Izquierdo

int inches = 0;
//Lectura
double LDD = 0;
double LDI = 0;
double LLD = 0;
double LLI = 0;

void leer()
{
  //LECTURA INICIAL DE LOS SENSORES
   LDD = analogRead(DD);
   LDD = 85383 * pow(LDD, -1.383);
   LDI = analogRead(DD);
   LDI = 85383 * pow(LDD, -1.383);
   LLD = analogRead(DD);
   LLD = 85383 * pow(LDD, -1.383);
   LLI = analogRead(DD);
   LLI = 85383 * pow(LDD, -1.383);
  
} 

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(DD, INPUT);
  pinMode(DI, INPUT);
  pinMode(LD, INPUT);
  pinMode(LI, INPUT);
  Serial.begin(9600);
}

void loop() {
 leer()
}


/* 
 *   leer(); 
  Serial.println(LDD);
  delay(100);


//si no detecta nada
if(LDD>75 && LDI>75 && LLD>75 && LLI>75)
     {
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(9,  LOW);
      Serial.println("todo");
     }
//SI DETECTA LOS DOS DELANTEROS
else if((LDD>10 && LDD<75) && (LDI>10 && LDI<75))
{
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(9,  LOW);
      Serial.println("todo");

}
//SI DETECTA EL DERECHO
else if(LLD>10 && LLD<75)
{
  while((LDD>10 && LDD<75) && (LDI>10 && LDI<75))
  {
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(9,  LOW);
      Serial.println("todo");

    leer();
  }
}
//SI DETECTA EL IZQUIERDO
else if(LLI>10 && LLI<75)
{
  while((LDD>10 && LDD<75) && (LDI>10 && LDI<75))
  {
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(9,  HIGH);
      Serial.println("todo");

    leer();
  }
}
 *  
 *  
 *  
 *  /
 */
