/*
	Configuraciones y librerias para programda de dado
*/

// Constantes para asignar puertos digitales a los LED y al botón
const int BotonPin = 2;
const int LedArribaIzquierda = 13;
const int LedArribaCentro = 12;
const int LedArribaDerecha = 11;
const int LedCentro = 10;
const int LedAbajoIzquiera = 9;
const int LedAbajoCentro = 8;
const int LedAbajoDerecha = 7;

void one()
{
  digitalWrite(LedCentro, HIGH);
}

void two()
{
  digitalWrite(LedArribaIzquierda, HIGH);
  digitalWrite(LedAbajoDerecha, HIGH);
}

void three()
{
  digitalWrite(LedArribaIzquierda, HIGH);
  digitalWrite(LedCentro, HIGH);
  digitalWrite(LedAbajoDerecha, HIGH);
}

void four()
{
  digitalWrite(LedArribaIzquierda, HIGH);
  digitalWrite(LedArribaDerecha, HIGH);
  digitalWrite(LedAbajoIzquiera, HIGH);
  digitalWrite(LedAbajoDerecha, HIGH);
}

void five()
{
  digitalWrite(LedArribaIzquierda, HIGH);
  digitalWrite(LedArribaDerecha, HIGH);
  digitalWrite(LedCentro, HIGH);
  digitalWrite(LedAbajoIzquiera, HIGH);
  digitalWrite(LedAbajoDerecha, HIGH);
}

void six()
{
  digitalWrite(LedArribaIzquierda, HIGH);
  digitalWrite(LedArribaCentro, HIGH);
  digitalWrite(LedArribaDerecha, HIGH);
  digitalWrite(LedAbajoIzquiera, HIGH);
  digitalWrite(LedAbajoCentro, HIGH);
  digitalWrite(LedAbajoDerecha, HIGH);
}

void seven()
{
  digitalWrite(LedArribaIzquierda, HIGH);
  digitalWrite(LedArribaCentro, HIGH);
  digitalWrite(LedArribaDerecha, HIGH);
  digitalWrite(LedCentro, HIGH);
  digitalWrite(LedAbajoIzquiera, HIGH);
  digitalWrite(LedAbajoCentro, HIGH);
  digitalWrite(LedAbajoDerecha, HIGH);
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
