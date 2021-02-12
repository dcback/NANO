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
#include <IRremote.h>

int irPin = 7;
IRrecv irrecv(irPin);
decode_results results;

void setup()
{
  Serial.begin(115200);
  irrecv.enableIRIn();  // 리모콘 시작
}

void loop()
{
  if (irrecv.decode(&results))              // 리모콘 누른값이 없다면 패스
  {
    Serial.print("results.decode_type : "); // 리모콘 타입
    Serial.println(results.decode_type);

    Serial.print("results.bits : ");        // 키값 길이
    Serial.println(results.bits);

    Serial.print("results.value : ");       // 키값
    Serial.println(results.value);

    Serial.print("results.value, HEX : ");  // 키값을 16진수로변환
    Serial.println(results.value, HEX);

    irrecv.resume(); // 다음 값
  }
}
