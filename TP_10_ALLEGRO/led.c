#include "led.h"
#include "registers.h"
#include <unistd.h>
#include <time.h>
int prenderLed(void * posPuerto, unsigned int tamanoPuerto, unsigned int numLed){
    return bitSet(posPuerto, tamanoPuerto , numLed);    //Pongo un bit prendido en el puerto en donde corresponde
}
int blinkAll_On_Leds(void * posPuerto, unsigned int tamanoPuerto ,char array[],int flagBlink, char * pposMascara){

     
     int error;
    
     if(flagBlink){
        sleep(1);
        error = maskOn(posPuerto, tamanoPuerto, pposMascara);    //Vuelvo a prenderlos con lo mismo que tenian antes
        flagBlink = 0;
        
    }
     else{
     (*pposMascara) = (*((char *)posPuerto));
     array[0] = (*((char *)posPuerto));
     error = apagarLeds(posPuerto, tamanoPuerto);        //Apago todos los leds
    
    flagBlink = 1;                                      
     }
    
    return flagBlink;
}

int apagarLeds(void * posPuerto, unsigned int tamanoPuerto){
    int led,error;

    for(led=0 ;led < (tamanoPuerto*8); led++){            //Recorro cada uno de los leds y los voy apagando
        error = bitClr(posPuerto, tamanoPuerto , led);
        if(error)
            break;
    }
    return error;

}

int PrenderLeds(void * posPuerto, unsigned int tamanoPuerto){
    int led,error;

    for(led=0 ;led < (tamanoPuerto*8); led++){            //Recorro cada uno de los leds y los voy prendiendo
        error = bitSet(posPuerto, tamanoPuerto , led);
        if(error)
            break;
    }
    return error;

}
