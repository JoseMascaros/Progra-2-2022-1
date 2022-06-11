#pragma once
#include "Character.h"
#include "Hero.h"

class Enemy : public Character {
private:
	int type;
	//0 -> Horizontal
	//1 -> Vertical
	//2 -> Random
	//3 -> Persuit

public:
	Enemy(int width, int height, int type) : Character(width, height) {
		this->type = type;
		x = rand() % 60 * 10;
		y = rand() % 30 * 10;
		dx = dy = 5;
	}

	~Enemy(){}

	void move(Graphics^ g, Hero* hero) {
		int i = rand() % 4;
		switch (type)
		{
		case 0: //Horizontal
			if (x + width * 1.0 > g->VisibleClipBounds.Width || x < 0)dx *= -1;
			if (dx > 0) {
				idy = 2;
			}
			else {
				idy = 1;
			}
			x += dx;
			break;

		case 1: //Vertical
			if (y + height * 1.0 > g->VisibleClipBounds.Height || y < 0)dy *= -1;
			if (dy > 0) {
				idy = 0;
			}
			else {
				idy = 3;
			}
			y += dy;
			break;

		case 2: //Random
			switch (i)
			{
			case 0: //Left
				if (x > 0) {
					x -= dx;
					idy = 1;
				}
				break;

			case 1: //Right
				if (x + width * 1.0 < g->VisibleClipBounds.Width) {
					x += dx;
					idy = 2;
				}
				break;

			case 2: //Up
				if (y > 0) {
					y -= dy;
					idy = 3;
				}
				break;

			case 3: //Down
				if (y + height * 1.0 < g->VisibleClipBounds.Height) {
					y += dy;
					idy = 0;
				}
				break;
			}
			break;

		case 3: //Persuit
			if (x == hero->getX()) {
				x += 0;
			}
			else if (x > hero->getX()) {
				x -= dx;
				idy = 1;
			}
			else if (x < hero->getX()) {
				x += dx;
				idy = 2;
			}

			if (y == hero->getY()) {
				y += 0;
			}
			else if (y > hero->getY()) {
				y -= dy;
				idy = 3;
			}
			else if (y < hero->getY()) {
				y += dy;
				idy = 0;
			}
		}

		idx++;
		if (idx > 3)idx = 0;
	}
};