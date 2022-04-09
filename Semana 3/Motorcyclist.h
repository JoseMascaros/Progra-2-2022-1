#pragma once
#include <iostream>
#include <string>

using namespace std;

string firstNames[7] = { "Jorge", "Caleb", "Juan", "Alessandra", "Jean", "Jan", "Adrian" };
string lastNames[7] = { "Rodriguez", "Coronal", "Achamizo","Ponce","Calisaya","Melgar", "Gutierrez" };
string businessNames[2] = { "Rappi" , "Globo" };

class Motorcyclist {
private:
	string firstName;
	string lastName;
	int plate;
	int kilometer;
	string business;

public:
	Motorcyclist() {
		firstName = firstNames[rand() % 7];
		lastName = lastNames[rand() % 7];
		plate = rand() % 20000 + 10000;
		kilometer = rand() % 41;
		business = businessNames[rand() % 2];
	}

	Motorcyclist(string firstName, string lastName, int plate, int kilometer, string business) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->plate = plate;
		this->kilometer = kilometer;
		this->business = business;
	}

	~Motorcyclist(){}

	double calculatePrice() {
		return double(kilometer) * 1.5;
	}

	string getBusiness() { return business; }
	void setBusiness(string v) { business = v; }

	void getInformation() {
		cout << "\t" << firstName << "\t" << lastName << "\t" << plate << "\t" << kilometer << "\t" << business << "\t" << calculatePrice() << "\t" << endl;
	}

};