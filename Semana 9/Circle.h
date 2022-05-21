#pragma once
#include <iostream>

using namespace System::Drawing;

class Circle {
private:
	int x, y;
	int radio;
	int dx;
	bool visible;

public:
	Circle() {
		x = rand() % 500;
		y = rand() % 300 + 100;
		radio = rand() % 10 + 30;
		dx = rand() % 5 + 10;
		visible = true;
	}

	~Circle(){}

	//Erase - Move - Draw

	void draw(Graphics^ g) {
		/*Pen^ p = gcnew Pen(Color::Aquamarine, 7);
		g->DrawEllipse(p, x, y, 2 * radio, 2 * radio);*/

		SolidBrush^ b = gcnew SolidBrush(Color::Moccasin);
		g->FillEllipse(b, x, y, radio * 2, radio * 2);
	}

	void move(Graphics^ g) {
		if (x < 0 || x + 2 * radio > g->VisibleClipBounds.Width) dx *= -1;
		x += dx;
	}

	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }

	Rectangle getRectangle() {
		return Rectangle(x, y, 2 * radio, 2 * radio);
	}

};