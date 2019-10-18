int x, pozycja_serca, x_time, beat, pulse, sensor;
void setup() {
  pinMode(A1, INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
  pozycja_serca=0;
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  x=0;
}

void loop() {
  Serial.println(analogRead(A1));
  sensor=analogRead(A1);
  delay(10);
  x_time++;
 // if(sensor>510)
  /*if(analogRead(A0)<510){
    x=1;
    
  }
  else{
    x=0;
  }
  
  if(x==1 && pozycja_serca!=0){
  pozycja_serca=0;
  digitalWrite(7, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  delay(100);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  delay(50);
  }
  else{
    delay(90);
  }
  if(x==0 && pozycja_serca!=1){
  pozycja_serca=1;
  digitalWrite(7, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  delay(100);
  digitalWrite(7, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(200);
  }
  else{
    delay(90);
  }*/
  
}
