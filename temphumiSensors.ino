// Read Sensors[DHT11, DHT22, AHT10, HTU21D, BME280]

#include <Wire.h>                       // I2C
#include <DHT.h>                        // DHT11, DHT22
#include <AHT10.h>                      // AHT10
#include <SparkFunHTU21D.h>             // HTU21D
#include <cactus_io_BME280_I2C.h>       // BME280

DHT dht11(4, DHT11);                    // DHT11
DHT dht22(5, DHT22);                    // DHT22
AHT10 aht10(AHT10_ADDRESS_0X38);        // AHT10
HTU21D htu21d;                          // HTU21D
BME280_I2C bme(0x76);                   // BME280

void setup()
{
  Serial.begin(9600);
  dht11.begin();          // DHT11
  dht22.begin();          // DHT22
  aht10.begin();          // AHT10
  htu21d.begin();         // HTU21D
  bme.begin();            // BME280
  bme.setTempCal(-1.5);   // BME280

  Serial.println(F("Read Sensors[DHT11, DHT22, AHT10, HTU21D, BME280]"));
}

void loop()
{
  Serial.print(F("DHT11Tem : "));  Serial.print(dht11.readTemperature()); Serial.print("\t");
  Serial.print(F("DHT11Hum : "));  Serial.println(dht11.readHumidity());

  Serial.print(F("DHT22Tem : "));  Serial.print(dht22.readTemperature()); Serial.print("\t");
  Serial.print(F("DHT22Hum : "));  Serial.println(dht22.readHumidity());

  Serial.print(F("AHT10Tem : "));  Serial.print(aht10.readTemperature()); Serial.print("\t");
  Serial.print(F("AHT10Hum : "));  Serial.println(aht10.readHumidity());

  Serial.print(F("HTU21Tem : "));  Serial.print(htu21d.readTemperature()); Serial.print("\t");
  Serial.print(F("HTU21Hum : "));  Serial.println(htu21d.readHumidity());

  delay(1000);

  bme.readSensor();
  Serial.print(F("BME28Tem : "));  Serial.print(bme.getTemperature_C());   Serial.print("\t");
  Serial.print(F("BME28Hum : "));  Serial.println(bme.getHumidity());

  float tempAvrg = ( dht11.readTemperature() + dht22.readTemperature() + aht10.readTemperature() +  htu21d.readTemperature() + bme.getTemperature_C() ) / 5;
  float humiAvrg = ( dht11.readHumidity() + dht22.readHumidity() + aht10.readHumidity() +  htu21d.readHumidity() + bme.getHumidity() ) / 5;

  Serial.println("-----------------------------------------");
  Serial.print(F("TempAvrg : "));  Serial.print(tempAvrg);   Serial.print("\t");
  Serial.print(F("HumiAvrg : "));  Serial.println(humiAvrg);
  Serial.println("-----------------------------------------");
  delay(2000);
}
