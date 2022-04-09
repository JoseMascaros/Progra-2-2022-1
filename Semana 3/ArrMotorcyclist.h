#pragma once
#include "Motocyclist.h"

class ArrMotorcyclist {
private:
	int n;
	Motorcyclist** arr; //Unique

public:
	ArrMotorcyclist() {
		n = 0;
		arr = new Motorcyclist * [n];
	}

	~ArrMotorcyclist(){}

	//CRUD
	//Create - Read - Update - Delete
	//CREATE
	void addMotorcyclist(Motorcyclist* m) {
		Motorcyclist** aux; //Duplicated
		aux = new Motorcyclist * [n + 1];

		for (int i = 0; i < n; i++) {
			aux[i] = arr[i];
		}

		aux[n] = m;
		n++;
		arr = aux;
	}

	void insertInPosition(int position, Motorcyclist* m) {
		Motorcyclist** aux; //Duplicated
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

	//READ
	void getRappiMotorcyclist() {
		for (int i = 0; i < n; i++) {
			if (arr[i]->getBusiness() == "Rappi") {
				arr[i]->getInformation();
			}
		}
	}

	void getGloboMotorcyclist() {
		for (int i = 0; i < n; i++) {
			if (arr[i]->getBusiness() == "Globo") {
				arr[i]->getInformation();
			}
		}
	}

	void getAllMotorcyclist() {
		for (int i = 0; i < n; i++) {
			arr[i]->getInformation();
		}
	}

	//UPDATE
	void editBusiness(int position, string newBusiness) {
		arr[position]->setBusiness(newBusiness);
	}


	//DELETE
	void deleteLastMotorcyclist() {
		Motorcyclist** aux; //Duplicated
		aux = new Motorcyclist * [n - 1];

		for (int i = 0; i < n - 1; i++) {
			aux[i] = arr[i];
		}
		
		n--;
		arr = aux;
	}

	void deleteInPosition(int position) {
		Motorcyclist** aux; //Duplicated
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

	
		
};