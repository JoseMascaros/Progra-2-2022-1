#pragma once
#include "Character.h"

class Hero : public Character {
private:
	int hp; //Health Points

public:
	Hero(int width, int height) : Character(width, height) {
		x = y = 100;
		dx = dy = 10;
		hp = 5;
	}

	~Hero(){}

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
			if (x + width * 1.0 < g->VisibleClipBounds.Width) {
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
			if (y + height * 1.0 < g->VisibleClipBounds.Height) {
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