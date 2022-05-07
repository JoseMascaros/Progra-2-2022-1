#pragma once
#include "Person.h"
#include "Star.h"
#include <vector>

class Controller {
private:
	Person* person;
	vector<Star*> stars;
	int cont;
	time_t timer;
	time_t spawnStars;
	int hp;

public:
	Controller(){
		hp = 10;
		timer = time(0);
		spawnStars = time(0);
		cont = 0;
		for (int i = 0; i < 10; i++) {
			addStar();
		}
		person = new Person(40, 30, 2, 1, 1, 2);
	}
	~Controller(){}

	void addStar() {
		stars.push_back(new Star(rand() % 70, 0, 1, 1, 1, 1));
	}

	void eraseEverything() {
		Console::SetCursorPosition(0, 0); cout << "          "; 
		Console::SetCursorPosition(0, 1); cout << "          "; 
		Console::SetCursorPosition(0, 2); cout << "          "; 
		for (int i = 0; i < hp; i++) {
			Console::SetCursorPosition(60 + i, 0); cout << " ";
		}

		for (int i = 0; i < stars.size(); i++) {
			stars[i]->erase();
		}
		person->erase();
	}

	void moveEverything() { //Auto movement
		for (int i = 0; i < stars.size(); i++) {
			stars[i]->move();
		}
	}

	void drawEverything() {
		Console::SetCursorPosition(0, 0); cout << "Points: " << cont;
		Console::SetCursorPosition(0, 1); cout << "Timer: " << int(60 - clock() / 1000);
		Console::SetCursorPosition(0, 2); cout << "Stars " << stars.size();
		for (int i = 0; i < hp; i++) {
			Console::SetCursorPosition(60 + i, 0); cout << char(3);
		}


		for (int i = 0; i < stars.size(); i++) {
			stars[i]->draw();
		}
		person->draw();
	}

	bool timeOut() {
		if (difftime(time(0), timer) >= 60)return true;
		else return false;
	}

	void spawn() {
		if (difftime(time(0), spawnStars) >= 3) {
			spawnStars = time(0);
			addStar();
		}
	}

	void collision() {
		//Verification
		for (int i = 0; i < stars.size(); i++) {
			if (person->getRectangle().IntersectsWith(stars[i]->getRectangle())) {
				stars[i]->setVisible(false);
				cont++;
				hp--;
			}
		}

		//Elimination
		for (int i = 0; i < stars.size(); i++) {
			if (!stars[i]->getVisible()) {
				stars.erase(stars.begin() + i);
			}
		}
	}

	int getCont() { return cont; }
	Person* getPerson() { return person; }
};