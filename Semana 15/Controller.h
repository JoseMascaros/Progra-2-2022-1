#pragma once
#include "Pikachu.h"
#include "Pokeball.h"
#include <vector>

using namespace std;

class Controller {
private:
	Pikachu* pikachu;
	vector<Pokeball*> pokeballs;
public:
	Controller(int x, int y, Bitmap^ bmpPikachu, int hp, Bitmap^ bmpPokeball) {
		pikachu = new Pikachu(x, y, bmpPikachu->Width / 4, bmpPikachu->Height / 4, hp);
		for (int i = 0; i < 3; i++) {
			pokeballs.push_back(new Pokeball(rand() % 600, rand() % 500, bmpPokeball->Width / 3, bmpPokeball->Height));
		}
	}

	~Controller(){}

	void drawEverything(Graphics^ g, Bitmap^ bmpPikachu, Bitmap^ bmpPokeball) {
		pikachu->draw(g, bmpPikachu);
		for each (Pokeball * p in pokeballs) {
			p->draw(g, bmpPokeball);
		}
	}

	void moveEverything(Graphics^ g){
		for each (Pokeball * p in pokeballs) {
			p->move(g);
		}
	}

	void collision() {
		//Verification
		for (int i = 0; i < pokeballs.size(); i++) {
			if (pikachu->getRectangle().IntersectsWith(pokeballs[i]->getRectangle())) {
				pokeballs[i]->setVisible(false);
				pikachu->decreaseHp();
				pikachu->setX(pikachu->getSpawnX());
				pikachu->setY(pikachu->getSpawnY());
			}
		}

		//Elimination
		for (int i = 0; i < pokeballs.size(); i++) {
			if (!pokeballs[i]->getVisible()) {
				pokeballs.erase(pokeballs.begin() + i);
			}
		}
	}

	Pikachu* getPikachu() {
		return pikachu;
	}
};