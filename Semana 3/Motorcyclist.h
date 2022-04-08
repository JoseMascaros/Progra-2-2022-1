#pragma once
#include <iostream>
#include <string>

using namespace std;

string firstNames[7] = { "Pedro" , "Juan", "Noemi", "Lucho", "Lucia", "Marko", "Vania" };
string lastNames[6] = { "Sanchez" , "Rodriguez", "Mascaro", "Casas", "Rosas", "Rosales" };
string businessNames[2] = { "Rappi" , "Globo" };

class Motorcyclist {
private:
	string firstName;
	string lastName;
	int plate;
	int kilometers;
	string business;

public:
	
	//Defeault Constructor
	Motorcyclist() {
		firstName = firstNames[rand()% 7];
		lastName = lastNames[rand() % 6];
		plate = rand() % 20000 + 10000;
		kilometers = rand() % 41;
		business = businessNames[rand() % 2];
	}

	//Parameter Constructor
	Motorcyclist(string firstName, string lastName, int plate, int kilometers, string business) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->plate = plate;
		this->kilometers = kilometers;
		this->business = business;
	}

	~Motorcyclist(){}

	double calculatePrice() {
		return double(kilometers) * 1.5;
	}

	void getInformation() {
		cout <<"\t " << firstName << " \t " << lastName << " \t " << plate << " \t " << kilometers << " \t " << business << " \t " << calculatePrice() << " \t " << endl;
	}

	string getBusiness() { return business; }
	void setBusiness(string v) { business = v; }
};