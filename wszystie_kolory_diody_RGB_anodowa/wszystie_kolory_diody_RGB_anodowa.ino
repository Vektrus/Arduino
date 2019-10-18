void setup() {
  pinMode(11, OUTPUT); // Piny, podłączone do diody jako wyjścia
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);

}

void loop() {
  digitalWrite(11, HIGH); //niebieski
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);

  delay(2000);
            
  digitalWrite(11, LOW);    //czerwony
  digitalWrite(10, HIGH);
  digitalWrite(9,HIGH);
  delay(2000);
  
  digitalWrite(11, HIGH);   //zielony
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
 
  delay(2000); 
  digitalWrite(11, HIGH); //niebieski-zielony
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);

  delay(2000);
            
  digitalWrite(11, LOW);    //czerwony-zielony
  digitalWrite(10, LOW);
  digitalWrite(9,HIGH);
  delay(2000);
  
  digitalWrite(11, LOW);   //czerwony-niebieski
  digitalWrite(10, HIGH);
  digitalWrite(9,LOW);
 
  delay(2000);
  
  digitalWrite(11, LOW);   //biały
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
 
  delay(2000);
}
