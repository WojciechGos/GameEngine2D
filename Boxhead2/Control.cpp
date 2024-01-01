#include "Control.h"

#include <allegro5/allegro.h>
#include <iostream>
#include "Engine.h"


/**
 * @brief Movement class representing the position and state of a game character.
 *
 * The Movement class manages the position (x, y), state, direction, and activity status
 * of a game character. It provides methods to set and retrieve these properties.
 */
Movement::Movement() {
    this->x = 0;
    this->y = 0;
    this->state = 0;
    this->direction = 0;
    this->active = false;
}
/**
 * @brief Overloaded constructor for the Movement class.
 *
 * Initializes the Movement object with specified initial x and y coordinates.
 *
 * @param x The initial x-coordinate of the character.
 * @param y The initial y-coordinate of the character.
 */
Movement::Movement(float x, float y) {
    this->x = x;
    this->y = y;
}


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


/**
 * @brief Set the x-coordinate of the character.
 *
 * @param x The x-coordinate to set.
 */
void Movement::setX(float x) {
    this->x = x;
}

/**
 * @brief Set the y-coordinate of the character.
 *
 * @param y The y-coordinate to set.
 */
void Movement::setY(float y) {
    this->y = y;
}

/**
 * @brief Set the state of the character.
 *
 * @param state The state value to set.
 */
void Movement::setState(int state) {
    this->state = state;
}

/**
 * @brief Set the direction of the character.
 *
 * @param direction The direction value to set.
 */

void Movement::setDirection(int direction) {
    this->direction = direction;
}
/**
 * @brief Set the activity status of the character.
 *
 * @param active The activity status to set (true if active, false otherwise).
 */

void Movement::setActive(bool active) {
    this->active = active;
}
/**
 * @brief Get the x-coordinate of the character.
 *
 * @return The current x-coordinate of the character.
 */
int Movement::getX() {
    return this->x;
}
/**
 * @brief Get the y-coordinate of the character.
 *
 * @return The current y-coordinate of the character.
 */

int Movement::getY() {
    return this->y;
}

/**
 * @brief Get the state of the character.
 *
 * @return The current state of the character.
 */
int Movement::getState() {
    return this->state;
}

/**
 * @brief Get the direction of the character.
 *
 * @return The current direction of the character.
 */
int Movement::getDirection() {
    return this->direction;
}

/**
 * @brief Get the activity status of the character.
 *
 * @return The current activity status of the character (true if active, false otherwise).
 */
bool Movement::getActive() {
    return this->active;
}

