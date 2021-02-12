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
#define  buzzPin 6        // the PWM pin the buzzer is attached to

void setup()
{
}

void loop()
{
  tone(buzzPin, 262); // 도(C4)
  delay(500);
  tone(buzzPin, 294); // 레(D4)
  delay(500);
  tone(buzzPin, 330); // 미(E4)
  delay(500);
  tone(buzzPin, 349); // 파(F4)
  delay(500);
  tone(buzzPin, 392); // 솔(G4)
  delay(500);
  tone(buzzPin, 440); // 라(A4)
  delay(500);
  tone(buzzPin, 494); // 시(B4)
  delay(500);
  tone(buzzPin, 523); // 도(C5)
  delay(500);
  
  noTone(buzzPin);
  delay(3000);
}
