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
#include <Wire.h>
#include <cactus_io_BME280_I2C.h>

BME280_I2C bme(0x76);                     // I2C using address 0x76

void setup()
{
  Serial.begin(115200);
  bme.begin();
  bme.setTempCal(-1.0);
}

void loop()
{
  bme.readSensor();

  Serial.print(F("Temperature: ")); Serial.print(bme.getTemperature_C());
  Serial.print("\t");
  Serial.print(F("Humidity: ")); Serial.println(bme.getHumidity());
  delay(3000);
}
