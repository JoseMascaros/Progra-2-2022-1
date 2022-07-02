#pragma once
#include "Astronaut.h"
#include "Meteorite.h"
#include <vector>

using namespace std;

class Controller {
private:
	Astronaut* astronaut;
	vector<Meteorite*> meteorites;

public:
	Controller(Bitmap^ bmpAstronaut) {
		astronaut = new Astronaut(bmpAstronaut->Width / 4, bmpAstronaut->Height / 4);
	}

	~Controller(){}

	void addMeteorite(Meteorite* m) {
		meteorites.push_back(m);
	}

	void drawEverything(Graphics^ g, Bitmap^ bmpAstronaut, Bitmap^ bmpMeteorite) {
		astronaut->draw(g, bmpAstronaut);
		for (int i; i < meteorites.size(); i++) {
			meteorites[i]->draw(g, bmpMeteorite);
		}
	}

	void moveEverything(Graphics^ g) { //Automated movement
		for (int i; i < meteorites.size(); i++) {
			meteorites[i]->move(g);
		}
	}

	void collision() {
		//Verification
		for (int i = 0; i < meteorites.size(); i++) {
			if (astronaut->getRectangle().IntersectsWith(meteorites[i]->getRectangle())) {
				astronaut->decreaseHp();
				/*astronaut->setX(150);
				astronaut->setY(400);*/
				meteorites[i]->setVisible(false);
			}
		}

		//Elimination
		for (int i = 0; i < meteorites.size(); i++) {
			if (!meteorites[i]->getVisible()) {
				meteorites.erase(meteorites.begin() + i);
			}
		}
	}

	int getMeteoritesLanded() {
		int cont = 0;
		for (int i = 0; i < meteorites.size(); i++) {
			if (meteorites[i]->getLand()) {
				cont++;
			}
		}
		return cont;
	}

	Astronaut* getAstronaut() { return astronaut; }
};