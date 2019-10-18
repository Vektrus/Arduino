#include <LiquidCrystal.h>
LiquidCrystal lcd(12,8,5,4,3,2);

byte dinozaur[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00011,
  0b00011,
  0b10110,
  0b01110,
  0b00010
};
byte kaktus_1[8] = {
  0b00000,
  0b00000,
  0b00100,
  0b10100,
  0b10100,
  0b01100,
  0b00100,
  0b00100
};
byte kaktus_2[8] = {
  0b00000,
  0b00100,
  0b00101,
  0b00111,
  0b10100,
  0b11100,
  0b00100,
  0b00100
};
byte kaktus_3[8] = {
  0b10000,
  0b10000,
  0b10100,
  0b10100,
  0b11000,
  0b10000,
  0b10000,
  0b10000
};
byte kaktus_4[8] = {
  0b00100,
  0b00100,
  0b10100,
  0b10100,
  0b01101,
  0b00101,
  0b00110,
  0b00100
};
byte kaktus_5[8] = {
  0b00000,
  0b10000,
  0b10100,
  0b10100,
  0b10100,
  0b01100,
  0b00100,
  0b00100
};
byte kaktus_6[8] = {
  0b00100,
  0b00101,
  0b00101,
  0b10110,
  0b10100,
  0b01100,
  0b00100,
  0b00100
};
byte kaktus_7[8] = {
  0b00000,
  0b00100,
  0b00101,
  0b00101,
  0b00110,
  0b00100,
  0b00100,
  0b00100
};
int pozycja_gracza, pozycja_kaktusow [9][3];
int dlugoscSkoku, kaktusyZRzedu, punkty, poziomTrudnosci = 120;
bool ekranKoncowy;
void setup() {
pinMode(7,INPUT);
pinMode(A0, INPUT);
randomSeed(analogRead(0));
Serial.begin(9600);
lcd.createChar(0,dinozaur);
lcd.createChar(1,kaktus_1);
lcd.createChar(2,kaktus_2);
lcd.createChar(3,kaktus_3);
lcd.createChar(4,kaktus_4);
lcd.createChar(5,kaktus_5);
lcd.createChar(6,kaktus_6);
lcd.createChar(7,kaktus_7);
lcd.begin(16,2);
lcd.setCursor(0,0);


}

void stworz(int x){
  for(int s=0;s<9;s++){
    if(pozycja_kaktusow [s][0]==0){
      pozycja_kaktusow [s][0]=1;
      pozycja_kaktusow [s][1]=15;
      pozycja_kaktusow [s][2]=x;
      Serial.println("wrog stworzony");
      break;
    }
  }
}
void czekajXTik(int x){
  for(int s=0; s < x; s++){
    delay(100);
  }
}

void poruszenieKaktusow(){
  
  for(int s=0;s<9;s++){
    if(pozycja_kaktusow [s][0]==1){
      
      pozycja_kaktusow [s][1]--;
      
      
    }
  }
    
}

void rysowanieGracza(){
  lcd.clear();
  if(digitalRead(7)==HIGH && dlugoscSkoku <= 5){
    lcd.setCursor(0,0);  
    lcd.print((char)0);
    pozycja_gracza=0;
    dlugoscSkoku++;
    
  }
  else{
    pozycja_gracza=1;
    lcd.setCursor(0,1);  
    lcd.print((char)0);
    dlugoscSkoku=0;
 }
}
  
 void losowanieNowychKaktusow(){
  if(kaktusyZRzedu <= 4){
    kaktusyZRzedu++;
    
    switch(random(poziomTrudnosci)){
      case 1:
      stworz(1);
      break;
      case 2:
      stworz(2);
      break;
      case 3:
      stworz(3);
      break;
      case 4:
      stworz(4);
      break;
      case 5:
      stworz(5);
      break;
      case 6:
      stworz(6);
      break;
      case 7:
      stworz(7);
      break;
      default:
      kaktusyZRzedu=0;
      break;
  }
  }
  else{
    kaktusyZRzedu=0;
    }
  }
 
 void rysowanieKaktusow(){
  for(int s=0;s<9;s++){
    if(pozycja_kaktusow [s][0]==1){
      lcd.setCursor(pozycja_kaktusow[s][1],1);
      lcd.print((char)pozycja_kaktusow[s][2]);
      
      
    }


  
}
  
}
void przegrana(){
ekranKoncowy = true;  
}
void sprawdzenieCzyZyje(){
  for(int s=0;s<9;s++){
    if(pozycja_kaktusow [s][0]==1){
      
      
      if(pozycja_kaktusow [s][1] == 0 && pozycja_gracza == 1){
        przegrana();
      }
      else if(pozycja_kaktusow [s][1] == 0){
        
        pozycja_kaktusow [s][0]=0;
      
      }
      
    }
  }
}


void dodaniePunktow(){
punkty++;
if(poziomTrudnosci > 20){
 poziomTrudnosci--;
 Serial.println(poziomTrudnosci);
 }
}




void loop() {
  if(ekranKoncowy == false){
    rysowanieGracza();
    poruszenieKaktusow();
    sprawdzenieCzyZyje();
    losowanieNowychKaktusow();
    rysowanieKaktusow();
    
    dodaniePunktow();
    czekajXTik(4);
  }
  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("YOU LOSE");
    lcd.setCursor(0,1);
    lcd.print("SCORE: ");
    lcd.print(punkty);
    czekajXTik(10);
    if(digitalRead(7)==HIGH){
      ekranKoncowy = false;
      punkty = 0;
      poziomTrudnosci = 120;
      for(int s=0;s<9;s++){
        
          pozycja_kaktusow [s][0]=0;
          pozycja_kaktusow [s][1]=0;
          pozycja_kaktusow [s][2]=0;
          
          
    }
    }
  }
  
  
}
