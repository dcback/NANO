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
int ledPin  =   13;
int PIR     =   A0;

void setup() {
  pinMode(ledPin, OUTPUT);   // initalize LED as an output
  pinMode(PIR, INPUT);    // initialize sensor as an input
  Serial.begin(115200);     // initialize serial
}

void loop() {
  if (digitalRead(PIR) == HIGH) { // check if the sensor is HIGH
    digitalWrite(ledPin, HIGH);      // turn LED ON
    Serial.println("Motion detected!");
    delay(100);                   // delay 100 milliseconds
  }
  else {
    digitalWrite(ledPin, LOW);       // turn LED OFF
    Serial.println("Motion stopped!");
    delay(100);                   // delay 100 milliseconds
  }
}
