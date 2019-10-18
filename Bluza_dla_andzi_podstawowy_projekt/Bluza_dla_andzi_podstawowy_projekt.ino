#define cztery 2
#define piec 4
#define szesc 6
#define siedem 8
#define dziewiec 9



int poz
ffcja_serca;
void setup() {
  pinMode(cztery, OUTPUT);
  pinMode(piec, OUTPUT);
  pinMode(szesc, OUTPUT);
  pinMode(siedem, OUTPUT);
  pinMode(dziewiec, OUTPUT);

  pozycja_serca = 0;
  digitalWrite(dziewiec, LOW);
  digitalWrite(siedem, LOW);
  digitalWrite(cztery, LOW);
  digitalWrite(piec, HIGH);
  digitalWrite(szesc, HIGH);
  
}

void loop() {
 if(pozycja_serca!=0){
  pozycja_serca=0;
  digitalWrite(dziewiec, LOW);
  digitalWrite(siedem, LOW);
  digitalWrite(cztery, HIGH);
  digitalWrite(piec, HIGH);
  digitalWrite(szesc, LOW);
  delay(100);
  digitalWrite(dziewiec, LOW);
  digitalWrite(siedem, LOW);
  digitalWrite(cztery, LOW);
  digitalWrite(piec, HIGH);
  digitalWrite(szesc, HIGH);
  
  }
  
  else if(pozycja_serca!=1){
  pozycja_serca=1;
  digitalWrite(dziewiec, LOW);
  digitalWrite(siedem, LOW);
  digitalWrite(cztery, HIGH);
  digitalWrite(piec, HIGH);
  digitalWrite(szesc, LOW);
  delay(100);
  digitalWrite(dziewiec, HIGH);
  digitalWrite(siedem, HIGH);
  digitalWrite(cztery, LOW);
  digitalWrite(piec, LOW);
  digitalWrite(szesc, LOW);
  
  }
  delay(300);
}
