#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Movement {
protected:
	int x, y;
	int dx, dy;
	int width, height;
	bool visible;

public:
	Movement(){}
	Movement(int x, int y, int dx, int dy, int width, int height) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->width = width;
		this->height = height;
		visible = true;
	}

	~Movement(){}
	
	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }

	virtual void erase(){}
	virtual void move(){}
	virtual void draw(){}

	Rectangle getRectangle() {
		return Rectangle(x, y, width, height);
	}
};