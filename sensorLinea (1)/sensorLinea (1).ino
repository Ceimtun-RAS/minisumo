int sensor = A1;
int aviso = 3;
int estado = 0;
int maximo = 1;
int minimo = 1300;
int sencibilidad=30;//valor entre 1-100; recomndacion menor a 40
void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(aviso, OUTPUT);
  Serial.println("calibrar... ");
  calibrar();



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
void loop() {
  //delay(100);
  estado = analogRead(sensor);
  //delay(100);
  if (estado <(((maximo-minimo)/2)-maximo*sencibilidad/100)) {
    Serial.println("blanc09o  ");
    Serial.print(estado);
  }
  else {
    Serial.println("negro  ");
    Serial.print(estado);
  }
}
