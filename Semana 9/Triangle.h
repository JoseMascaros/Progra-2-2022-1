#pragma once
#include <iostream>

using namespace System::Drawing;

class Triangle {
private:
	int x, y;
	int width, height;
	int dy;
	bool visible;

public:
	Triangle() {
		x = rand() % 500;
		y = rand() % 300 + 100;
		width = rand() % 30 + 10;
		height = rand() % 30 + 10;
		dy = rand() % 5 + 10;
		visible = true;
	}

	~Triangle() {}

	//Erase - Move - Draw

	void draw(Graphics^ g) {
		Pen^ p = gcnew Pen(Color::DarkViolet, 5);
		g->DrawLine(p, x, y, x, y + height);
		g->DrawLine(p, x, y + height, x + width, y + height);
		g->DrawLine(p, x + width, y + height, x, y);
	}

	void move(Graphics^ g) {
		if (y < 0 || y + height > g->VisibleClipBounds.Height) dy *= -1;
		y += dy;
	}

	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }

	Rectangle getRectangle() {
		return Rectangle(x, y, width, height);
	}

};