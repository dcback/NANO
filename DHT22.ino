/*
                [NANO Pinout]
                  ----------
            TX=1-|   328P   |-VIN
            RX=0-|   NANO   |-GND
           RESET-|          |-RESET
             GND-|          |-5V
          INT0=2-|          |-A7
       INT1=3(~)-|          |-A6
               4-|          |-19=A5=SCL
            5(~)-|          |-18=A4=SDA
            6(~)-|          |-17=A3
               7-|          |-16=A2
               8-|          |-15=A1
            9(~)-|          |-14=A0
        SS=10(~)-|          |-AREF
      MOSI=11(~)-|    --    |-3V3
         MISO=12-|   |  |   |-13=SCK
                  ----------
*/
#include <DHT.h>

#define DHTPIN  7
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);
  dht.begin();
}

void loop()
{
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();

  Serial.print("temperature:");
  Serial.print(temp);
  Serial.print("\t");
  Serial.print("humidity:");
  Serial.println(humi);
  
  delay(1000);
}
