#include "Person.h"

Person::Person(string name, int age, char gender, double weight, double height) {
	this->name = name;
	this->age = age;
	this->gender = gender;
	validateGender();
	generateDNI();
	this->weight = weight;
	this->height = height;
	cout << "Constructor executed" << endl;
}

bool Person::isAdult() {
	if (age >= 18)return true;
	else return false;
}

void Person::validateGender(){
	if (gender != 'M' && gender != 'F') {
		gender = 'M';
	}
}

void Person::generateDNI(){
	DNI = rand() % 9999999 + 10000000;
}

void Person::getInformation(){
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Gender: " << gender << endl;
	cout << "DNI: " << DNI << endl;
	cout << "Weight: " << weight << endl;
	cout << "Height: " << height << endl << endl;
}

int Person::calculateIMC(){
	double idealWeight = weight / (height * height);
	if (idealWeight < 20)return -1;
	if (idealWeight >= 20 && idealWeight <= 25)return 0;
	if (idealWeight > 25) return 1;
}


