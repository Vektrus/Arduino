#define czerwony 11
#define niebieski 9
#define zielony 10
#define tri 7
#define echo 6
#define zmien_par 13
#define zmien_par_g 1
#define zmien_par_b 0

#include <LiquidCrystal.h>


LiquidCrystal lcd(12,8,5,4,3,2);
int x,y,z;
int od_x,od_y,od_z;
int zmieniasz_to;
int bylo_wyl_po_r,bylo_wyl_po_g,bylo_wyl_po_b,bylo_wyl;

void setup() {
  pinMode(czerwony, OUTPUT); 
  pinMode(niebieski, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(tri, OUTPUT);
  pinMode(zielony, OUTPUT);
  pinMode(zmien_par,INPUT);
  pinMode(zmien_par_b,INPUT);
  pinMode(zmien_par_g,INPUT);
  digitalWrite(czerwony, HIGH);
  digitalWrite(niebieski, HIGH);
  digitalWrite(zielony, HIGH);

  
  x=255;
  y=255;
  z=255;
od_z=255-z;
od_x=255-x;
od_y=255-y;
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("RGB= ");
lcd.print(od_x);
lcd.print(",");
lcd.setCursor(9,0);
lcd.print(od_y);
lcd.print(",");
lcd.setCursor(13,0);
lcd.print(od_z);
lcd.setCursor(0,1);
lcd.print("WYBIERZ PAR.");
zmieniasz_to=0;
Serial.begin(9600);
bylo_wyl=1;
bylo_wyl_po_r=0;
bylo_wyl_po_b=0;
bylo_wyl_po_g=0;
}



void loop() {
long czas,odleglosc;
digitalWrite(tri,HIGH);
delay(10);
digitalWrite(tri,LOW);
czas = pulseIn(echo, HIGH);
odleglosc=czas/58;

if((digitalRead(zmien_par)== HIGH)&&(zmieniasz_to==0)&&(bylo_wyl==1)){
  lcd.begin(16,2);
  lcd.setCursor(0,1);
  lcd.print("ZMIENIASZ PAR. R"); 
  zmieniasz_to=1;  
}
if((digitalRead(zmien_par)== HIGH)&&(zmieniasz_to==1)&&(bylo_wyl_po_r==1)){
  lcd.begin(16,2);
  lcd.setCursor(0,1);
  lcd.print("ZMIENIASZ PAR. G"); 
  zmieniasz_to=2;  
}
if((digitalRead(zmien_par)== HIGH)&&(zmieniasz_to==2)&&(bylo_wyl_po_g==1)){
  lcd.begin(16,2);
  lcd.setCursor(0,1);
  lcd.print("ZMIENIASZ PAR. B"); 
  zmieniasz_to=3;  
}
if((digitalRead(zmien_par)== HIGH)&&(zmieniasz_to==3)&&(bylo_wyl_po_b==1)){
  lcd.begin(16,2);
  lcd.setCursor(0,1);
  lcd.print("WYBIERZ PAR."); 
  zmieniasz_to=0;  
}
if((digitalRead(zmien_par)== LOW)&&(zmieniasz_to==1)){
  bylo_wyl=0;
  bylo_wyl_po_r=1;
}

if((digitalRead(zmien_par)== LOW)&&(zmieniasz_to==2)){
  bylo_wyl_po_r=0;
  bylo_wyl_po_g=1;
}
if((digitalRead(zmien_par)== LOW)&&(zmieniasz_to==3)){
  bylo_wyl_po_g=0;
  bylo_wyl_po_b=1;
}
if((digitalRead(zmien_par)== LOW)&&(zmieniasz_to==0)){
  bylo_wyl_po_b=0;
  bylo_wyl=1;
}
/*if(digitalRead(zmien_par_r)==LOW){
  lcd.begin(16,2);
  lcd.setCursor(0,1);
  lcd.print("WYBIERZ PAR."); 
  zmieniasz_to=0;
}
if(digitalRead(zmien_par_g)==LOW){
  lcd.begin(16,2);
  lcd.setCursor(0,1);
  lcd.print("WYBIERZ PAR."); 
  zmieniasz_to=0;
}
if(digitalRead(zmien_par_b)==LOW){
  lcd.begin(16,2);
  lcd.setCursor(0,1);
  lcd.print("WYBIERZ PAR."); 
  zmieniasz_to=0;
}

if(digitalRead(zmien_par_r)==HIGH){
  lcd.begin(16,2);
  lcd.setCursor(0,1);
  lcd.print("ZMIENIASZ PAR. R"); 
  zmieniasz_to=1;
}


if(digitalRead(zmien_par_g)==HIGH){
  lcd.begin(16,2);
  lcd.setCursor(0,1);
  lcd.print("ZMIENIASZ PAR. G"); 
  zmieniasz_to=2;
}


if(digitalRead(zmien_par_b)==HIGH){
  
  lcd.setCursor(0,1);
  lcd.print("ZMIENIASZ PAR. B"); 
  zmieniasz_to=3;
}*/

if(odleglosc>255){
  odleglosc=255;
  Serial.print(odleglosc);
  Serial.print("\n");
}
if(zmieniasz_to==1){
 x=odleglosc; 
}

if(zmieniasz_to==2){
 y=odleglosc; 
}

if(zmieniasz_to==3){
 z=odleglosc; 
}
od_x=255-x;
od_y=255-y;
od_z=255-z;

lcd.setCursor(0,0);
lcd.print("RGB= ");
lcd.print(od_x);
lcd.print(",");
lcd.setCursor(9,0);
lcd.print(od_y);
lcd.print(",");
lcd.setCursor(13,0);
lcd.print(od_z);

analogWrite(czerwony,x);
analogWrite(niebieski,z);
analogWrite(zielony,y);
delay(300);
}
