#include "Control.h"

#include <allegro5/allegro.h>
#include <iostream>
#include "Engine.h"


/*
    Keyboard file contains all classes and functions that handle user's input.
*/


Movement::Movement() {
    this->x = 0;
    this->y = 0;
    this->state = 0;
    this->direction = 0;
    this->active = false;
}

Movement::Movement(float x, float y) {
    this->x = x;
    this->y = y;
}

//Movement Movement::update(Movement movement) {
//
//}

bool Movement::checkCollision() {
    
    if (direction == UP && ((y + MOVE <= 0)))
        return true;
       
    if (direction == DOWN && ((y + 30) >= screenHeight))
        return true;

    if (direction == LEFT && ((x - MOVE) <= 0))
        return true;

    if (direction == RIGHT && ((x + 30) >= screenWidth))
        return true;

    return false;
}

void Movement::setX(float x) {
    this->x = x;
}
void Movement::setY(float y) {
    this->y = y;
}
void Movement::setState(int state) {
    this->state = state;
}
void Movement::setDirection(int direction) {
    this->direction = direction;
}
void Movement::setActive(bool active) {
    this->active = active;
}

int Movement::getX() {
    return this->x;
}
int Movement::getY() {
    return this->y;
}
int Movement::getState() {
    return this->state;
}
int Movement::getDirection() {
    return this->direction;
}
bool Movement::getActive() {
    return this->active;
}

