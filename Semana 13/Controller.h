#pragma once
#include "Enemy.h"
#include <vector>

using namespace std;

class Controller {
private:
	vector<Enemy*> enemiesA;
	vector<Enemy*> enemiesB;
	vector<Enemy*> enemiesC;

public:
	Controller(Enemy* enemyA, Enemy* enemyB, Enemy* enemyC) {
		enemiesA.push_back(enemyA);
		enemiesB.push_back(enemyB);
		enemiesC.push_back(enemyC);
	}

	~Controller(){}

	void drawEverything(Graphics^ g, Bitmap^ bmpEnemyA, Bitmap^ bmpEnemyB, Bitmap^ bmpEnemyC) {	
		for (int i = 0; i < enemiesA.size(); i++) {
			enemiesA[i]->draw(g, bmpEnemyA);
		}
		for (int i = 0; i < enemiesB.size(); i++) {
			enemiesB[i]->draw(g, bmpEnemyB);
		}
		for (int i = 0; i < enemiesC.size(); i++) {
			enemiesC[i]->draw(g, bmpEnemyC);
		}
	}

	void moveEverything(Graphics^ g) {
		for (int i = 0; i < enemiesA.size(); i++) {
			enemiesA[i]->move(g);
		}
		for (int i = 0; i < enemiesB.size(); i++) {
			enemiesB[i]->move(g);
		}
		for (int i = 0; i < enemiesC.size(); i++) {
			enemiesC[i]->move(g);
		}
	}

	void addEnemyA(Enemy* e) {
		enemiesA.push_back(e);
	}
	void addEnemyB(Enemy* e) {
		enemiesB.push_back(e);
	}
	void addEnemyC(Enemy* e) {
		enemiesC.push_back(e);
	}
	void makeEnemiesAEmpty() {
		enemiesA.clear();
	}
};