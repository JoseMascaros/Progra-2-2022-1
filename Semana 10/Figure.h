#pragma once
#include <iostream>

using namespace std;
using namespace System::Drawing;

class Figure {
protected:
	int x, y;
	int dx, dy;
	int width, height;
	int r, g, b;
	
public:
	Figure(int x, int y, int r, int g, int b) {
		this->x = x;
		this->y = y;
		dx = dy = 10;
		width = rand() % 30 + 10;
		height = rand() % 30 + 10;
		this->r = r;
		this->g = g;
		this->b = b;
	}

	~Figure(){}

	//Erase - Move - Draw

	void move(Graphics^ g) {
		if (x < 0 || x + width > g->VisibleClipBounds.Width)dx *= -1;
		if (y < 0 || y + height > g->VisibleClipBounds.Height)dy *= -1;
		x += dx;
		y += dy;
	}

	virtual void draw(Graphics^ g) = 0;

	
};