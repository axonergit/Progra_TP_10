#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


#include "led.h"
#include "registers.h"
 
#define FPS			60.0
#define SCREEN_W		640
#define SCREEN_H		480
#define CUADRADITO_SIZE	32
#define MOVE_RATE		4.0

enum MYKEYS {
	KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7,KEY_8, KEY_ESCAPE, KEY_S, KEY_C, KEY_B //arrow keys
};
 
int main(void)
{
        int error = 0;
        int flagBlink = 0;
        puerto_8_t puertoA;
    
        puertoA.port = 0;
        
        int portSize = TAMANOPUERTO_8_T;
        
        char array [TAMANOPUERTO_16_T];
    
	ALLEGRO_DISPLAY *display = NULL;
        ALLEGRO_BITMAP  *image_on   = NULL;
        ALLEGRO_BITMAP  *image_off   = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *cuadradito = NULL;
	
	bool key_pressed[12] = { false, false, false, false, false, false, false, false, false, false, false, false}; //Estado de teclas, true cuando esta apretada
	bool redraw = false;
	bool do_exit = false; 
 
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
 
        if(!al_init_image_addon()) { // ADDON necesario para manejo(no olvidar el freno de mano) de imagenes 
		fprintf(stderr, "failed to initialize image addon !\n");
		return -1;
	}
        
        image_on = al_load_bitmap("red-led-on-md.png");
	if(!image_on) {
		fprintf(stderr, "failed to load image !\n");
		return 0;
	}
        
        image_off = al_load_bitmap("red-led-off-small-md.png");
	if(!image_off) {
		fprintf(stderr, "failed to load image !\n");
		return 0;
	}
        
	if(!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}
 
	timer = al_create_timer(1.0 / FPS);
	if(!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	event_queue = al_create_event_queue();
	if(!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_timer(timer);
                al_destroy_bitmap(image_on);
                al_destroy_bitmap(image_off);
		return -1;
	}
 
	display = al_create_display(SCREEN_W, SCREEN_H);
	if(!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		al_destroy_event_queue(event_queue);
                al_destroy_bitmap(image_on);
                al_destroy_bitmap(image_off);
		return -1;
	}
	
	al_clear_to_color(al_map_rgb(255, 0, 255));
	al_set_target_bitmap(al_get_backbuffer(display));
  
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source()); //REGISTRAMOS EL TECLADO
 
	al_clear_to_color(al_map_rgb(0,0,0));
	al_flip_display();
	al_start_timer(timer);
 
	while(!do_exit)
	{
		ALLEGRO_EVENT ev;
                
		if( al_get_next_event(event_queue, &ev) ) //Toma un evento de la cola, VER RETURN EN DOCUMENT.
		{ 
			if(ev.type == ALLEGRO_EVENT_TIMER) 
			{
				     
                                if(key_pressed[KEY_B]){
                                    error = blinkAll_On_Leds(&puertoA.port, portSize, array, flagBlink);
                                }
                                if(key_pressed[KEY_1]) 
                                    error = prenderLed(&puertoA.port, portSize, 0);

				if(key_pressed[KEY_2]) 
                                    error = prenderLed(&puertoA.port, portSize, 1);

				if(key_pressed[KEY_3]) 
                                    error = prenderLed(&puertoA.port, portSize, 2);

				if(key_pressed[KEY_4]) 
                                    error = prenderLed(&puertoA.port, portSize, 3);
                                
                                if(key_pressed[KEY_5])
                                    error = prenderLed(&puertoA.port, portSize, 4);
                                    
                                if(key_pressed[KEY_6])
                                    error = prenderLed(&puertoA.port, portSize, 5);
                                    
                                if(key_pressed[KEY_7])
                                    error = prenderLed(&puertoA.port, portSize, 6);
                                
                                if(key_pressed[KEY_8])
                                    error = prenderLed(&puertoA.port, portSize, 7);
                                    
                                if(key_pressed[KEY_ESCAPE])
                                    do_exit = true;
                                    
                                if(key_pressed[KEY_S])
                                    error = PrenderLeds(&puertoA.port, portSize);
                                    
                                if(key_pressed[KEY_C])
                                    error = apagarLeds(&puertoA.port, portSize);
                               
                                    
				redraw = true;
			}

			else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
				do_exit = true;

			else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) 
			{
				switch(ev.keyboard.keycode){
					case ALLEGRO_KEY_1:
						key_pressed[KEY_1] = true;
						break;

					case ALLEGRO_KEY_2:
						key_pressed[KEY_2] = true;
						break;

					case ALLEGRO_KEY_3: 
						key_pressed[KEY_3] = true;
						break;

					case ALLEGRO_KEY_4:
						key_pressed[KEY_4] = true;
						break;
                                             
                                        case ALLEGRO_KEY_5:
						key_pressed[KEY_5] = true;
						break;
                                                
                                        case ALLEGRO_KEY_6:
						key_pressed[KEY_6] = true;
						break;
                                                
                                        case ALLEGRO_KEY_7:
						key_pressed[KEY_7] = true;
						break;
                                                
                                        case ALLEGRO_KEY_8:
						key_pressed[KEY_8] = true;
                                                break;
                                                
                                        case ALLEGRO_KEY_ESCAPE:
						do_exit = true;
						break;
                                                
                                        case ALLEGRO_KEY_S:
						key_pressed[KEY_S] = true;
						break;
                                                
                                        case ALLEGRO_KEY_C:
						key_pressed[KEY_C] = true;
						break;
                                                
                                        case ALLEGRO_KEY_B:
						key_pressed[KEY_B] = true;
						break;        
				}
			}

			else if(ev.type == ALLEGRO_EVENT_KEY_UP) 
			{
				switch(ev.keyboard.keycode) {
					case ALLEGRO_KEY_1:
						key_pressed[KEY_1] = false;
						break;

					case ALLEGRO_KEY_2:
						key_pressed[KEY_2] = false;
						break;

					case ALLEGRO_KEY_3: 
						key_pressed[KEY_3] = false;
						break;

					case ALLEGRO_KEY_4:
						key_pressed[KEY_4] = false;
						break;
                                             
                                        case ALLEGRO_KEY_5:
						key_pressed[KEY_5] = false;
						break;
                                                
                                        case ALLEGRO_KEY_6:
						key_pressed[KEY_6] = false;
						break;
                                                
                                        case ALLEGRO_KEY_7:
						key_pressed[KEY_7] = false;
						break;
                                                
                                        case ALLEGRO_KEY_8:
						key_pressed[KEY_8] = false;
						break;
                                                
                                        case ALLEGRO_KEY_ESCAPE:
						do_exit = true;
						break;
                                                
                                        case ALLEGRO_KEY_S:
						key_pressed[KEY_S] = false;
						break;
                                                
                                        case ALLEGRO_KEY_C:
						key_pressed[KEY_C] = false;
						break;
                                                
                                        case ALLEGRO_KEY_B:
						key_pressed[KEY_B] = false;
						break;   
				}
			}
		}
 
		if(redraw && al_is_event_queue_empty(event_queue)) 
		{  
			redraw = false;
			al_clear_to_color(al_map_rgb(0,0,0));
                        
                        if(puertoA.port & 0x80)
                            al_draw_bitmap(image_on, 10, 120, 0);
                        else
                            al_draw_bitmap(image_off, 10, 120, 0);
                                    
                        if(puertoA.port & 0x40)
                            al_draw_bitmap(image_on, 90, 120, 0);
                        else
                            al_draw_bitmap(image_off, 90, 120, 0);
                                    
                        if(puertoA.port & 0x20)
                            al_draw_bitmap(image_on, 170, 120, 0);
                        else
                            al_draw_bitmap(image_off, 170, 120, 0);
                                    
                        if(puertoA.port & 0x10)
                            al_draw_bitmap(image_on, 250, 120, 0);
                        else
                            al_draw_bitmap(image_off, 250, 120, 0);
                        
                        if(puertoA.port & 0x08)
                            al_draw_bitmap(image_on, 330, 120, 0);
                        else
                            al_draw_bitmap(image_off, 330, 120, 0);
                        
                        if(puertoA.port & 0x04)
                            al_draw_bitmap(image_on, 410, 120, 0);
                        else
                            al_draw_bitmap(image_off, 410, 120, 0);
                        
                        if(puertoA.port & 0x02)
                            al_draw_bitmap(image_on, 490, 120, 0);
                        else
                            al_draw_bitmap(image_off, 490, 120, 0);
                        
                        if(puertoA.port & 0x01)
                            al_draw_bitmap(image_on, 570, 120, 0);
                        else
                            al_draw_bitmap(image_off, 570, 120, 0);
                            

			al_flip_display();
		}
	}
 
	al_destroy_bitmap(image_off);
        al_destroy_bitmap(image_on);
	al_destroy_timer(timer);
	al_destroy_display(display);
	return 0;
}