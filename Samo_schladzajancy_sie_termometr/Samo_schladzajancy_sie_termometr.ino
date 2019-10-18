float temperatura; //Utworzenie zmiennej przechowującej temperaturę
int LM35 = 0;

void setup() {
 Serial.begin(9600);
  pinMode(6, OUTPUT); //Sygnał PWM silnika nr 1
  digitalWrite(6, LOW); //Ustawiamy (na stałe) stan wysoki na pinie 6
  
  pinMode(7, OUTPUT); //Sygnały sterujące kierunkiem obrotów silnika nr 1
  pinMode(8, OUTPUT);
  digitalWrite(7, LOW); //Silnik obroty w lewo
  digitalWrite(8, HIGH); 
}

void loop() {
 temperatura = analogRead(LM35); //Odczytanie napięcia z czujnika temperatury
 temperatura = temperatura * 0.48828125; //Wyznaczenie temperatury

  Serial.print("Temperatura: ");
  Serial.println(temperatura);
   if(temperatura>=31){
    digitalWrite(6, HIGH);
   }
   if(temperatura<31){
    digitalWrite(6, LOW);
   }
   delay(1000); //Odświeżanie co 1 sekundę

}
