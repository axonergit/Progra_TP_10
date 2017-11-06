#include <stdio.h>

#include "Display.h"

void bienvenida(void)                               // mensaje de bienvenida
{
    printf("Bienvenido a mi humilde programa.\n");
    printf("Os invito a jugar un juego...\n");
    printf("Teneis que adivinar un numero del 0 al %d.\n", MAX_NUMBER);
    printf("Pero no va a ser una tarea sencilla,\n");
    printf("ya que solamente teneis %d segundos ", (int)MAX_SEC);
    printf("y %d intentos.\n\n", MAX_TRY);
    printf("Presione enter para comenzar y escape para salir\n\n");
}


void imprimirString(char * string)                  // funcion que imprime en pantalla un string
{
    printf("%s\n", string);
}

void imprimirVar(int var)                           // funcion que imprime una variable
{
    printf("%d\n", var);
}
