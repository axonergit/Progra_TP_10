#ifndef REGISTERS_H
#define REGISTERS_H


#define TAMANOPUERTO_8_T 1
#define TAMANOPUERTO_16_T 2

/*
---------------bitSet------------
  Prende (le asigna el valor de 1 a) un bit del puerto.

  INPUT:
    1) PosPuerto: puntero a la posicion a la primera posición de nenoria del puerto.
    2) tamanoPuerto: Cantidad de bytes qeu ocupa en memoria el puerto,
    3) numBit: numero de bit a prender (empezando desde el bit 0)

  OUTPUT:
    devuelve un 0 en caso de NO haber error.
    devuelve un valor distitno de cero en caso de haber error,
*/
int bitSet(void * posPuerto, unsigned int tamanoPuerto , unsigned int numBit);

/*
---------------bitClr------------
  Apaga (le asigna el valor de 0 a) un bit del puerto.

  INPUT:
    1) PosPuerto: puntero a la posicion a la primera posición de nenoria del puerto.
    2) tamanoPuerto: Cantidad de bytes qeu ocupa en memoria el puerto,
    3) numBit: numero de bit a prender (empezando desde el bit 0)

  OUTPUT:
    devuelve un 0 en caso de NO haber error.
    devuelve un valor distitno de cero en caso de haber error,
*/
int bitClr(void * posPuerto, unsigned int tamanoPuerto , unsigned int numBit);

/*
---------------bitGet------------
  Devuelve el valor del bit. Indica si hay error.

  INPUT:
    1) PosPuerto: puntero a la posicion a la primera posición de nenoria del puerto.
    2) tamanoPuerto: Cantidad de bytes qeu ocupa en memoria el puerto,
    3) numBit: numero de bit a prender (empezando desde el bit 0)

  OUTPUT:
    1) Un 0 o un 1 dependiendo del valor del bit indicado.
    2) Un 2 eb caso de eror.
*/
int bitGet(void * posPuerto, unsigned int tamanoPuerto , unsigned int numBit);

/*
---------------maskOn------------
  Asigna un valor de 1 a cada bit del puerto en el cual la mascara pasada como parametro tiene un uno.

  INPUT:
    1) PosPuerto: puntero a la posicion a la primera posición de nenoria del puerto.
    2) tamanoPuerto: Cantidad de bytes que ocupa en memoria el puerto, Misma cabtidad de bytes que la mascara.
    3) mascara: puntero a char de la nascara utilizada. La mascara tiene que ocupar la misma cantidad de bytes que puerto en memoria.

  OUTPUT:
    1) Un 0 en caso de que no haya error,
    2) Un 1 en caso de error,
*/
int maskOn(void * posPuerto, unsigned int tamanoPuerto, char * mascara);

/*
---------------maskOff------------
  Dado un puerto y una máscara, apaga todos aquellos bits que estén prendidos en la
  máscara, sin cambiar el estado de los restantes. Por ejemplo, dado el puerto A, que originalmente
  se encuentra en el estado 0x0A, al aplicarle la máscara 0x02, el resultado será 0x08.

  INPUT:
    1) PosPuerto: puntero a la posicion a la primera posición de nenoria del puerto.
    2) tamanoPuerto: Cantidad de bytes que ocupa en memoria el puerto, Misma cabtidad de bytes que la mascara.
    3) mascara: puntero a char de la nascara utilizada. La mascara tiene que ocupar la misma cantidad de bytes que puerto en memoria.

  OUTPUT:
    1) Un 0 en caso de que no haya error,
    2) Un 1 en caso de error,
*/
int maskOff(void * posPuerto, unsigned int tamanoPuerto, char * mascara);

typedef struct{
    unsigned char b0 :1;
    unsigned char b1 :1;
    unsigned char b2 :1;
    unsigned char b3 :1;
    unsigned char b4 :1;
    unsigned char b5 :1;
    unsigned char b6 :1;
    unsigned char b7 :1;
}bitfield_8_t;

typedef struct{
    unsigned char b0 :1;
    unsigned char b1 :1;
    unsigned char b2 :1;
    unsigned char b3 :1;
    unsigned char b4 :1;
    unsigned char b5 :1;
    unsigned char b6 :1;
    unsigned char b7 :1;
    unsigned char b8 :1;
    unsigned char b9 :1;
    unsigned char b10 :1;
    unsigned char b11 :1;
    unsigned char b12 :1;
    unsigned char b13 :1;
    unsigned char b14 :1;
    unsigned char b15 :1;
}bitfield_16_t;

typedef union{

    bitfield_8_t bitPort;
    unsigned char port;

}puerto_8_t;

typedef struct{

    puerto_8_t puertoB;
    puerto_8_t puertoA;

}puerto_16_Dividido_t;

typedef union{

    bitfield_16_t bitPort;
    unsigned short int port;
    puerto_16_Dividido_t puertos;

}puerto_16_t;



#endif /* REGISTERS_H */
