# ARDUINO: INTRODUCCIÓN
# Práctica con LEDs, pulsador y altavoz

Este es un proyecto de un dado simple basado en LEDs, un interruptor de botón, un buzzer y una placa de desarrollo de microcontrolador [Arduino Uno](https://store.arduino.cc/arduino-uno-rev3). Se ha construirlo en una placa de pruebas con los componentes del [Arduino Starter Kit](https://store.arduino.cc/genuino-starter-kit) previa simulación en TINKERCAD.

## Planteamiento
El programa generar un número aleatorio entre 1 y 7 cada vez que se pulse un pulsador y encenderá los diodos LED correspondientes al número aleatorio generado como si se tratara de un dado. Además emite una serie de pitidos correspondiente al número generado.

Los patrones de iluminación de los LEDs para representar los número son:

<img src="./LEDs_caras_dado.jpg" align="center" />

Los LEDs correspondientes al número estarán encendidos durante un segundo tras la secuencia de pitidos. Pasado este tiempo se deben apagar los diodos LED automáticamente y quedarse a la espera de que se vuelva a pulsar el pulsador.

## La solución
### Hardware
Utilizando el entorno de Circuits de TinKerCad se interconectan todos los componentes sobre la placa de desarrollo. El microcontrolador alimenta los LED a través de resistencias limitadoras de corriente de 10K ohmios desde el comun negativo de la placa. Por otra parte el ánodo de los LEDs se conectan conseutivamente a los pines digitales desde el 13 al 7

Por otra parte el interruptor de botón está conectado al pin 2 digital, que está configurado para usar una resistencia pull-up de 220 ohmnios.

El buzzer (altavoz digital) está directamente conectado al pin 4 digital.
<img src="./practica_dado_arduino_uno.png" width=600 align="center" />

### Software
El programa espera hasta que se presione el botón. En el primer instante del botón pulsado, el programa se genera un número semi-aleatorio. Y este número es el argumento de una función que se encarga de llamar a las rutinas que encienden los LEDs correspondientes al número generado. En cascada se llama también a otra función que emite los pitidos correspondientes al número.

Se divide el código en dos bloques:
* Programa principal con la definición de variables, inicialización y bucle principal.
```c++
#include "dadolib.h";

// variables 
int ButtonState = 0;     // variable para el estado de pulsación del botón

void setup() {
  Serial.begin(115200);
  // initializa los pines digitales de
  // LEDs:
  pinMode(LedArribaIzquierda, OUTPUT);
  pinMode(LedArribaCentro, OUTPUT);
  pinMode(LedArribaDerecha, OUTPUT);
  pinMode(LedCentro, OUTPUT);
  pinMode(LedAbajoIzquiera, OUTPUT);
  pinMode(LedAbajoCentro, OUTPUT);
  pinMode(LedAbajoDerecha, OUTPUT);
  // Botón:
  pinMode(BotonPin, INPUT);
  // Buzzer
  pinMode(buzzer, OUTPUT); //
  
  // Inicializa la secuencia semi-aleatoria en la posición de la lectura basadan en la entrada analógica.
  // Esto evita que la secuencia de numeros aleatoríos obtenidos con ramdon, empiece siempre igual.
  randomSeed(analogRead(0));
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
    }
}

void loop() {
  // Lee el estado del botón
  ButtonState = digitalRead(BotonPin);

  // Si se pulsa el botón (ButtonState=HIGH):
  if (ButtonState == HIGH) {
    ShowNumber(random(1,7));  // Obtenemos un número aleatorio de 1 a 7 y lo enviamos a la rutina que muestra y pita el número
    delay(1000);              // Se espera 1 segundo (1000 ms)
    TurnOffAll();             // Se apagan todos los LEDs
  }
}
```

* Configuración. Constantes y rutinas para mostrar números y emitir los pitidos.
```c++
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

```
### Resultado

[![Video del montaje real](https://raw.githubusercontent.com/McOrts/practica_dado_arduino_uno/main/practica_dado_arduino_uno_real.jpg)](https://youtu.be/Z49DEIchQN4)

## ¿Qué hemos aprendido?

## Generación de números casi aleatorios.
randomSeed() inicializa el generador de números pseudo aleatorios, haciendo que se inicie en un punto arbitrario en su secuencia aleatoria. Esta secuencia, aunque muy larga, y al azar, es siempre la misma.
Si es importante que la secuencia de valores generados por randomSeed() difiera, en sucesivas ejecuciones de un programa. Por lo que se usa una entrada bastante aletoria leida con analogRead() que tiene que se de un pin desconectado.

## Generación de sonidos a partir de una señal digital
Técnicamente tanto buzzers como altavoces son transductores electroacústicos, es decir, dispositivos que convierten señales eléctricas en sonido. La diferencia entre ambos es el fenómeno en el que basan su funcionamiento.

Los buzzer son transductores piezoeléctricos. Los materiales piezoeléctricos tiene la propiedad especial de variar su volumen al ser atravesados por corrientes eléctricas.

<img src="./>arduino-buzzer-funcionamiento.png" align="center" />

Un buzzer aprovecha este fenómeno para hacer vibrar una membrana al atravesar el material piezoeléctrico con una señal eléctrica.

<img src="./>arduino-buzzer-funcionamiento2.png" align="center" />

Los buzzer son dispositivos pequeños y compactos, con alta durabilidad, y bajo consumo eléctrico. Por contra, la calidad de sonido es reducida.

Para su uso con una placa como esta. Utilizaremos una de las salidas digitales. Esto significa que el sonido sólo lo vamos a poder modificar en su frecuencia pero no en su amplitud ya que el voltaje de salida no es modificable. Pero el tono si será modificable en función de onda cuadrada que generemos en La salida. La frecuencia de cambio de la señal de 0 a 1 que programemos identificará este tono y su duración.

<img src="./>how-it-works-piezo-buzzer-music.gif" align="center" />
