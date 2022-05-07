#pragma once
#include "Movement.h"

class Star : public Movement {
public:
	Star(){}
	Star(int x, int y, int dx, int dy, int width, int height) : Movement(x, y, dx, dy, width, height){}
	~Star(){}

	void erase() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void move() {
		if (y + height < 35) y += rand()% 2 + 1;
		else { y = 0; x = rand() % 70; }
	}

	void draw() {
		Console::SetCursorPosition(x, y); cout << "*";
	}
};