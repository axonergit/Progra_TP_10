#include "display.h"

void bienvenida(void)
{
    imprimirString("Bienvenido a mi humilde carpa");
    imprimirString("os invito a jugar un juego...\n");
    imprimirString("Teneis que adivinar un numero del 0 al %d", MAX_ADIV);
    imprimirString("pero no va a ser una tarea sencilla");
    imprimirString("ya que solamente teneis %d segundos", MAX_SEG);
    imprimirString("y %d intentos\n", MAX_TRY);
    imprimirString("Presione enter para comenzar y escape para salir\n");
}


void imprimirString(char * string)
{
    printf("%s\n", string);
}

void imprimirVar(int var)
{
    printf("%d\n", var);
}