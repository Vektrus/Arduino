#include "DHT.h"
#define DHT11_PIN 13
DHT dht;
 
void setup()
{
  Serial.begin(9600);
  dht.setup(DHT11_PIN);
}
 
void loop()
{
  //Pobranie informacji o wilgotnosci
  int wilgotnosc = dht.getHumidity();
  //Pobranie informacji o temperaturze
  int temperatura = dht.getTemperature();
  
  if (dht.getStatusString() == "OK") {
    Serial.print(wilgotnosc);
    Serial.print("%RH | ");
    Serial.print(temperatura);
    Serial.println("*C");
  }
  
  //Odczekanie wymaganego czasugo
  delay(dht.getMinimumSamplingPeriod());
}
