/*
	Configuraciones y librerias para programda de dado
*/

// Constantes para asignar puertos digitales a los LED, botón y buzzer
const int BotonPin = 2;
const int LedArribaIzquierda = 13;
const int LedArribaCentro = 12;
const int LedArribaDerecha = 11;
const int LedCentro = 10;
const int LedAbajoIzquiera = 9;
const int LedAbajoCentro = 8;
const int LedAbajoDerecha = 7;
const int buzzer = 4;

// Rutina para emitir los beeps que corresponden a cada número  
void Sounds (int beeps)
{
  for (int i = 1; i <= beeps; i++) {
    tone(buzzer, 1000); // envia 1KHz sonido 
    delay(200);        
    noTone(buzzer);     // Stop sonido
    delay(200);      
  }
}

// Rutinas para encender los LEDs correspondientes a los números
void one()
{
  digitalWrite(LedCentro, HIGH);
  Sounds(1);
}

void two()
{
  digitalWrite(LedArribaIzquierda, HIGH);
  digitalWrite(LedAbajoDerecha, HIGH);
  Sounds(2);
}

void three()
{
  digitalWrite(LedArribaIzquierda, HIGH);
  digitalWrite(LedCentro, HIGH);
  digitalWrite(LedAbajoDerecha, HIGH);
  Sounds(3);
}

void four()
{
  digitalWrite(LedArribaIzquierda, HIGH);
  digitalWrite(LedArribaDerecha, HIGH);
  digitalWrite(LedAbajoIzquiera, HIGH);
  digitalWrite(LedAbajoDerecha, HIGH);
  Sounds(4);
}

void five()
{
  digitalWrite(LedArribaIzquierda, HIGH);
  digitalWrite(LedArribaDerecha, HIGH);
  digitalWrite(LedCentro, HIGH);
  digitalWrite(LedAbajoIzquiera, HIGH);
  digitalWrite(LedAbajoDerecha, HIGH);
  Sounds(5);
}

void six()
{
  digitalWrite(LedArribaIzquierda, HIGH);
  digitalWrite(LedArribaCentro, HIGH);
  digitalWrite(LedArribaDerecha, HIGH);
  digitalWrite(LedAbajoIzquiera, HIGH);
  digitalWrite(LedAbajoCentro, HIGH);
  digitalWrite(LedAbajoDerecha, HIGH);
  Sounds(6);
}

void TurnOffAll()
{
  digitalWrite(LedArribaIzquierda, LOW);
  digitalWrite(LedArribaCentro, LOW);
  digitalWrite(LedArribaDerecha, LOW);
  digitalWrite(LedCentro, LOW);
  digitalWrite(LedAbajoIzquiera, LOW);
  digitalWrite(LedAbajoCentro, LOW);
  digitalWrite(LedAbajoDerecha, LOW);
}
