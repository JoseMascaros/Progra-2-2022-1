#pragma once
#include "Motorcyclist.h"

class ArrMotorcyclist {
private:
	int n;
	Motorcyclist** arr; //unique

public:
	ArrMotorcyclist() {
		n = 0;
		arr = new Motorcyclist * [n];
	}

	~ArrMotorcyclist(){}

	void addMotorcyclist() {
		Motorcyclist* m = new Motorcyclist();
		Motorcyclist** aux; //duplicated
		aux = new Motorcyclist * [n + 1];

		for (int i = 0; i < n; i++) {
			aux[i] = arr[i];
		}

		aux[n] = m;
		n++;
		arr = aux;
	}

	void addMotorcyclist(Motorcyclist* m) {
		Motorcyclist** aux; //duplicated
		aux = new Motorcyclist * [n + 1];

		for (int i = 0; i < n; i++) {
			aux[i] = arr[i];
		}

		aux[n] = m;
		n++;
		arr = aux;
	}

	void insertMotorcyclist(int position) {
		Motorcyclist* m = new Motorcyclist();
		Motorcyclist** aux; //duplicated
		aux = new Motorcyclist * [n + 1];

		for (int i = 0; i < position; i++) {
			aux[i] = arr[i];
		}

		aux[position] = m;

		for (int i = position; i < n; i++) {
			aux[i + 1] = arr[i];
		}

		n++;
		arr = aux;
	}

	void deleteLastMotorcyclist() {
		Motorcyclist** aux; //duplicated
		aux = new Motorcyclist * [n - 1];

		for (int i = 0; i < n - 1; i++) {
			aux[i] = arr[i];
		}

		n--;
		arr = aux;
	}

	void deleteInPosition(int position) {
		Motorcyclist** aux; //duplicated
		aux = new Motorcyclist * [n - 1];

		for (int i = 0; i < position; i++) {
			aux[i] = arr[i];
		}

		for (int i = position; i < n; i++) {
			aux[i] = arr[i + 1];
		}

		n--;
		arr = aux;
	}

	void editBusiness(int position, string newBusiness) {
		arr[position]->setBusiness(newBusiness);
	}

	void getAllMotorcyclist() {
		//cout << "\t First Name " << "\t Last Name " << "\t Plate " << "\t Kilometers " << "\t Busis " << "\t Price " << endl;
		for (int i = 0; i < n; i++) {
			arr[i]->getInformation(); 
		}
	}

	void getRappiMotocyclist() {
		for (int i = 0; i < n; i++) {
			if(arr[i]->getBusiness() == "Rappi") arr[i]->getInformation();
		}
	}

	void getGloboMotocyclist() {
		for (int i = 0; i < n; i++) {
			if (arr[i]->getBusiness() == "Globo") arr[i]->getInformation();
		}
	}

};