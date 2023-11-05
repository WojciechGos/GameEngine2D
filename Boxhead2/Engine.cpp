#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

#include "Engine.h"
#include "Control.h"
#include "Interface.h"
#include <iostream>

#define screenWidth 1800
#define screenHeight 900

int SCREEN_POSITION_X = 30;
int SCREEN_POSITION_Y = 30;



bool handle_events(ALLEGRO_EVENT event);

void init() {
	// initiation 
	ALLEGRO_DISPLAY* display = NULL;
	al_init();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();



	/*
		SETTING WINDOWS PARAMETERS
	*/
	display = al_create_display(screenWidth, screenHeight);
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	al_set_window_position(display, SCREEN_POSITION_X, SCREEN_POSITION_Y);
	al_set_window_title(display, "Boxhead2");

	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

	if (!event_queue) {
		std::cerr << "Błąd inicjalizacji okna." << std::endl;
		return;
	}
		


	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());


	/*
		 MAIN LOOP
	*/

    al_clear_to_color(al_map_rgb(0, 0, 0));

    //mapa
    al_draw_filled_rectangle(0, 0, 1800, 900, al_map_rgb(217, 186, 140));

    int liczba_prostokatow = 8;
    int x = 0;
    int prostokat_szerokosc = 100;
    int prostokat_wysokosc = 50;

    for (int i = 0; i < liczba_prostokatow; i++) {
        al_draw_filled_rectangle(x, 0, x + prostokat_szerokosc, prostokat_wysokosc, al_map_rgb(128, 128, 128));
        al_draw_line(x + prostokat_szerokosc, 0, x + prostokat_szerokosc, prostokat_wysokosc, al_map_rgb(0, 0, 0), 2);

        x += prostokat_szerokosc;
    }

    int y = 1800;


    for (int i = 0; i < liczba_prostokatow; i++) {
        al_draw_filled_rectangle(y - prostokat_szerokosc, 0, y, prostokat_wysokosc, al_map_rgb(128, 128, 128));
        al_draw_line(y - prostokat_szerokosc, 0, y - prostokat_szerokosc, prostokat_wysokosc, al_map_rgb(0, 0, 0), 2);

        y -= prostokat_szerokosc;
    }



    int liczba_beczek = 10;
    int odleglosc_miedzy_beczkami = 50;
    int x_poczatek = 0;

    for (int i = 0; i < liczba_beczek; i++) {

        al_draw_filled_ellipse(x_poczatek, 300, 50, 25, al_map_rgb(255, 255, 255));
        al_draw_filled_ellipse(x_poczatek, 400, 50, 25, al_map_rgb(255, 255, 255));

        al_draw_ellipse(x_poczatek, 300, 50, 25, al_map_rgb(0, 0, 0), 2);
        al_draw_ellipse(x_poczatek, 400, 50, 25, al_map_rgb(0, 0, 0), 2);
        al_draw_filled_rectangle(x_poczatek - 50, 300, x_poczatek + 50, 400, al_map_rgb(255, 255, 255));

        x_poczatek += odleglosc_miedzy_beczkami;
    }



    int x_koniec = 1800;
    int y_poczatek = 250;

    for (int i = 0; i < liczba_beczek; i++) {
        float y_gora = y_poczatek - 25;
        float y_dol = y_poczatek + 25;

        al_draw_filled_ellipse(x_koniec, y_gora, 50, 25, al_map_rgb(255, 255, 255));
        al_draw_filled_ellipse(x_koniec, y_dol, 50, 25, al_map_rgb(255, 255, 255));
        al_draw_ellipse(x_koniec, y_gora, 50, 25, al_map_rgb(0, 0, 0), 2);
        al_draw_ellipse(x_koniec, y_dol, 50, 25, al_map_rgb(0, 0, 0), 2);
        al_draw_filled_rectangle(x_koniec - 50, y_gora, x_koniec + 50, y_dol, al_map_rgb(255, 255, 255));

        x_koniec -= odleglosc_miedzy_beczkami;
    }






	bool running = true;
	al_flip_display();
	while (running) {
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);
		

		running = handle_events(event);

	}



	al_destroy_display(display);
}

bool handle_events(ALLEGRO_EVENT event) {
	handle_keyboard(event);

	if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		return false;
	}

	return true;
}
