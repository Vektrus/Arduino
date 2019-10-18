#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

#include <LiquidCrystal.h>
#include <Wire.h>
#include<PCF8574.h>
PCF8574 expander;
int parametry_strzalu[30][2][2];
int pozycja_gracza;
int parametry_wroga[10][2][2];
int tik,tikk;
int wynik,przegrana,tik_przegranej;
LiquidCrystal lcd(12,11,5,4,3,2);
// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int thisNote = 0;
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  10, 8, 8, 4, 4, 4, 4, 4
};


byte gracz_lewy[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00011,
  0b00111,
  0b00011
};
byte gracz_prawy[8] = {
  0b00011,
  0b00111,
  0b00011,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
byte asteroida_lewy[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00110,
  0b01111,
  0b00110
};
byte asteroida_prawy[8] = {
  0b00110,
  0b01111,
  0b00110,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
byte pocisk_lewy[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b01100,
  0b00000
};
byte pocisk_prawy[8] = {
  0b00000,
  0b01100,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
byte dwie_asteroidy[8] = {
  0b00110,
  0b01111,
  0b00110,
  0b00000,
  0b00000,
  0b00110,
  0b01111,
  0b00110
};
byte u_zamkniente[8] = {
  0b00010,
  0b00100,
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b01110,
  0b00000
};
int poczatek;
void setup() {
  lcd.createChar(0,gracz_lewy);
  lcd.createChar(1,gracz_prawy);
  lcd.createChar(2,asteroida_lewy);
  lcd.createChar(3,asteroida_prawy);
  lcd.createChar(4,pocisk_lewy);
  lcd.createChar(5,pocisk_prawy);
  lcd.createChar(6,dwie_asteroidy);
  lcd.createChar(7,u_zamkniente);
  
  pinMode(A0, INPUT);
  expander.begin(0x20);
  tik=0;
  tikk=0;
  pozycja_gracza=1;
  Serial.begin(9600);
  randomSeed(analogRead(0));
  poczatek=0;
  lcd.begin(16,2);
  lcd.print("Atak Asteroid");
  lcd.setCursor(13,0);
  lcd.print((char)7);
  lcd.setCursor(14,0);
  lcd.print("w");
  lcd.setCursor(0,1);
  lcd.print("Kliknij Guzik");
  wynik=0;
  przegrana=0;
  tik_przegranej=0;
}

void loop() {
  if(przegrana==1){
    poczatek=0;
    for(int c=0; c<30;c++){
      parametry_strzalu[c][0][0]=0;
    }
    for(int c=0; c<10;c++){
      parametry_wroga[c][0][0]=0;
    }
    lcd.clear();
    if(tik_przegranej==1){
      tik_przegranej=0;
      lcd.setCursor(0,0);
      lcd.print("Tw");
      lcd.print((char)7);
      lcd.print("j Wynik");
      lcd.setCursor(11,0);
      lcd.print(wynik);
      
    }
    else if(tik_przegranej==0){
      tik_przegranej=1;
      lcd.setCursor(0,0);
      
      lcd.print("Koniec Gry");
    
      
    }
    lcd.setCursor(0,1);
    lcd.print("Kliknij Guzik");
    delay(1000);
  }
  
  
  if(expander.digitalRead(1)==HIGH || expander.digitalRead(0)==HIGH || expander.digitalRead(2)==HIGH || poczatek==1){
    poczatek=1;
    if(przegrana==1){
      przegrana=0;
      wynik=0;
    }
  if(pozycja_gracza==1){
    lcd.clear();
    lcd.setCursor(15,0);
    lcd.print((char)0);
  }

 
  if(pozycja_gracza==0){
    lcd.begin(16,2);
    lcd.setCursor(15,0);
    lcd.print((char)1);
  }
    if(pozycja_gracza==2){
    lcd.begin(16,2);
    lcd.setCursor(15,1);
    lcd.print((char)1);
  }
    if(pozycja_gracza==3){
    lcd.begin(16,2);
    lcd.setCursor(15,1);
    lcd.print((char)0);
  }
  if(expander.digitalRead(0)==HIGH){
    pozycja_gracza++;
  }
  
  if(expander.digitalRead(1)==HIGH){
    pozycja_gracza--;
  }
  if(pozycja_gracza<0){
    pozycja_gracza=0;
  }
  if(pozycja_gracza>3){
    pozycja_gracza=3;
  }
  if(tikk==2){
    tikk=0;
   for(int c=0; c<30;c++){
    if(parametry_strzalu[c][0][0]==1){
      parametry_strzalu[c][1][0]--;
      if(parametry_strzalu[c][1][0]<0){
       parametry_strzalu[c][0][0]=0; 
      }
    }
    
   }
  }
  else{
    tikk++;
  }
    if(expander.digitalRead(2)==HIGH){
      for(int c=0; c<30;c++){
        if(parametry_strzalu[c][0][0]==0){
          parametry_strzalu[c][0][0]=1;
          parametry_strzalu[c][1][0]=14;
          parametry_strzalu[c][0][1]=pozycja_gracza;
          
          break;
        }
        
        
      }
  }
  for(int c=0; c<30;c++){
    for(int v=0; v<30;v++){
      if(parametry_strzalu[c][0][1]==parametry_strzalu[v][0][1]&&c!=v&&parametry_strzalu[c][1][0]==parametry_strzalu[v][1][0] && parametry_strzalu[v][0][0]==1 && parametry_strzalu[c][0][0]==1){
        parametry_strzalu[v][0][0]=0;
    }
  }
  }
  if(tik==6){
   tik=0;
   for(int c=0; c<10;c++){
      if(parametry_wroga[c][0][0]==1){
        parametry_wroga[c][0][1]++;
        
      }
    
    }
  }
  else{
    tik++;
  }
  Serial.println(random(5));
  switch(random(140)){
    case 0:
     for(int c=0; c<10;c++){
      if(parametry_wroga[c][0][0]==0){
        parametry_wroga[c][0][0]=1;
        parametry_wroga[c][1][0]=0;
        parametry_wroga[c][0][1]=0;
        break;
      }
     }
     break;
     case 1:
     for(int c=0; c<10;c++){
      if(parametry_wroga[c][0][0]==0){
        parametry_wroga[c][0][0]=1;
        parametry_wroga[c][1][0]=1;
        parametry_wroga[c][0][1]=0;
        break;
      }
     }
     break;
     case 2:
     for(int c=0; c<10;c++){
      if(parametry_wroga[c][0][0]==0){
        parametry_wroga[c][0][0]=1;
        parametry_wroga[c][1][0]=2;
        parametry_wroga[c][0][1]=0;
        break;
      }
     }
     case 3:
     for(int c=0; c<10;c++){
      if(parametry_wroga[c][0][0]==0){
        parametry_wroga[c][0][0]=1;
        parametry_wroga[c][1][0]=3;
        parametry_wroga[c][0][1]=0;
        break;
      }
     }
     break;
     break;
     default: 
     break;
  }
  for(int c=0; c<10;c++){
    for(int v=0; v<10;v++){
      if(parametry_wroga[c][0][1]==parametry_wroga[v][0][1] && c!=v && parametry_wroga[c][1][0]==parametry_wroga[v][1][0] && parametry_wroga[v][0][0]==1 && parametry_wroga[c][0][0]==1){
        parametry_wroga[v][0][0]=0;
      }
    }
  }
  for(int c=0; c<10;c++){
    if(parametry_wroga[c][0][0]==1){
      for(int v=0; v<30;v++){
        if(parametry_strzalu[v][0][0]==1){
          if((parametry_strzalu[v][1][0]==parametry_wroga[c][0][1]&&parametry_strzalu[v][0][1]==parametry_wroga[c][1][0])||((parametry_strzalu[v][1][0])+1==parametry_wroga[c][0][1]&&parametry_strzalu[v][0][1]==parametry_wroga[c][1][0])||((parametry_strzalu[v][1][0])-1==parametry_wroga[c][0][1]&&parametry_strzalu[v][0][1]==parametry_wroga[c][1][0])){
            parametry_wroga[c][0][0]=0;
            parametry_strzalu[v][0][0]=0;
            wynik++;
                  // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDurationn = 1000 / noteDurations[thisNote];
    tone(8, melody[1], noteDurationn);
          // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotess = noteDurationn * 1.30;
    delay(pauseBetweenNotess);
    // stop the tone playing:
    noTone(8); 
          }
        }
      }
    }
  }
  for(int c=0; c<10;c++){
    if(parametry_wroga[c][0][0]==1){
      if(parametry_wroga[c][0][1]>15){
        parametry_wroga[c][0][0]=0;
        przegrana=1;
      }
    }
  }
  for(int c=0; c<10;c++){
    if(parametry_wroga[c][0][0]==1){
      if(parametry_wroga[c][1][0]==0){
        lcd.setCursor(parametry_wroga[c][0][1],0);
        lcd.print((char)3);
      }
      if(parametry_wroga[c][1][0]==1){
        lcd.setCursor(parametry_wroga[c][0][1],0);
        lcd.print((char)2);
      }
      if(parametry_wroga[c][1][0]==2){
        lcd.setCursor(parametry_wroga[c][0][1],1);
        lcd.print((char)3);
      }
      if(parametry_wroga[c][1][0]==3){
        lcd.setCursor(parametry_wroga[c][0][1],1);
        lcd.print((char)2);
      }
    }
  }
  for(int c=0; c<10;c++){
     for(int v=0; v<10;v++){
        if(parametry_wroga[c][0][1]==parametry_wroga[v][0][1]&&parametry_wroga[c][1][0]==0&&parametry_wroga[v][1][0]==1 && parametry_wroga[v][0][0]==1 && parametry_wroga[c][0][0]==1){
          lcd.setCursor(parametry_wroga[c][0][1],0);
          lcd.print((char)6);
        }
        if(parametry_wroga[c][0][1]==parametry_wroga[v][0][1]&&parametry_wroga[c][1][0]==2&&parametry_wroga[v][1][0]==3 && parametry_wroga[v][0][0]==1 && parametry_wroga[c][0][0]==1){
          lcd.setCursor(parametry_wroga[c][0][1],1);
          lcd.print((char)6);
        }
     }
  }
  for(int c=0; c<30;c++){
    if(parametry_strzalu[c][0][0]==1){
      if(parametry_strzalu[c][0][1]==0||parametry_strzalu[c][0][1]==1){
        lcd.setCursor(parametry_strzalu[c][1][0],0);
        if(parametry_strzalu[c][0][1]==0){
          lcd.print((char)5);
        }
        if(parametry_strzalu[c][0][1]==1){
          lcd.print((char)4);
        } 
      }
      if(parametry_strzalu[c][0][1]==2||parametry_strzalu[c][0][1]==3){
        lcd.setCursor(parametry_strzalu[c][1][0],1);
        if(parametry_strzalu[c][0][1]==2){
          lcd.print((char)5);
        }
        if(parametry_strzalu[c][0][1]==3){
          lcd.print((char)4);
        } 
      }
      
    }
  }
  

  delay(100);
}
}
