#include "Player.h"

#include <iostream>
#include <string>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


Player::Player(int x, int y) {
    position.setX(x);
    position.setY(y);
}

void Player::render() {
	ALLEGRO_BITMAP* player = al_load_bitmap("player.png");


	if (!player) {
		std::cout << "player init error" << std::endl;
	}

	//al_clear_to_color(al_map_rgb(0, 0, 0));
	
	//al_draw_bitmap_region(player, movement->getX(), movement->getY(), 100, 100, 100, 100, 0);
	al_draw_bitmap(player, position.getX(), position.getY(), 0);

}

void render_shot(Movement* movement) {
}

void Player::drawLifeBar()
{
    ALLEGRO_COLOR borderColor = al_map_rgb(0, 0, 0);
    ALLEGRO_COLOR lifeColor = al_map_rgb(255, 0, 0);

    al_draw_rectangle(100, 20, 700, 50, borderColor, 2);
    
        //pasek zycia
        if (hp > 0 /*&& hitplayer()*/)
            //hp-=10;
            al_draw_filled_rectangle(100, 20, 7*hp , 50, lifeColor);
}

void Player::pointsCounter()
{
    int points = 0;
    /*
    if player killed enemy
    points =+1;
    */

    std::string text = "POINTS: " + std::to_string(points);
    al_draw_text(al_create_builtin_font(), al_map_rgb(255, 255, 255), 1588, 40, ALLEGRO_ALIGN_CENTER, ("Points: " + std::to_string(points)).c_str());
}
