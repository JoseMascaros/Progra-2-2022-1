#pragma once
#include "Character.h"

class Pokeball : public Character {
public:
	Pokeball(int x, int y, int width, int height) : Character(x, y, width, height) {
		dx = dy = 20;
	}

	~Pokeball(){}

	void move(Graphics^ g) {
		int i = rand() % 4;
		switch (i)
		{
		case 0:
			if (x > 0) {
				x -= dx;
			}
			break;

		case 1:
			if (x + width * zoomxy < g->VisibleClipBounds.Width) {
				x += dx;
			}
			break;

		case 2:
			if (y > 0) {
				y -= dy;
			}
			break;

		case 3:
			if (y + height * zoomxy < g->VisibleClipBounds.Height) {
				y += dy;
			}
		}

		idx++;
		if (idx > 2)idx = 0;
	}
};