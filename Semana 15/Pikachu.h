#pragma once
#include "Character.h"

class Pikachu : public Character {
private:
	int hp; //Health Points

public:
	Pikachu(int x, int y, int width, int height, int hp) : Character(x, y, width, height) {
		this->hp = hp;
		dx = dy = 10;
	}

	~Pikachu(){}

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
		}

		idx++;
		if (idx > 3)idx = 0;
	}

	int getHp() { return hp; }
	void decreaseHp() { hp--; }
};