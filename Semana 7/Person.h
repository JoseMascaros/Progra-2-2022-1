#pragma once
#include "Movement.h"
#include <iostream>

using namespace std;


class Person : public Movement {
public:
	Person(){}
	Person(int x, int y, int dx, int dy, int width, int height) : Movement(x, y, dx, dy, width, height) {}
	~Person(){}

	void erase() {
		Console::SetCursorPosition(x, y);     cout << " ";
		Console::SetCursorPosition(x, y + 1); cout << " ";
	}

	void move(char key) {
		switch (key)
		{
		case 'A':
			if (x > 0)x -= dx; break;
		case 'D':
			if (x + width < Console::WindowWidth) x += dx; break;
		}
	}

	void draw() {
		Console::SetCursorPosition(x, y);     cout << "@";
		Console::SetCursorPosition(x, y + 1); cout << "┼";
	}
};