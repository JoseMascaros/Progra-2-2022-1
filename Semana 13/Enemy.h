#pragma once
#include <iostream>

using namespace System::Drawing;

class Enemy {
private:
	int x, y;
	int dx, dy;
	int width, heigth;
	int idx, idy;
	double zoomxy;

public:
	Enemy(int x, int y, int width, int heigth){
		this->x = x;
		this->y = y;
		this->width = width;
		this->heigth = heigth;
		idx = idy = 0;
		dx = dy = 10;
		zoomxy = 1.0;
	}

	~Enemy(){}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * width, idy * heigth, width, heigth);
		Rectangle zoom = Rectangle(x, y, width * zoomxy, heigth * zoomxy);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void move(Graphics^ g) {
		int i = rand() % 4;
		switch (i)
		{
		case 0: // Left
			if (x > 0) {
				x -= dx;
				idy = 1;
			}
			break;

		case 1: // Right
			if (x + width * zoomxy < g->VisibleClipBounds.Width) {
				x += dx;
				idy = 2;
			}
			break;

		case 2: // Up
			if (y > 0) {
				y -= dy;
				idy = 3;
			}
			break;

		case 3: // Down
			if (y + heigth * zoomxy < g->VisibleClipBounds.Height) {
				y += dy;
				idy = 0;
			}
		}

		idx++;
		if (idx > 3)idx = 0;
	}

};