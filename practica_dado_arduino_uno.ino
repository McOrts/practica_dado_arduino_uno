/*
 Carlos Orts
*/

// Constantes para asignar puertos digitales a los LED y al botón
const int BotonPin = 2;
const int Led1Pin = 13;
const int Led2Pin = 12;
const int Led3Pin = 11;
const int Led4Pin = 10;
const int Led3Pin =  9;
const int Led2Pin =  8;
const int Led1Pin =  7;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(115200);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    Serial.println(buttonState)
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    Serial.println(buttonState)
  }
}
