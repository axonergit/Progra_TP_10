/*
 * TP_10
 */

/* 
 * File:   main.c
 * Author: Matias Gonzalez, Alexa Maingard, Tomas Gonzalez y Martin Bellefroid
 */


#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Deff.h"


int main(void)
{
    srand (time(NULL));         //inicializo mi semilla
    
    changemode(BUFFERED_OFF); // Turns terminal line buffering off
    clrscr();
    
    bienvenida();
    
    while(input != EXIT || /* poner timer*/)            //salgo del while cuando el usuario lo indique y asi termina el programa
    {
        
    }
    
    
    // ACA VA EL CODIGO ELEFANTE!!!
    
    return 0;
}

