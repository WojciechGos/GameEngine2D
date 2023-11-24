#include "Interface.h"

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


Interface::Interface(){}

void Interface::menu() {

    al_clear_to_color(al_map_rgb(0, 0, 0));

    //map
    al_draw_filled_rectangle(0, 0, 1800, 900, al_map_rgb(217, 186, 140));
    //gora mapy
    int liczba_prostokatow = 8;
    int x = 0;
    int prostokat_szerokosc = 100;
    int prostokat_wysokosc = 50;

    for (int i = 0; i < liczba_prostokatow; i++) {
        al_draw_filled_rectangle(x, 0, x + prostokat_szerokosc, prostokat_wysokosc, al_map_rgb(128, 128, 128));
        al_draw_line(x + prostokat_szerokosc, 0, x + prostokat_szerokosc, prostokat_wysokosc, al_map_rgb(0, 0, 0), 2);

        x += prostokat_szerokosc;
    }
    for (int i = 0; i < liczba_prostokatow; i++) {

        al_draw_line(200 + x, prostokat_wysokosc, x + 4 * prostokat_szerokosc, prostokat_wysokosc, al_map_rgb(0, 0, 0), 5);
        x += prostokat_szerokosc;
    }
    int y = 1800;


    for (int i = 0; i < liczba_prostokatow; i++) {
        al_draw_filled_rectangle(y - prostokat_szerokosc, 0, y, prostokat_wysokosc, al_map_rgb(128, 128, 128));
        al_draw_line(y - prostokat_szerokosc, 0, y - prostokat_szerokosc, prostokat_wysokosc, al_map_rgb(0, 0, 0), 2);

        y -= prostokat_szerokosc;
    }

    for (int i = 0; i < liczba_prostokatow; i++) {

        al_draw_line(0, prostokat_wysokosc, y/2+300, prostokat_wysokosc, al_map_rgb(0, 0, 0), 2);
        y -= prostokat_szerokosc;
    }



    //przeszkody
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

    //start
    x = 600, y = 200, width = 450, height = 400;
    al_draw_filled_rectangle(x, y, x + width, y + height, al_map_rgb(70, 70, 70));
    al_draw_rectangle(x, y, x + width, y + height, al_map_rgb(255, 255, 255), 2);

    al_draw_text(al_create_builtin_font(), al_map_rgb(255, 255, 255), x + width / 2 , y + height / 2 - 20, ALLEGRO_ALIGN_CENTER, "BOXHEAD 2");
    al_draw_text(al_create_builtin_font(), al_map_rgb(255, 255, 255), x + width / 2, y + height / 2, ALLEGRO_ALIGN_CENTER, "Start");
}

void Interface::drawMap()
{
    al_clear_to_color(al_map_rgb(0, 0, 0));

    //map
    al_draw_filled_rectangle(0, 0, 1800, 900, al_map_rgb(217, 186, 140));

    //gora mapy
    int liczba_prostokatow = 8;
    int x = 0;
    int prostokat_szerokosc = 100;
    int prostokat_wysokosc = 50;

    for (int i = 0; i < liczba_prostokatow; i++) {
        al_draw_filled_rectangle(x, 0, x + prostokat_szerokosc, prostokat_wysokosc, al_map_rgb(128, 128, 128));
        al_draw_line(x + prostokat_szerokosc, 0, x + prostokat_szerokosc, prostokat_wysokosc, al_map_rgb(0, 0, 0), 2);

        x += prostokat_szerokosc;
    }
    
    for (int i = 0; i < liczba_prostokatow; i++) {

        al_draw_line(200 + x, prostokat_wysokosc, x + 4* prostokat_szerokosc, prostokat_wysokosc, al_map_rgb(0, 0, 0), 5);
        x += prostokat_szerokosc;
    }

    int y = 1800;

    for (int i = 0; i < liczba_prostokatow; i++) {
        al_draw_filled_rectangle(y - prostokat_szerokosc, 0, y, prostokat_wysokosc, al_map_rgb(128, 128, 128));
        al_draw_line(y - prostokat_szerokosc, 0, y - prostokat_szerokosc, prostokat_wysokosc, al_map_rgb(0, 0, 0), 2);

        y -= prostokat_szerokosc;
    }
    for (int i = 0; i < liczba_prostokatow; i++) {

        al_draw_line(0, prostokat_wysokosc, y / 2 + 300, prostokat_wysokosc, al_map_rgb(0, 0, 0), 2);
        y -= prostokat_szerokosc;
    }


    //przeszkody
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
}

/*
	Interface file contains all classes related with drawing graphic.
*/
