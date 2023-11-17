#include "Enemy.h"

#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>


#define ENEMY_SPEED 2.0f


void update_enemy_position(Movement* enemy_position, Movement* player_position) {

	float dx = player_position->getX();
	float dy = player_position->getY();

	float length = sqrt(dx * dx + dy * dy);

	if (length != 0) {
		dx /= length;
		dy /= length;
	}


	// Update enemy position

	float move_x = 0;
	float move_y = 0;
	if (enemy_position->getX() < player_position->getX())
		move_x = dx * ENEMY_SPEED;
	else
		move_x = -1 * dx * ENEMY_SPEED;

	if (enemy_position->getY() < player_position->getY())
		move_y = dy * ENEMY_SPEED;
	else
		move_y = -1 * dy * ENEMY_SPEED;


	enemy_position->setX(enemy_position->getX() +move_x);
	enemy_position->setY(enemy_position->getY() + move_y);

	//enemy_position->setY(enemy_position->getY() - (dy * speed));
	std::cout << "player_x: " << player_position->getX() << " player_y: " << player_position->getY() << std::endl;
	std::cout << "dx: " << dx << " dy: " << dy << std::endl;
	std::cout << "enemy_x: " << enemy_position->getX() << " enemy_y: " << enemy_position->getY() << std::endl;
}


void render_enemy(Movement* movement) {
	ALLEGRO_BITMAP* enemy = al_load_bitmap("zombie.png");


	if (!enemy) {
		std::cout << "enemy init error" << std::endl;
	}

	//al_clear_to_color(al_map_rgb(0, 0, 0));,
	al_draw_bitmap(enemy, movement->getX(), movement->getY(), 0);

}
