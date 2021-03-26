/*
 Dado electrónico
 Carlos Orts
*/

#include "dadolib.h";

// variables 
int ButtonState = 0;     // variable para el estado de pulsación del botón

void setup() {
  Serial.begin(115200);
  // initializa los pines digitales de los LEDs como output:
  pinMode(LedArribaIzquierda, OUTPUT);
  pinMode(LedArribaCentro, OUTPUT);
  pinMode(LedArribaDerecha, OUTPUT);
  pinMode(LedCentro, OUTPUT);
  pinMode(LedAbajoIzquiera, OUTPUT);
  pinMode(LedAbajoCentro, OUTPUT);
  pinMode(LedAbajoDerecha, OUTPUT);
  // initializa el pin digitales del botón como output:
  pinMode(BotonPin, INPUT);
  // Inicializa la secuencia semi-aleatoria en la posición de la lectura de la entrada analógica.
  // Esto evita que la secuencia de numeros aleatoríos optenidos con ramdon, empiece siempre igual.
  //randomSeed(analogRead(0));
}

// Activa los puertos de los LEDs correspondientes al número generado
void ShowNumber(int Numero){
    Serial.println(Numero);
    switch (Numero) {
      case 1:
        one();
        break;
      case 2:
        two();
        break;
      case 3:
        three();
        break;
      case 4:
        four();
        break;
      case 5:
        five();
        break;
      case 6:
        six();
        break;
      case 7:
        seven();
        break;
    }
}

void loop() {
  // Lee el estado del botón
  ButtonState = digitalRead(BotonPin);

  // Si se pulsa el botón (ButtonState=HIGH):
  if (ButtonState == HIGH) {
    ShowNumber(random(1,8));  // Obtenemos un número aleatorio de 1 a 7
    delay(1000);              // Se espera 1 segundo (1000 ms)
    TurnOffAll();             // Se apagan todos los LEDs
  }
}
