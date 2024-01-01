#include "Enemy.h"
#include "Gameplay.h"
#include <iostream>
#include <allegro5/allegro.h>
#include "Interface.h"

Gameplay::Gameplay(){

}

/*
	It set count of enemies in next round
*/
void Gameplay::startRound() {
	round++;
	enemyNumberInRound = float(enemyNumberInRound) * 2;
	ifNewRoundStarted = true;
	std::cout << "enemies in round: " << enemyNumberInRound << std::endl;

}

/*
	In this function there are performed all operations related to gameplay like:
		- checks whether a new round should start
		- spawns new set of enemies
	Timer need to be set to 1 second
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

int Gameplay::getEnemyNumber() {
	return (int)enemies.size();
}

void Gameplay::spawnEnemy() {
	enemyNumberAlive++;
	enemyNumberSpawned++;
	enemies.push_back(Enemy::spawnEnemy());
}

bool Gameplay::ifAllEnemiesAreDead() {
	if (enemyNumberAlive == 0) {
		return true;
	}
	return false;
}

void Gameplay::killEnemy(int index) {

	enemies[index].setIsAlive(false);

	deadEnemies.push_back(enemies[index]);
	enemies.erase(enemies.begin() + index);

	enemyNumberAlive--;
	std::cout << "enemy number alive: " << enemyNumberAlive << std::endl;
}
