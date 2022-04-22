#pragma once
#include "Ball.h"
#include "Square.h"

class Controller {
private:
	Square* square;
	Ball* ball;
	int cont;

public:
	Controller() {
		square = new Square();
		ball = new Ball();
		cont = 0;
	}

	//Erase - Move - Draw
	void eraseEverything() {
		square->erase();
		ball->erase();
	}

	void moveEverything() { //Automatic Move
		ball->move();
	}

	void drawEverrything() {
		square->draw();
		ball->draw();
	}

	void collision() {
		if (square->getRectangle().IntersectsWith(ball->getRectangle())) {
			ball->changeDirection();
			cont++;
		}
	}

	Square* getSquare() { return square; }
	int getCont() { return cont; }
};