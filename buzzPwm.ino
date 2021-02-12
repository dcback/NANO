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
int volume = 0;           // how loud the buzzer is
int fadeAmount = 5;       // how many points to fade the buzzer volume by

int duty_cycle = 127;     // 0-255 so 50% = 127 approx

void setup()
{
  pinMode(buzzPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop()
{
  analogWrite(buzzPin, volume);

  // change the volume for next time through the loop:
  volume = volume + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (volume <= 0 || volume >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 1~100 milliseconds to see the volume effect
  delay(10);
}
