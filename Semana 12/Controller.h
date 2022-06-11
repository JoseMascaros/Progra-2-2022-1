#pragma once
#include "Enemy.h"
#include "Hero.h"
#include <vector>

using namespace std;

class Controller {
private:
	Hero* hero;
	vector<Enemy*> enemies;

public:
	Controller(Bitmap^ bmpHero, Bitmap^ bmpEnemy) {
		hero = new Hero(bmpHero->Width / 4, bmpHero->Height / 4);
		enemies.push_back(new Enemy(bmpEnemy->Width / 4, bmpEnemy->Height / 4, 0));
		enemies.push_back(new Enemy(bmpEnemy->Width / 4, bmpEnemy->Height / 4, 1));
		enemies.push_back(new Enemy(bmpEnemy->Width / 4, bmpEnemy->Height / 4, 2));
		enemies.push_back(new Enemy(bmpEnemy->Width / 4, bmpEnemy->Height / 4, 3));
	}

	~Controller(){}

	void drawEverything(Graphics^ g, Bitmap^ bmpHero, Bitmap^ bmpEnemy) {
		hero->draw(g, bmpHero);
		for (int i = 0; i < enemies.size(); i++) {
			enemies[i]->draw(g, bmpEnemy);
		}
	}

	void moveEverything(Graphics^ g) {
		for (int i = 0; i < enemies.size(); i++) {
			enemies[i]->move(g, hero);
		}
	}

	void collision() {
		//Verification
		for (int i = 0; i < enemies.size(); i++) {
			if (hero->getRectangle().IntersectsWith(enemies[i]->getRectangle())) {
				hero->decreaseHp();
				enemies[i]->setVisible(false);
			}
		}

		//Elimination
		for (int i = 0; i < enemies.size(); i++) {
			if (!enemies[i]->getVisible()) {
				enemies.erase(enemies.begin() + i);
			}
		}
	}

	Hero* getHero() { return hero; }
};