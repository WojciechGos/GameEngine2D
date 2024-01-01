#include "Interface.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <cmath>
#include <string>
#define M_PI 3.14159265358979323846
#define RADIUS 15

void Interface::menu() {

    al_clear_to_color(al_map_rgb(0, 0, 0));

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

        al_draw_line(0, prostokat_wysokosc, y / 2 + 300, prostokat_wysokosc, al_map_rgb(0, 0, 0), 2);
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
    float width, height;

    //od tego momentu kod na prostokat
    x = 650, y = 200, width = 450, height = 400;
    al_draw_filled_rectangle(x, y, x + width, y + height, al_map_rgb(70, 70, 70));
    al_draw_rectangle(x, y, x + width, y + height, al_map_rgb(255, 255, 255), 2);

    al_draw_text(al_create_builtin_font(), al_map_rgb(255, 255, 255), x + width / 2, y + height / 2 - 20, ALLEGRO_ALIGN_CENTER, "Start");
    al_draw_text(al_create_builtin_font(), al_map_rgb(255, 255, 255), x + width / 2, y + height / 2, ALLEGRO_ALIGN_CENTER, "Start");
}


void Interface::goodbye() {

    al_clear_to_color(al_map_rgb(0, 0, 0));

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

        al_draw_line(0, prostokat_wysokosc, y / 2 + 300, prostokat_wysokosc, al_map_rgb(0, 0, 0), 2);
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
    float width, height;

    //od tego momentu kod na prostokat
    x = 650, y = 200, width = 450, height = 400;
    al_draw_filled_rectangle(x, y, x + width, y + height, al_map_rgb(70, 70, 70));
    al_draw_rectangle(x, y, x + width, y + height, al_map_rgb(255, 255, 255), 2);

    al_draw_text(al_create_builtin_font(), al_map_rgb(255, 255, 255), x + width / 2, y + height / 2 - 20, ALLEGRO_ALIGN_CENTER, "Boxhead2");
    al_draw_text(al_create_builtin_font(), al_map_rgb(255, 255, 255), x + width / 2, y + height / 2, ALLEGRO_ALIGN_CENTER, "Przegrales Wylacz i wlacz, aby zagrac ponownie");
}
/**
 * @brief Draw the game map.
 *
 * This function draws the game map using filled rectangles and ellipses.
 * It includes walls and barrels as part of the environment.
 */
void Interface::drawMap()
{
    al_clear_to_color(al_map_rgb(0, 0, 0));

    //map
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

    //for (int i = 0; i < liczba_beczek; i++) {

    //    al_draw_filled_ellipse(x_poczatek, 300, 50, 25, al_map_rgb(255, 255, 255));
    //    al_draw_filled_ellipse(x_poczatek, 400, 50, 25, al_map_rgb(255, 255, 255));

    //    al_draw_ellipse(x_poczatek, 300, 50, 25, al_map_rgb(0, 0, 0), 2);
    //    al_draw_ellipse(x_poczatek, 400, 50, 25, al_map_rgb(0, 0, 0), 2);
    //    al_draw_filled_rectangle(x_poczatek - 50, 300, x_poczatek + 50, 400, al_map_rgb(255, 255, 255));

    //    x_poczatek += odleglosc_miedzy_beczkami;
    //}



    //int x_koniec = 1800;
    //int y_poczatek = 250;

    //for (int i = 0; i < liczba_beczek; i++) {
    //    float y_gora = y_poczatek - 25;
    //    float y_dol = y_poczatek + 25;

    //    al_draw_filled_ellipse(x_koniec, y_gora, 50, 25, al_map_rgb(255, 255, 255));
    //    al_draw_filled_ellipse(x_koniec, y_dol, 50, 25, al_map_rgb(255, 255, 255));
    //    al_draw_ellipse(x_koniec, y_gora, 50, 25, al_map_rgb(0, 0, 0), 2);
    //    al_draw_ellipse(x_koniec, y_dol, 50, 25, al_map_rgb(0, 0, 0), 2);
    //    al_draw_filled_rectangle(x_koniec - 50, y_gora, x_koniec + 50, y_dol, al_map_rgb(255, 255, 255));

    //    x_koniec -= odleglosc_miedzy_beczkami;
    //}
}

/**
 * @brief Display a blood effect at a specific position.
 *
 * This function draws a blood effect at the specified position (x0, y0).
 * It creates a semi-circular pattern using pixels and fills the center with
 * a filled circle to represent blood. The color used is red (255, 0, 0).
 *
 * @param x0 The x-coordinate of the center of the blood effect.
 * @param y0 The y-coordinate of the center of the blood effect.
 */
void Interface::blood(int x0, int y0)
{
    for (double alpha = 0; alpha <= M_PI / 2; alpha += 0.01) {
        int x = static_cast<int>(x0 + RADIUS * std::cos(alpha));
        int y = static_cast<int>(y0 - RADIUS * std::sin(alpha));

        al_draw_pixel(x, y, al_map_rgb(255, 0, 0));

        al_draw_pixel(x0 - (x - x0), y, al_map_rgb(255, 0, 0));
        al_draw_pixel(x, y0 + (y0 - y), al_map_rgb(255, 0, 0));
        al_draw_pixel(x0 - (x - x0), y0 + (y0 - y), al_map_rgb(255, 0, 0));
    }

    al_draw_filled_circle(x0, y0, RADIUS, al_map_rgb(255, 0, 0));
}


void Interface::barrel(int x0, int y0, int RX, int RY)
{
    //for (double alpha = 0; alpha < 2 * M_PI; alpha += 0.01) {
    //    int x = x0 + RX * cos(alpha);
    //    int y = y0 + RY * sin(alpha);

    //    al_draw_pixel(x, y, al_map_rgb(0, 0, 0));
    //    al_draw_pixel(x, y - 50, al_map_rgb(0, 0, 0));
    //}

    //al_draw_filled_ellipse(x0, y0 - 2.5, RX, RY, al_map_rgb(255, 255, 255));
    //al_draw_filled_ellipse(x0, y0 - 50, RX, RY, al_map_rgb(255, 255, 255));

    //al_draw_filled_rectangle(720, 550, 880, 600, al_map_rgb(255, 255, 255));
}
/*
	Interface file contains all classes related with drawing graphic.
*/
