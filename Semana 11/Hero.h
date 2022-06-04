#pragma once

using namespace System::Drawing;

class Hero {
private:
	int x, y;//coordinates
	int dx, dy; //movement
	int width, height;
	int idx, idy; //index

public:
	Hero(int width, int height) {
		this->width = width;
		this->height = height;
		x = 100;
		y = 100;
		dx = dy = 5;
		idx = idy = 0;
	}

	~Hero(){}

	void draw(Graphics^ g, Bitmap^ bmp) { //Graphics -> Canvas // Bitmap -> Image
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void move(Graphics^ g, char i) {
		//Direction and movement
		switch (i)
		{
		case 'A':
			if (x > 0) {
				x -= dx; //Movement
				idy = 1; //Direction
			}
			break;

		case 'D':
			if (x + width * 1.0 < g->VisibleClipBounds.Width) {
				x += dx;
				idy = 2;
			}
			break;

		case 'W':
			if (y > 0) {
				y -= dy;
				idy = 3;
			}
			break;

		case 'S':
			if (y + height * 1.0 < g->VisibleClipBounds.Height) {
				y += dy;
				idy = 0;
			}
			break;
		}

		//Animation
		idx++;
		if (idx > 3)idx = 0;
	}

	void still() {
		idx = 0;
	}


};