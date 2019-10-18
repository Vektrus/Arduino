#define lewo 4 
#define prawo 5 
#define gora 6 
#define dol 7 

#include <Wire.h>
#include<PCF8574.h>
PCF8574 expander;



void setup() {
  expander.begin(0x20);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  expander.pinMode(4,INPUT);
  expander.pinMode(5,INPUT);
  expander.pinMode(6,INPUT);
  expander.pinMode(7,INPUT);
}


void loop() {
  
  /*Serial.println(expander.digitalRead(lewo));
  delay(1);
  Serial.println(expander.digitalRead(prawo));
  delay(1);
  Serial.println(expander.digitalRead(gora));
  delay(1);
  Serial.println(expander.digitalRead(dol));*/
  if(stan_przycisku(7)== true){
    digitalWrite(8,HIGH);
  delay(1000);
  digitalWrite(8,LOW);
  }
  delay(100);
  if(stan_przycisku(6)== true){
    digitalWrite(8,HIGH);
  delay(1000);
  digitalWrite(8,LOW);
  }
  delay(100);
  if(stan_przycisku(5)== true){
    digitalWrite(8,HIGH);
  delay(1000);
  digitalWrite(8,LOW);
  }
  delay(100);
  if(stan_przycisku(4)== true){
    digitalWrite(8,HIGH);
  delay(1000);
  digitalWrite(8,LOW);
  }
  delay(100);
  
}

bool stan_przycisku(int nazwa_pinu){
  if(expander.digitalRead(nazwa_pinu)== HIGH){ 
    return (true);
    }
  else{ 
    return (false);
    }
}
