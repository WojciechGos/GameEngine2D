#include "Enemy.h"

#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <cmath>
#include "Interface.h"

#define ENEMY_SPEED 1.0f

#define INITIAL_ENEMY_POSITION_X 850
#define INITIAL_ENEMY_POSITION_Y 0

Enemy::Enemy(int x, int y) {
	bitmap = al_load_bitmap("zombie.png");
	position.setX(x);
	position.setY(y);
}

Enemy::Enemy() {
	bitmap = al_load_bitmap("zombie.png");
	this->state = 0;
	this->direction = 0;
}

void Enemy::setState(int state) {
	this->state = state;
}
void Enemy::setDirection(int direction) {
	this->direction = direction;
}
int Enemy::getState() {
	return this->state;
}
int Enemy::getDirection() {
	return this->direction;
}

Movement* Enemy::getPosition() {
	return &position;
}

bool Enemy::getIsAlive() {
	return this->isAlive;
}

void Enemy::updatePosition(Movement* player_position) {

	if (!isAlive)
		return;

	float dx = player_position->getX();
	float dy = player_position->getY();

	// Update enemy position
	float move_x = 0;
	float move_y = 0;

	float length = std::ceil(sqrt(dx * dx + dy * dy));

	if (length != 0) {
		dx /= length;
		dy /= length;
	}



	if (position.getX() < player_position->getX())
		move_x = std::ceil(dx * ENEMY_SPEED);
	else
		move_x = -1 * std::ceil(dx * ENEMY_SPEED);

	if (position.getY() < player_position->getY())
		move_y = std::ceil(dy * ENEMY_SPEED);
	else
		move_y = -1 * std::ceil(dy * ENEMY_SPEED);

	//std::cout << "move_x: " << move_x << " move_y: " << move_y << std::endl;
	//std::cout << "x: " << position.getX() << " y: " << position.getY() << std::endl;
	//std::cout << "player_x: " << player_position->getX() << " player_y: " << player_position->getY() << std::endl;
	
	position.setX(position.getX() + move_x);
	position.setY(position.getY() + move_y);
	
	if (position.getX() > player_position->getX())
	{
		if (position.getY() < player_position->getY())
		{
			setDirection(0);
		}
		else
		{
			setDirection(32);
		}
	}
	else if (position.getX() < player_position->getX())
	{
		if (position.getY() > player_position->getY())
		{
			setDirection(96);
		}
		else
		{
			setDirection(64);
		}
	}
}


void Enemy::render(ALLEGRO_EVENT events) {
	
	if (!isAlive) {
		Interface::blood(position.getX(), position.getY());
		return;
	}

	if (!bitmap) {
		std::cout << "enemy init error" << std::endl;
	}

	if (events.type == ALLEGRO_EVENT_TIMER)
	{
		if (true)
			setState(getState() + 32);
		if (getState() >= 96)
			setState(0);
	}

	al_draw_bitmap_region(bitmap, getState(), getDirection(), 32, 32, position.getX(), position.getY(), NULL);
}


Enemy Enemy::spawnEnemy() {
	Enemy enemy(INITIAL_ENEMY_POSITION_X, INITIAL_ENEMY_POSITION_Y);
	return enemy;
}
void Enemy::setIsAlive(bool state) {
	isAlive = state;
}
