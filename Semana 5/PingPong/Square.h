#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Square {
private:
	int x, y;
	int dx;
	int width, height;

public:
	Square() {
		x = 40;
		y = 30;
		dx = 2;
		height = 3;
		width = 12;
	}

	~Square(){}

	void erase() {
		Console::SetCursorPosition(x, y);     cout << "           ";
		Console::SetCursorPosition(x, y + 1); cout << "           ";
		Console::SetCursorPosition(x, y + 2); cout << "           ";
	}

	void move(char index) {
		switch (index)
		{
		case 'A':
			if (x > 0) x -= dx; break;
		case 'D':
			if (x + width < 80) x += dx;
		}
	}

	void draw() {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, y);     cout << "<--------->";
		Console::SetCursorPosition(x, y + 1); cout << "<----+---->";
		Console::SetCursorPosition(x, y + 2); cout << "<--------->";
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width, height);
	}
};