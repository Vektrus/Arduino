#define pierwsza_zielona 13
#define druga_zielona 12
#define trzecia_zielona 11
#define pierwsza_zulta 10
#define druga_zulta 9
#define trzecia_zulta 8
#define pierwsza_czerwona 7
#define druga_czerwona 6
#define trzecia_czerwona 5
#define tri 4
#define echo 3



void setup() {
  pinMode(echo, INPUT);
  pinMode(tri, OUTPUT);
  pinMode(pierwsza_zielona, OUTPUT);
  pinMode(druga_zielona, OUTPUT);
  pinMode(trzecia_zielona, OUTPUT);
  pinMode(pierwsza_zulta, OUTPUT);
  pinMode(druga_zulta, OUTPUT);
  pinMode(trzecia_zulta, OUTPUT);
  pinMode(pierwsza_czerwona, OUTPUT);
  pinMode(druga_czerwona, OUTPUT);
  pinMode(trzecia_czerwona, OUTPUT);
  digitalWrite(pierwsza_zielona, LOW);
  digitalWrite(druga_zielona, LOW);
  digitalWrite(trzecia_zielona, LOW);
  digitalWrite(pierwsza_zulta, LOW);
  digitalWrite(druga_zulta, LOW);
  digitalWrite(trzecia_zulta, LOW);
  digitalWrite(pierwsza_czerwona, LOW);
  digitalWrite(druga_czerwona, LOW);
  digitalWrite(trzecia_czerwona, LOW);

  
}
void loop() {
long czas,odleglosc;
digitalWrite(tri,HIGH);
delay(10);
digitalWrite(tri,LOW);
czas = pulseIn(echo, HIGH);
odleglosc=czas/58;

if(odleglosc>=36){
  digitalWrite(pierwsza_zielona, HIGH);
  digitalWrite(druga_zielona, LOW);
  digitalWrite(trzecia_zielona, LOW);
  digitalWrite(pierwsza_zulta, LOW);
  digitalWrite(druga_zulta, LOW);
  digitalWrite(trzecia_zulta, LOW);
  digitalWrite(pierwsza_czerwona, LOW);
  digitalWrite(druga_czerwona, LOW);
  digitalWrite(trzecia_czerwona, LOW);
  
}


else if(odleglosc>=32){
  digitalWrite(pierwsza_zielona, LOW);
  digitalWrite(druga_zielona, HIGH);
  digitalWrite(trzecia_zielona, LOW);
  digitalWrite(pierwsza_zulta, LOW);
  digitalWrite(druga_zulta, LOW);
  digitalWrite(trzecia_zulta, LOW);
  digitalWrite(pierwsza_czerwona, LOW);
  digitalWrite(druga_czerwona, LOW);
  digitalWrite(trzecia_czerwona, LOW);
  
}

else if(odleglosc>=28){
  digitalWrite(pierwsza_zielona, LOW);
  digitalWrite(druga_zielona, LOW);
  digitalWrite(trzecia_zielona, HIGH);
  digitalWrite(pierwsza_zulta, LOW);
  digitalWrite(druga_zulta, LOW);
  digitalWrite(trzecia_zulta, LOW);
  digitalWrite(pierwsza_czerwona, LOW);
  digitalWrite(druga_czerwona, LOW);
  digitalWrite(trzecia_czerwona, LOW);
  
}

else if(odleglosc>=24){
  digitalWrite(pierwsza_zielona, LOW);
  digitalWrite(druga_zielona, LOW);
  digitalWrite(trzecia_zielona, LOW);
  digitalWrite(pierwsza_zulta, HIGH);
  digitalWrite(druga_zulta, LOW);
  digitalWrite(trzecia_zulta, LOW);
  digitalWrite(pierwsza_czerwona, LOW);
  digitalWrite(druga_czerwona, LOW);
  digitalWrite(trzecia_czerwona, LOW);
  
}

else if(odleglosc>=20){
  digitalWrite(pierwsza_zielona, LOW);
  digitalWrite(druga_zielona, LOW);
  digitalWrite(trzecia_zielona, LOW);
  digitalWrite(pierwsza_zulta, LOW);
  digitalWrite(druga_zulta, HIGH);
  digitalWrite(trzecia_zulta, LOW);
  digitalWrite(pierwsza_czerwona, LOW);
  digitalWrite(druga_czerwona, LOW);
  digitalWrite(trzecia_czerwona, LOW);
  
}

else if(odleglosc>=16){
  digitalWrite(pierwsza_zielona, LOW);
  digitalWrite(druga_zielona, LOW);
  digitalWrite(trzecia_zielona, LOW);
  digitalWrite(pierwsza_zulta, LOW);
  digitalWrite(druga_zulta, LOW);
  digitalWrite(trzecia_zulta, HIGH);
  digitalWrite(pierwsza_czerwona, LOW);
  digitalWrite(druga_czerwona, LOW);
  digitalWrite(trzecia_czerwona, LOW);
  
}

else if(odleglosc>=12){
  digitalWrite(pierwsza_zielona, LOW);
  digitalWrite(druga_zielona, LOW);
  digitalWrite(trzecia_zielona, LOW);
  digitalWrite(pierwsza_zulta, LOW);
  digitalWrite(druga_zulta, LOW);
  digitalWrite(trzecia_zulta, LOW);
  digitalWrite(pierwsza_czerwona, HIGH);
  digitalWrite(druga_czerwona, LOW);
  digitalWrite(trzecia_czerwona, LOW);
  
}

else if(odleglosc>=8){
  digitalWrite(pierwsza_zielona, LOW);
  digitalWrite(druga_zielona, LOW);
  digitalWrite(trzecia_zielona, LOW);
  digitalWrite(pierwsza_zulta, LOW);
  digitalWrite(druga_zulta, LOW);
  digitalWrite(trzecia_zulta, LOW);
  digitalWrite(pierwsza_czerwona, LOW);
  digitalWrite(druga_czerwona, HIGH);
  digitalWrite(trzecia_czerwona, LOW);
  
}

else if(odleglosc<8){
  digitalWrite(pierwsza_zielona, LOW);
  digitalWrite(druga_zielona, LOW);
  digitalWrite(trzecia_zielona, LOW);
  digitalWrite(pierwsza_zulta, LOW);
  digitalWrite(druga_zulta, LOW);
  digitalWrite(trzecia_zulta, LOW);
  digitalWrite(pierwsza_czerwona, LOW);
  digitalWrite(druga_czerwona, LOW);
  digitalWrite(trzecia_czerwona, HIGH);
  
}
}
