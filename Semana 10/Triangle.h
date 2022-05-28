#pragma once
#include "Figure.h"

class Triangle : public Figure {
public:
	Triangle(int x, int y, int r, int g, int b) : Figure(x, y , r, g, b) {}
	~Triangle(){}

	//Erase - Move - Draw
	void draw(Graphics^ g) {
		Pen^ p = gcnew Pen(Color::FromArgb(r, this->g, b), 4);
		g->DrawLine(p, x, y, x, y + height);
		g->DrawLine(p, x, y + height, x + width, y + height);
		g->DrawLine(p, x + width, y + height, x, y);
	}
};