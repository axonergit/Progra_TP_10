#ifndef LED_H
#define LED_H

/*
---------------prenderLed-------------
  Prende un led especificado.

  INPUT:
    1) PosPuerto: puntero a la posición a la primera posición de memoria del puerto.
    2) tamanoPuerto: Cantidad de bytes que ocupa en memoria el puerto.
    3) numLed: numero de led a prender (empezando desde el led 0).

  OUTPUT:
    devuelve un 0 en caso de NO haber error.
    devuelve un valor distitno de cero en caso de haber error.
*/
int prenderLed(void * posPuerto, unsigned int tamanoPuerto, unsigned int numLed);

/*
---------------blinkAll_On_Leds-------------
  Hace blinkear los leds prendidos UNA SOLA VEZ, es decir:
  Apaga todos los leds y vuelve a prender los que estaban prendidos originalmente.

  INPUT:
    1) PosPuerto: puntero a la posición a la primera posición de memoria del puerto.
    2) tamanoPuerto: Cantidad de bytes qeu ocupa en memoria el puerto,

  OUTPUT:
    devuelve un 0 en caso de NO haber error.
    devuelve un valor distitno de cero en caso de haber error,
*/
int blinkAll_On_Leds(void * posPuerto, unsigned int tamanoPuerto ,char array[], int flagBlink);

/*
---------------prenderLeds-------------
  Prende todos los leds del puerto.

  INPUT:
    1) PosPuerto: puntero a la posicion a la primera posición de nenoria del puerto.
    2) tamanoPuerto: Cantidad de bytes qeu ocupa en memoria el puerto,

  OUTPUT:
    devuelve un 0 en caso de NO haber error.
    devuelve un valor distinto de cero en caso de haber error,
*/
int PrenderLeds(void * posPuerto, unsigned int tamanoPuerto);

/*
---------------ApagarLeds-------------
  Apaga todos los leds del puerto.

  INPUT:
    1) PosPuerto: puntero a la posición a la primera posición de memoria del puerto.
    2) tamanoPuerto: Cantidad de bytes que ocupa en memoria el puerto,

  OUTPUT:
    devuelve un 0 en caso de NO haber error.
    devuelve un valor distitno de cero en caso de haber error,
*/
int apagarLeds(void * posPuerto, unsigned int tamanoPuerto);

#endif /* LED_H */
