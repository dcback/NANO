// 1-Switch 3-LED Control(Toggle)
// https://www.mekanizmalar.com/arduino-five-led-control-in-sequence-with-a-button.html

const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPin1 = 3;    // the number of the LED pin
const int ledPin2 = 4;    // the number of the LED pin
const int ledPin3 = 5;    // the number of the LED pin

// variables will change:
int buttonState = 0;      // variable for reading the pushbutton status
int buttonPressCount = 1; // Initial Condition for ledPin1
int numberOfLED = 3;

void setup()
{
  Serial.begin(115200);

  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  digitalWrite(ledPin1, HIGH);
}

void loop()
{
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    if (buttonPressCount % numberOfLED == 0)
      digitalWrite(ledPin1, HIGH); // turn LED1 on:
    else
      digitalWrite(ledPin1, LOW);

    if (buttonPressCount % numberOfLED == 1)
      digitalWrite(ledPin2, HIGH); // turn LED2 on:
    else
      digitalWrite(ledPin2, LOW);

    if (buttonPressCount % numberOfLED == 2)
      digitalWrite(ledPin3, HIGH); // turn LED3 on:
    else
      digitalWrite(ledPin3, LOW);

    buttonPressCount++;
  }
  delay(500);
  Serial.println(buttonPressCount);
  Serial.print("ledPin1 : " );  Serial.println(digitalRead(ledPin1));
  Serial.print("ledPin2 : " );  Serial.println(digitalRead(ledPin2));
  Serial.print("ledPin3 : " );  Serial.println(digitalRead(ledPin3));
}
