#pragma once
#include <iostream>

using namespace std;
using namespace System;

class Square {
private:
	int x, y; //Coordinates
	int dx, dy; // Movement
	int color;

public:

	Square() {
		x = 2;
		y = 2;
		dx = 1;
		dy = 1;
		color = rand() % 5;
	}

	~Square(){}

	//Erase - Move - Draw

	void erase() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void move() {
		if (x < 60 && y == 2) x += dx;
		if (y < 30 && x == 60) y += dy;
		if (x > 2 && y == 30) x -= dx;
		if (y > 2 && x == 2) y -= dy;
	}

	void draw() {
		switch (color) {
		case 0: Console::ForegroundColor = ConsoleColor::Magenta; break;
		case 1: Console::ForegroundColor = ConsoleColor::Blue; break;
		case 2: Console::ForegroundColor = ConsoleColor::Yellow; break;
		case 3: Console::ForegroundColor = ConsoleColor::Green; break;
		case 4: Console::ForegroundColor = ConsoleColor::Red; break;
		}
		Console::SetCursorPosition(x, y); cout << char(219);
	}

	void changeColor() {
		color = rand() % 5;
	}


};