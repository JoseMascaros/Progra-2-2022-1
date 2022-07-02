#pragma once

using namespace System::Drawing;

class Character {
protected:
	int x, y;
	int dx, dy;
	int width, height;
	int idx, idy;
	bool visible;
	double zoomxy;

public:
	Character(int width, int height) {
		this->width = width;
		this->height = height;
		idx = 0;
		idy = 0;
		visible = true;
	}

	~Character(){}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * zoomxy, height * zoomxy);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	virtual void move(){}

	void setVisible(bool v) { visible = v; }
	bool getVisible() { return visible; }
	void setX(int v) { x = v; }
	void setY(int v) { y = v; }

	Rectangle getRectangle() {
		return Rectangle(x, y, width * zoomxy, height * zoomxy);
	}
};