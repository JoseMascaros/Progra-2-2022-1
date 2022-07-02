#pragma once
#include <iostream>
#include "Character.h"

class Meteorite : public Character {
private:
	bool land;

public:
	Meteorite(int width, int height) : Character(width, height) {
		land = false;
		x = rand() % 800;
		y = 3;
		dx = 0;
		dy = 5;
		zoomxy = rand() % 30 / 10 + 1;
	}

	~Meteorite(){}

	void move(Graphics^ g) {
		if (y + height * zoomxy < g->VisibleClipBounds.Height) {
			y += dy;
			idy++;
			if (idy > 7)idy = 0;
		}
		else {
			land = true;
		}
	}

	bool getLand() { return land; }
};