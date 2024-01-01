#include "Player.h"

#include <iostream>
#include <string>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "Control.h"

#define SPRITE_DIMENSION 32
#define SPRITE_SHIFT 10.0f // it is related to position of shot
#define LENGTH_OF_FIRE 2000


Player::Player(int x, int y) {
	player = al_load_bitmap("player.png");
    position.setX(x);
    position.setY(y);
}

void Player::render(ALLEGRO_EVENT* events) {


	if (!player) {
		std::cout << "player init error" << std::endl;
	}

	if (events->type == ALLEGRO_EVENT_TIMER)
	{
		if (position.getActive())
			position.setState(position.getState()+32);
		else
			position.setState(32);

		if (position.getState() >= 96)
			position.setState(0);
	}

	al_draw_bitmap_region(player, position.getState(), position.getDirection(), 32, 32, position.getX(), position.getY(), NULL);
	//al_flip_display();
	//al_clear_to_color(al_map_rgb(0, 0, 0));
}


/*
	This function is reponsible for fire functionality. I
	It iterate for every enemy and checks wheter enemy is in field of fire
*/
void Player::shot(Gameplay* gameplay) {
	std::cout << " SPACE TEST " << std::endl;
	renderShot();

	float field_of_fire_y1 = 0, field_of_fire_y2 = 0;
	float field_of_fire_x1 = 0, field_of_fire_x2 = 0;
	float enemy_y = 0, enemy_x = 0;

	float distance = 0, lowestDistance = 10000000;
	bool isSomeoneShoted = false;
	int index = 0;
	//std::cout << "size: " << gameplay->enemies.size() << std::endl;

    for (auto& enemy : gameplay->enemies) {
        distance = enemy.distanceToPlayer(&this->position);

        enemy_x = enemy.getPosition()->getX();
        enemy_y = enemy.getPosition()->getY();

        field_of_fire_y1 = position.getY() + 2 * SPRITE_SHIFT - SPRITE_DIMENSION;
        field_of_fire_y2 = position.getY() + 2 * SPRITE_SHIFT;

        field_of_fire_x1 = position.getX() + SPRITE_SHIFT - SPRITE_DIMENSION;
        field_of_fire_x2 = position.getX() + SPRITE_SHIFT;

        if (position.getDirection() == UP && enemy_y < position.getY()) {
            if (field_of_fire_x1 <= enemy_x && enemy_x <= field_of_fire_x2) {
                isSomeoneShoted = true;
                if (lowestDistance > distance) {
                    lowestDistance = distance;
                    index = &enemy - &gameplay->enemies[0]; // Calculate the index
                }
            }
        }
        else if (position.getDirection() == DOWN && enemy_y > position.getY()) {
            if (field_of_fire_x1 <= enemy_x && enemy_x <= field_of_fire_x2) {
                isSomeoneShoted = true;
                if (lowestDistance > distance) {
                    lowestDistance = distance;
                    index = &enemy - &gameplay->enemies[0]; // Calculate the index
                }
            }
        }
        else if (position.getDirection() == LEFT && enemy_x < position.getX()) {
            if (enemy_y >= field_of_fire_y1 && enemy_y <= field_of_fire_y2) {
                isSomeoneShoted = true;
                if (lowestDistance > distance) {
                    lowestDistance = distance;
                    index = &enemy - &gameplay->enemies[0]; // Calculate the index
                }
            }
        }
        else if (position.getDirection() == RIGHT && enemy_x > position.getX()) {
            if (enemy_y >= field_of_fire_y1 && enemy_y <= field_of_fire_y2) {
                isSomeoneShoted = true;
                if (lowestDistance > distance) {
                    lowestDistance = distance;
                    index = &enemy - &gameplay->enemies[0]; // Calculate the index
                }
            }
        }
    }

    distance = 0;
    lowestDistance = 10000000;

    if (isSomeoneShoted) {
        isSomeoneShoted = false;
        points += 10;
        gameplay->killEnemy(index);
    }

}

void Player::drawLifeBar()
{

    ALLEGRO_COLOR bgColor = al_map_rgb(255, 255, 255);
    ALLEGRO_COLOR borderColor = al_map_rgb(0, 0, 0);
    ALLEGRO_COLOR lifeColor = al_map_rgb(255, 0, 0);

    al_draw_rectangle(100, 20, 700, 50, borderColor, 2);
    
  
        float lifeWidth = static_cast<float>(lifePoints) / 15.0 * 100;


        al_draw_rectangle(100, 20, 700, 50, borderColor, 2);
        //pasek zycia
    if (lifePoints > 0)
        al_draw_filled_rectangle(100, 20, 100 * lifePoints + 100, 50, lifeColor);
}

bool Player::giveDmg() {
    lifePoints--;
    if (lifePoints == 0)
        return true;
    return false;
}


void Player::pointsCounter(ALLEGRO_FONT* font)
{
	std::string text = "POINTS: " + std::to_string(points);
	al_draw_text(font, al_map_rgb(255, 255, 255), 1588, 40, ALLEGRO_ALIGN_CENTER, text.c_str());
}

void Player::renderShot() {
	
	float start_point_x = position.getX();
	float start_point_y = position.getY();

	float destination_x = position.getX();
	float destination_y = position.getY();

	if (position.getDirection() == UP) {
		destination_y -= LENGTH_OF_FIRE;
		start_point_x += SPRITE_SHIFT;
	}
	else if (position.getDirection() == DOWN) {
		destination_y += LENGTH_OF_FIRE;
		start_point_x += SPRITE_SHIFT;
	}
	else if (position.getDirection() == LEFT) {
		destination_x -= LENGTH_OF_FIRE;
		start_point_x += SPRITE_SHIFT;
		start_point_y += 2 * SPRITE_SHIFT;
	}
	else if (position.getDirection() == RIGHT) {
		destination_x += LENGTH_OF_FIRE;
		start_point_x += 2*SPRITE_SHIFT;
		start_point_y += 2*SPRITE_SHIFT;
	}

	al_draw_line(start_point_x, start_point_y, destination_x, destination_y, al_map_rgb(255, 255, 204), 2);
}