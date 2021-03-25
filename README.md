# Práctica con LEDs, pulsador y altavoz
A partir de diodos LED, un pulsador y una plataforma Arduino Uno debemos desarrollar un programa que haga lo siguiente:
Generar un número aleatorio entre 1 y 6 (buscar información sobre la función random( ) de Arduino) cada vez que se pulse un pulsador.
Configurar un sistema de diodos LED con la siguiente estructura:

		LED1			LED2			LED3


					LED4


		LED5			LED6			LED7

Programar la placa Arduino Uno para que se enciendan los diodos LED correspondientes al número aleatorio generado como si se tratara de un dado. Así, si el número aleatorio fuera el 3, los diodos LED encendidos serían:


		LED1			LED2			LED3


					LED4


		LED5			LED6			LED7

El tiempo que deben estar encendidos será un segundo (busca información sobre la función delay ( ) de Arduino). Pasado este tiempo se deben apagar los diodos LED automáticamente y quedarse a la espera de que se vuelva a pulsar el pulsador.
