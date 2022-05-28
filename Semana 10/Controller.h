#pragma once
#include "Triangle.h"
#include "Circle.h"
#include "Square.h"
#include <vector>

class Controller {
private:
	vector<Triangle*> triangles;
	vector<Circle*> circles;
	vector<Square*> squares;

public:
	Controller(){}
	~Controller(){}

	void addTriangle(int x, int y, int r, int g, int b) {
		Triangle* t = new Triangle(x , y, r, g ,b);
		triangles.push_back(t);
	}

	void deleteTriangle() {
		triangles.pop_back();
	}

	void addCircle(int x, int y, int r, int g, int b) {
		circles.push_back(new Circle(x, y, r, g, b));
	}

	void deleteCircle() {
		circles.pop_back();
	}

	void addSquare(int x, int y, int r, int g, int b) {
		squares.push_back(new Square(x, y, r, g, b));
	}

	void deleteSquare() {
		squares.pop_back();
	}

	void moveEverything(Graphics^ g) {
		for (int i = 0; i < triangles.size(); i++) {
			triangles[i]->move(g);
		}
		for (int i = 0; i < circles.size(); i++) {
			circles[i]->move(g);
		}
		for (int i = 0; i < squares.size(); i++) {
			squares[i]->move(g);
		}
	}

	void drawEverything(Graphics^ g) {
		for (int i = 0; i < triangles.size(); i++) {
			triangles[i]->draw(g);
		}
		for (int i = 0; i < circles.size(); i++) {
			circles[i]->draw(g);
		}
		for (int i = 0; i < squares.size(); i++) {
			squares[i]->draw(g);
		}
	}

};