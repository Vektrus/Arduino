float temperatura; //Utworzenie zmiennej przechowującej temperaturę
int LM35 = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
 temperatura = analogRead(LM35); //Odczytanie napięcia z czujnika temperatury
 temperatura = temperatura * 0.48828125; //Wyznaczenie temperatury

  Serial.print("Temperatura: ");
  Serial.println(temperatura);
   
   delay(1000); //Odświeżanie co 1 sekundę
}
