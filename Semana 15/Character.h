#pragma once
#include <iostream>

using namespace System::Drawing;

class Character {
protected:
	int x, y; //coordinates in real time
	int width, height;
	int dx, dy;
	int idx, idy;
	int spawnX, spawnY; // initial coordinates
	bool visible;
	double zoomxy;

public:
	Character(int x, int y, int width, int height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		spawnX = x;
		spawnY = y;
		idx = idy = 0;
		visible = true;
		zoomxy = 1.0;
	}

	~Character(){}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		//Rectangle zoom = Rectangle(x, y, width * zoomxy, height * zoomxy);
		g->DrawImage(bmp, this->getRectangle(), sectionShown, GraphicsUnit::Pixel);
	}

	virtual void move(){}

	Rectangle getRectangle() {
		return Rectangle(x, y, width * zoomxy, height * zoomxy);
	}

	int getX() { return x; }
	int getY() { return y; }
	bool getVisible() { return visible; }
	int getSpawnX() { return spawnX; }
	int getSpawnY() { return spawnY; }
	void setX(int v) { x = v; }
	void setY(int v) { y = v; }
	void setVisible(bool v) { visible = v; }


};