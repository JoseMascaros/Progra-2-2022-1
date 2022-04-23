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
	bool visible;
	int rgb;

public:
	Ball() {
		int r = rand() % 2;
		if (r == 0)dx = 1;
		else dx = -1;

		x = rand() % 20 + 20;
		y = 2;
		dy = 1;
		width = 1;
		height = 1;
		rgb = rand() % 5;
		visible = true;
	}

	~Ball(){}

	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
	int getY() { return y; }

	//Erase - Move - Draw
	void erase() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void move() {
		if (x < 1 || x + width > 69) {
			dx *= -1;
			changeColor();
		}
		if (y < 1) {
			dy *= -1;
			changeColor();
		}

		x += dx;
		y += dy;
	}

	void changeColor() {
		rgb = rand() % 5;
	}

	void draw() {
		switch (rgb)
		{
		case 0: 
			Console::ForegroundColor = ConsoleColor::Cyan; break;
		case 1:
			Console::ForegroundColor = ConsoleColor::Green; break;
		case 2:
			Console::ForegroundColor = ConsoleColor::Yellow; break;
		case 3:
			Console::ForegroundColor = ConsoleColor::Magenta; break;
		case 4:
			Console::ForegroundColor = ConsoleColor::Blue; break;
		}
		Console::SetCursorPosition(x, y); cout << char(1);
	}

	void changeDirection() {
		dy *= -1;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width, height);
	}
};