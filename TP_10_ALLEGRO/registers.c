#include <stdio.h>
#include "registers.h"

int bitSet(void * posPuerto, unsigned int tamanoPuerto , unsigned int numBit){

    int error =0;
    int numByte;
    char byte ,* p;

    if((tamanoPuerto * 8) < numBit ){
        error = 1;          //Chequeo si tengo un numero valido de bits en el puerto
    }
    else{
        p = (char *) posPuerto;       //Posiciono mi puntero en el primer bit del puerto
        numByte = numBit/8;           //Chequeo el numero de bytes segun los bits
        p = p + numByte;            //Me paro en el bit a modificar

        byte = (*p);                //Me fijo en que byte estoy
        numBit = numBit % 8;          //Me fijo en que bit estoy dentro de mi byte
        byte = ( byte | (1 << numBit) );      //or logico con el n-esimo bit, siendo el n-esimo bit el (numBit+1)-esimo bit.
        *p = byte;            //Le asigno al puntero el numero de byte
    }
    return error;
}
int bitClr(void * posPuerto, unsigned int tamanoPuerto , unsigned int numBit){

    int error =0;
    int numByte;
    char byte ,* p;

    if((tamanoPuerto * 8) < numBit ){
        error = 1;             //Chequeo si tengo un numero valido de bits en el puerto
    }
    else{
        p = (char *) posPuerto;      //Posiciono mi puntero en el primer bit del puerto
        numByte = numBit/8;         //Chequeo el numero de bytes segun los bits
        p = p + numByte;              //Me paro en el bit a modificar

        byte = (*p);                  //Me fijo en que byte estoy
        numBit = numBit % 8;            //Me fijo en que bit estoy dentro de mi byte
        byte = ( byte & (~(1 << numBit)) );     //complemento a 1 del n-esimo bit, siendo el n-esimo bit el (numBit+1)-esimo bit
        *p = byte;                //luego le hace un and logico y le asigna el byte al puntero
    }
    return error;
}

int bitGet(void * posPuerto, unsigned int tamanoPuerto , unsigned int numBit){

    int error =0;
    int numByte;
    char byte ,* p;

    if((tamanoPuerto * 8) < numBit ){
        printf("error.");
        error = 2;
    }
    else{
        p = (char *) posPuerto;             //Posiciono mi puntero en el primer bit del puerto
        numByte = numBit/8;                 //Chequeo el numero de bytes segun los bits
        p = p + numByte;              //Me paro en el bit a modificar

        byte = (*p);                //Me fijo en que byte estoy
        numBit = numBit % 8;            //Me fijo en que bit estoy dentro de mi byte
        byte = ( byte & (1 << numBit) );        //and logico con el n-esimo bit, siendo el n-esimo bit el (numBit+1)-esimo bit

        error = (byte == 0) ? 0 : 1;        //Chequeo si el bit esta en 1 o 0

    }
    return error;

}
int maskOn(void * posPuerto, unsigned int tamanoPuerto, char * mascara){
    int error =0;
    char * p;
    p = (char *) posPuerto;         //Posiciono mi puntero en el primer bit del puerto
    int i;
    for(i = 0; i <tamanoPuerto ;i++){     //Aplico una mascara al puerto asignando un 1 a cada bit del
        *(p+i) = (*(p+i)) | (*(mascara+i));     //puerto en el cual la mascara pasada como parametro tiene un uno, or logico
    }
    return error;
}

int maskOff(void * posPuerto, unsigned int tamanoPuerto, char * mascara){
    int error =0;
    char * p;
    p = (char *) posPuerto;
    int i;
    for(i = 0; i <tamanoPuerto ;i++){         //Aplico una mascara al puerto y niego todos aquellos bits que estén prendidos en la
        *(p+i) = (*(p+i)) & (~(*(mascara+i)));          //mascara, and logico
    }
    return error;
}
