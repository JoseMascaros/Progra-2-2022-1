#pragma once
#include <vector>
#include "Square.h"

class ArrSquare {
private:
	/*int n;
	Square** arr;*/
	vector<Square*> arr;

public:
	ArrSquare() {
		/*n = 0;
		arr = new Square * [n];*/
	}

	~ArrSquare(){}

	//void addSquare(Square* m) {
	//	Square** aux; //Duplicated
	//	aux = new Square * [n + 1];

	//	for (int i = 0; i < n; i++) {
	//		aux[i] = arr[i];
	//	}

	//	aux[n] = m;
	//	n++;
	//	arr = aux;
	//}
	
	void addSquare(Square* s) {
		arr.push_back(s);
	}

	//void insertInPosition(int position, Square* m) {
	//	Square** aux; //Duplicated
	//	aux = new Square * [n + 1];

	//	for (int i = 0; i < position; i++) {
	//		aux[i] = arr[i];
	//	}

	//	aux[position] = m;

	//	for (int i = position; i < n; i++) {
	//		aux[i + 1] = arr[i];
	//	}

	//	n++;
	//	arr = aux;
	//}

	void insertInPosition(int position, Square* s) {
		arr.insert(arr.begin() + position, s);
	}

	//void deleteLastSquare() {
	//	Square** aux; //Duplicated
	//	aux = new Square * [n - 1];

	//	for (int i = 0; i < n - 1; i++) {
	//		aux[i] = arr[i];
	//	}

	//	n--;
	//	arr = aux;
	//}

	void deleteLastSquare() {
		arr.pop_back();
	}

	//void deleteInPosition(int position) {
	//	Square** aux; //Duplicated
	//	aux = new Square * [n - 1];

	//	for (int i = 0; i < position; i++) {
	//		aux[i] = arr[i];
	//	}

	//	for (int i = position; i < n; i++) {
	//		aux[i] = arr[i + 1];
	//	}

	//	n--;
	//	arr = aux;
	//}

	void deleteInPosition(int position) {
		arr[position]->erase();
		arr.erase(arr.begin() + position);
	}

	//Erase - Move - Draw
	void eraseEverything() {
		for (int i = 0; i < arr.size(); i++) {
			//arr[i]->erase();
			arr.at(i)->erase();
		}
	}

	void moveEverything() {
		for (int i = 0; i < arr.size(); i++) {
			arr[i]->move();
		}
	}

	void drawEverything() {
		for (int i = 0; i < arr.size(); i++) {
			arr[i]->draw();
		}
	}

	void changeColors() {
		for (int i = 0; i < arr.size(); i++) {
			arr[i]->changeColor();
		}
	}

};