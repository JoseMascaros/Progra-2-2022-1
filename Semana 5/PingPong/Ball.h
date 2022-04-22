#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Ball {
private:
	int x, y;
	int dx, dy;
	int width, height;

public:
	Ball() {
		x = rand() % 20 + 20;
		y = 2;
		dx = 1;
		dy = 1;
		width = 1;
		height = 1;
	}

	~Ball(){}

	void erase() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void move() {
		if (x < 2 || x + width > 75) {
			dx *= -1;
		}
		if (y < 2 || y + height > 35) {
			dy *= -1;
		}
		x += dx;
		y += dy;
	}

	void draw() {
		Console::SetCursorPosition(x, y); cout << char(1);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width, height);
	}

	void changeDirection() {
		dy *= -1;
	}
};