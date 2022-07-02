#pragma once
#include <iostream>
#include "Character.h"

class Astronaut : public Character {
private:
	int hp;

public: 
	Astronaut(int width, int height) : Character(width, height) {
		x = 150;
		y = 400;
		dx = dy = 15;
		hp = rand() % 6 + 5;
		zoomxy = 1.2;
	}

	~Astronaut(){}

	void move(Graphics^ g, char i) {
		switch (i)
		{
		case 'A':
			if (x > 0) {
				x -= dx;
				idy = 1;
			}
			break;

		case 'D':
			if (x + width * zoomxy < g->VisibleClipBounds.Width) {
				x += dx;
				idy = 2;
			}
			break;

		case 'W':
			if (y > 0) {
				y -= dy;
				idy = 3;
			}
			break;

		case 'S':
			if (y + height * zoomxy < g->VisibleClipBounds.Height) {
				y += dy;
				idy = 0;
			}
			break;
		}

		idx++;
		if (idx > 3)idx = 0;
	}

	int getHp() { return hp; }
	void decreaseHp() { hp--; }
};