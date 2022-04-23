#pragma once
#include "Ball.h"
#include "Square.h"
#include <vector>

class Controller {
private:
	vector<Ball*> balls;
	Square* square;
	int hp;

public:
	Controller() {
		square = new Square();
		hp = 10;
	}

	~Controller(){}

	void addBall() {
		balls.push_back(new Ball());
	}

	//Erase - Move - Draw
	void eraseEverything() {
		for (int i = 0; i < balls.size(); i++) {
			balls[i]->erase();
		}
		square->erase();
		Console::SetCursorPosition(1, 1);
		for (int i = 0; i < hp; i++) {
			cout << " ";
		}
	}

	void moveEverything() { //Auto movement
		for (int i = 0; i < balls.size(); i++) {
			balls[i]->move();
		}
	}

	void drawEverything() {
		for (int i = 0; i < balls.size(); i++) {
			balls[i]->draw();
		}
		square->draw();
		Console::SetCursorPosition(1, 1);
		for (int i = 0; i < hp; i++) {
			cout << char(3);
		}
	}

	void collision() {
		for (int i = 0; i < balls.size(); i++) {
			if (square->getRectangle().IntersectsWith(balls[i]->getRectangle())) {
				balls[i]->changeDirection();
				balls[i]->changeColor();
			}
		}

		//Verification
		for (int i = 0; i < balls.size(); i++) {
			if (balls[i]->getY() > 39) {
				balls[i]->setVisible(false);
				hp--;
			}
		}

		//Elimination
		for (int i = 0; i < balls.size(); i++) {
			if (balls[i]->getVisible() == false) {
				balls.erase(balls.begin() + i);
			}
		}
	}

	int getHp() { return hp; }
	Square* getSquare() { return square; }
};