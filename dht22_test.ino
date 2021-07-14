#include "DHTesp.h" // Click here to get the library: http://librarymanager/All#DHTesp

#ifdef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP8266 ONLY!)
#error Select ESP8266 board.
#endif

DHTesp dht;

void setup()
{
  Serial.begin(115200);
  
  dht.setup(2, DHTesp::DHT22); // DHT22 센서를 ESP8266 D4(GPIO2) 핀에 연결
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  Serial.print("Status : ");
  Serial.print(dht.getStatusString());
  Serial.print("  ");
  Serial.print("Humidity : ");
  Serial.print(humidity, 1);
  Serial.print("  ");
  Serial.print("Temperature : ");
  Serial.print(temperature, 1);
  Serial.println("");
  
  delay(2000);
}