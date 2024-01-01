#include "Enemy.h"
#include "Gameplay.h"
#include <iostream>
#include <allegro5/allegro.h>
#include "Interface.h"

/**
 * @brief Gameplay class responsible for managing game-related operations.
 *
 * The Gameplay class handles various game-related functions, such as
 * starting new rounds, spawning enemies, checking if enemies are defeated,
 * and running the main game loop. It uses Allegro for event handling and
 * timing purposes.
 */
Gameplay::Gameplay(){

}

/**
 * @brief Start a new round in the game.
 *
 * This function increments the round counter, increases the expected
 * number of enemies for the round, sets a flag indicating the start
 * of a new round, and prints the updated number of enemies to the console.
 */
void Gameplay::startRound() {
	round++;
	enemyNumberInRound = float(enemyNumberInRound) * 2;
	ifNewRoundStarted = true;
	std::cout << "enemies in round: " << enemyNumberInRound << std::endl;

}

/*
*	 @brief In this function there are performed all operations related to gameplay like:
*		- checks wherher a new round should start
*		- spawns new set of enemies
*	Timer need to be set to 1 second
*/
void Gameplay::run(ALLEGRO_EVENT* event, ALLEGRO_TIMER* enemy_timer) {
	if (event->type == ALLEGRO_EVENT_TIMER) {
		if (event->timer.source == enemy_timer) {
			if (enemyNumberAlive == 0 &&  (enemyNumberSpawned == enemyNumberInRound))
				startRound();
			
			if (enemyNumberInRound != enemyNumberSpawned) {
				spawnEnemy();
			}
		}
	}
}
/**
 * @brief Get the current number of enemies in the game.
 *
 * This function returns the current count of enemies in the game by
 * querying the size of the enemies vector.
 *
 * @return The number of enemies in the game.
 */
int Gameplay::getEnemyNumber() {
	return (int)enemies.size();
}
/**
 * @brief Spawn a new enemy.
 *
 * This function is responsible for spawning a new enemy in the game.
 * It increments the count of spawned enemies (enemyNumberSpawned) and
 * adds a newly spawned enemy to the list of enemies.
 */
void Gameplay::spawnEnemy() {
	enemyNumberAlive++;
	enemyNumberSpawned++;
	enemies.push_back(Enemy::spawnEnemy());
}
/**
 * @brief Check if all enemies are defeated.
 *
 * This function checks whether all enemies in the game are defeated.
 * It examines the number of alive enemies (enemyNumberAlive) and returns
 * true if there are no remaining enemies, indicating that the player has
 * successfully defeated all enemies. Otherwise, it returns false.
 *
 * @return true if all enemies are defeated, false otherwise.
 */

bool Gameplay::ifAllEnemiesAreDead() {
	if (enemyNumberAlive == 0) {
		return true;
	}
	return false;
}
/**
 * @brief Kill an enemy in the game.
 *
 * This function marks the specified enemy as not alive, adds it to the
 * list of dead enemies, and removes it from the list of alive enemies.
 * Additionally, it decrements the count of alive enemies (enemyNumberAlive)
 * and prints the updated number of alive enemies to the standard output.
 *
 * @param index The index of the enemy to be killed.
 */
void Gameplay::killEnemy(int index) {

	enemies[index].setIsAlive(false);

	deadEnemies.push_back(enemies[index]);
	enemies.erase(enemies.begin() + index);

	enemyNumberAlive--;
	std::cout << "enemy number alive: " << enemyNumberAlive << std::endl;
}
