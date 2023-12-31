#include <allegro5/allegro.h>
#include "Enemy.h"
#include <vector>
#include <allegro5/allegro.h>

#ifndef Gameplay_h
#define Gameplay_h

class Gameplay {

private:	
	int round = 0;
	int enemyNumberInRound = 10;
	int enemyNumberAlive = 0;
	int enemyNumberSpawned = 0;
	bool ifNewRoundStarted = false;
	bool ifAllEnemiesAreDead();
	void startRound();
	void spawnEnemy();

public:
	Gameplay();
	std::vector<Enemy> enemies;
	std::vector<Enemy> deadEnemies;
	int getEnemyNumber();
	void run(ALLEGRO_EVENT *event, ALLEGRO_TIMER* enemy_timer);
	void killEnemy(int index);
};



#endif