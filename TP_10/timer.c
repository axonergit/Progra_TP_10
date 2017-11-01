#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "termlib.h"


#define MAX_SEC 30.0
#define MAX_NUMBER 100

#define KEY 'T'

#define TRUE 1
#define FALSE 0

void timer(const double time_max);
int is_number(int c); /* Chequeo si el valor entrada es un numero */

int main(void)
{
    printf("%d\n",CLOCKS_PER_SEC);
    srand(time(NULL));

    int number = (rand()%100)+1;

    printf("the random number is %d \n",number);
    printf("GOOO \n");

    clock_t time = 0.0;
    clock_t time_prec = -1.0;
    clock_t init=clock();

    unsigned char num = '0';
    unsigned int numero=0;

    while(((clock()-init))<MAX_SEC*CLOCKS_PER_SEC)
    {
        time=(clock()-init)/CLOCKS_PER_SEC;     /* second since the begining of the game*/
        if(time!=time_prec) /* One second has passed*/
        {
            printf("Number of seconds left : %d\n",((int)MAX_SEC-time));
            time_prec = time;
        }
        else if(kbhit()) /*user typing*/
        {
            num=getch(); /*character chosen*/
            if(is_number(num)) /*the character is a digit*/
            {
                numero = numero*10+(num-'0');
            }

            else if(num == KEY) /* The character is the one meaning the end of the number chosen*/
            {
                printf("                                            numero : %d \n",numero);
                if(numero==number)
                {
                     printf("                                            TRUE! The number was %d \n",number);
                     break;
                }
                else
                    printf("                                            FALSE! \n");
                numero = 0;
            }
            else /* The character is an error*/
            {
                printf("                                            Error %c is neither a digit, neither the key\n",num);
                numero = 0;
            }
        }
    }

    if(((clock()-init))>MAX_SEC*CLOCKS_PER_SEC) /*Number not found at the end of the given time*/
        printf("                                            TIMEOUT! \n ");

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
