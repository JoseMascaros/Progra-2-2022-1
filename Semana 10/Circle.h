#pragma once
#include "Figure.h"

class Circle : public Figure {
public:
	Circle(int x, int y, int r, int g, int b) : Figure(x , y, r, g, b) {
		width = height;
	}
	~Circle() {}

	//Erase - Move - Draw
	void draw(Graphics^ g) {
		Pen^ p = gcnew Pen(Color::FromArgb(r, this->g, b), 4);
		g->DrawEllipse(p, x, y, width, height);
	}
};