int s1 = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,INPUT);
  pinMode(1,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(digitalRead(13));
  Serial.println(analogRead(1));  
  delay(100);
}
