#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const int LED=12;

void setup()
{pinMode(LED, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop()
{   delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if(h>75){ digitalWrite(LED, HIGH);
  delayMicroseconds(50);
  digitalWrite(LED, LOW);
  delayMicroseconds(50);}

  else{
digitalWrite(LED, LOW);
  }

  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("% Temperature ");
  Serial.print(t);
  Serial.println(" *C");
}