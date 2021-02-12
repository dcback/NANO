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
  /*************************************************
    [SPI]       ATm328p     STM32       ESP8266
    MOSI        D11         PA7         D7(GPIO13)
    MISO        D12         PA6         D6(GPIO12)
    SCK/CLK     D13         PA5         D5(GPIO14)
    NSS/CSN     D10         PA4         D8{GPIO15)
    NRESET      D8          PC14        D0(GPIO16)
    DIO0        D9          PC15        D1(GPIO5)
    VCC         3.3V        3.3V        3.3V
****************************************************
  Define(TX/RX, ARDUINO_NANO/BLUEPILL/NODEMCU)
***************************************************/
#define LORA_TX
//#define LORA_RX

#define ARDUINO_NANO
//#define BLUEPILL
//#define NODEMCU
//***************************************************

#ifdef ARDUINO_NANO
#define ledPin      13
#define csPin       10
#define resetPin    8
#define irqPin      9
#elif defined BLUEPILL
#define ledPin      PC13
#define csPin       PA4
#define resetPin    PC14
#define irqPin      PC15
#else //NODEMCU
#define ledPin      D4
#define csPin       D8
#define resetPin    D0
#define irqPin      D1
#endif

#include <SPI.h>
#include <LoRa.h>

int counter = 0;

// Functions()
void led_Blink();
void Init_Send();
void Init_Receive();
void LoRa_Send();
void LoRa_Receive();

void setup() {
#ifdef LORA_TX
  Init_Send();
#endif

#ifdef LORA_RX
  Init_Receive();
#endif
}

void loop() {
#ifdef LORA_TX
  LoRa_Send();
#endif

#ifdef LORA_RX
  LoRa_Receive();
#endif
}

// ===========================
// Functions()
// ===========================
void led_Blink() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}

void Init_Send() {
  Serial.begin(115200);
  //  while (!Serial);
  pinMode(ledPin, OUTPUT);

  LoRa.setPins(csPin, resetPin, irqPin);  // CS, RST, IRQ Pin Set
  Serial.println("LoRa Sender");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void Init_Receive() {
  Serial.begin(115200);
  //    while (!Serial);
  pinMode(ledPin, OUTPUT);

  LoRa.setPins(csPin, resetPin, irqPin);  // CS, RST, IRQ Pin Set
  Serial.println("LoRa Receiver");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void LoRa_Send() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();

  led_Blink();
  counter++;
}

void LoRa_Receive() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
    led_Blink();
  }
}
