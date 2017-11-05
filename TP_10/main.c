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

#include "Deff.h"       // Incluye definiciones y prototipos de funciones
#include "termlib.h"    /* getch, getche, kbhit */ 
#include "Display.h"    /* imprimirString, imprimirVar, bienvenida */


int main(void)
{
    changemode(BUFFERED_OFF); // Turns terminal line buffering off
    clrscr();                  //Limpia la pantalla del terminal (Linux)
    
    srand (time(NULL));         //inicializo mi semilla
    
    int number = (rand()%MAX_NUMBER)+1;     //creo numero random gracias a la semilla
    
    unsigned char num = '0';                // creacion de variables y flags
    unsigned int numero = 0;
    
    int intentos = (int)MAX_TRY;
    int flagExit = 0;
    int flagWin = 0;
    
    clock_t time = 0.0;                 // inicializo y seteo timer del programa
    clock_t time_prec = -1.0;
    clock_t init = clock();
    
    bienvenida();                   //saludo de bienvenida
    
    /*   Prueba de programa.
     *
     *   printf("Clocks per second: %ld\n",CLOCKS_PER_SEC);
     *   printf("The random number is: %d \n",number);
     *   printf("LET'S GOOOOOOOOOOOO! \n\n");
     */
     
    while(flagExit == 0)        //primera entrada antes de comenzar el juego
    {                           //simula el clasico start de todo juego
        while(kbhit())
            num = getch();
        
        if(num == '\n')
            flagExit = 2;
        else if(num == EXIT)
            flagExit = 1;
        
    }
    
    while((num != EXIT) || (((clock()-init))<MAX_SEC*CLOCKS_PER_SEC))            //salgo del juego cuando el usuario lo indique
    {
        if(flagExit == 1)                                                        //exit de inicio
            break;
        
        time=(clock()-init)/CLOCKS_PER_SEC;     /* second since the begining of the game*/
        
        if(intentos <= 0)
            break;
        
        if(time!=time_prec) /* One second has passed*/
        {
            printf("Number of seconds left : %ld\n",((int)MAX_SEC-time));
            time_prec = time;
        }
        else if(kbhit()) /*user typing*/
        {
            num=getch(); /*character chosen*/
            
            if(is_number(num)) /*the character is a digit*/
                numero = numero*10+(num-'0');
            else if(num == KEY) /* The character is the one meaning the end of the number chosen*/
            {
                if((--intentos) >= 0)
                    printf("                                            Intentos restantes: %d\n", intentos);
                else
                    break;
                
                printf("                                            Numero : %u \n",numero);
                
                if(numero==number)
                {
                     printf("                                            TRUE! The number was %d \n",number);
                     flagWin = 1;
                     break;
                }
                else
                    printf("                                            FALSE! \n");
                
                numero = 0;
            }
            
            else if(num == EXIT)
                break;
            else /* The character is an error*/
            {
                printf("                                            Error, input invalido.\n");
                numero = 0;
            }
        }
    }
    
    
    if((num != EXIT) && (((clock()-init))>MAX_SEC*CLOCKS_PER_SEC)) /*Number not found at the end of the given time*/
        printf("                                            TIMEOUT! \n ");
    else if (num == EXIT || flagExit == 1)
        imprimirString("\n\nHa decidido retirarse, Vuelva pronto!\nGracias por jugar.");
    else if (flagWin == 1)
        imprimirString("\nFelicitaciones, usted ha adivinado.\nGracias por jugar,\nvuelva pronto!");
    else
        imprimirString("\nSe han acabado los intentos, vuelva pronto!\nGracias por jugar.");
    
    
    changemode(BUFFERED_ON); // Turns terminal line buffering off
    
    return 0;
}



/*
    Recibe un int correspondante a una valor en char.
    Si el valor del int corresponde a un numero (0 a 9), return TRUE
    Si no, return FALSE
*/
int is_number(int c)
{
    switch(c)
    {
        case '0': return TRUE; break;
        case '1': return TRUE; break;
        case '2': return TRUE; break;
        case '3': return TRUE; break;
        case '4': return TRUE; break;
        case '5': return TRUE; break;
        case '6': return TRUE; break;
        case '7': return TRUE; break;
        case '8': return TRUE; break;
        case '9': return TRUE; break;
        default : return FALSE; break;
    }
}

