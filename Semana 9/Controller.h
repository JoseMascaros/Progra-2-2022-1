#pragma once
#include "Circle.h"
#include "Triangle.h"
#include <vector>

using namespace std;

class Controller {
private:
	vector<Circle*> circles;
	vector<Triangle*> triangles;

public:
	Controller() {
		for (int i = 0; i < 5; i++) {
			addCircle();
		}
	}

	~Controller(){}

	void addCircle() {
		Circle* c = new Circle();
		circles.push_back(c);
	}

	void addTriangle() {
		Triangle* t = new Triangle();
		triangles.push_back(t);
	}

	void drawEverything(Graphics^ g) {
		for (int i = 0; i < circles.size(); i++) {
			circles[i]->draw(g);
		}
		for (int i = 0; i < triangles.size(); i++) {
			triangles[i]->draw(g);
		}
	}

	void moveEverything(Graphics^ g) {
		for (int i = 0; i < circles.size(); i++) {
			circles[i]->move(g);
		}
		for (int i = 0; i < triangles.size(); i++) {
			triangles[i]->move(g);
		}
	}

	void collision() {
		//Verification
		for (int i = 0; i < circles.size(); i++) {
			for (int j = 0; j < triangles.size(); j++) {
				if (circles[i]->getRectangle().IntersectsWith(triangles[j]->getRectangle())) {
					circles[i]->setVisible(false);
					triangles[j]->setVisible(false);
				}
			}
		}

		//Elimination
		for (int i = 0; i < circles.size(); i++) {
			if (!circles[i]->getVisible()) {
				circles.erase(circles.begin() + i);
			}
		}

		for (int i = 0; i < triangles.size(); i++) {
			if (!triangles[i]->getVisible()) {
				triangles.erase(triangles.begin() + i);
			}
		}

	}

};