/*
  https://github.com/sui77/rc-switch/
  https://github.com/sui77/rc-switch/blob/master/examples/ReceiveDemo_Simple/ReceiveDemo_Simple.ino
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
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
unsigned int Value ;

void setup() {
  Serial.begin(115200);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => NANO@2, STM32@PA0 
}

void loop() {
  if (mySwitch.available()) {

    Value = mySwitch.getReceivedValue();

    Serial.print("Received ");
    Serial.print( mySwitch.getReceivedValue() ); 
    Serial.print(":");
    Serial.print( Value );
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( mySwitch.getReceivedProtocol() );

    mySwitch.resetAvailable();
  }
}
