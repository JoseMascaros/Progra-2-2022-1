#pragma once
#include <iostream>
#include <string>

using namespace std;
// access levels -> private, public, protected

class Person {
private:
	//Atributos -> Caracteristicas
	string name;
	int age;
	int DNI;
	char gender;
	double height;
	double weight;

public:
	//Methods
	//Constructor 
	Person() {
		name = "";
		age = 0;
		generateDNI();
		gender = 'M';
		height = 0.0;
		weight = 0.0;
		cout << "Constructor executed" << endl;
	}

	Person(string name, int age, char gender) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		generateDNI();
		height = 0.0;
		weight = 0.0;
		cout << "Constructor executed" << endl;
	}

	Person(string name, int age, char gender, double height, double weight) {
		this->name = name;
		this->age = age;
		generateDNI();
		this->gender = gender;
		this->height = height;
		this->weight = weight;
		cout << "Constructor executed" << endl;
	}

	~Person(){
		cout << "Destructor executed" << endl;
	}

	bool isAdult() {
		if (age >= 18)return true;
		else return false;
	}

	void validateGender() {
		if (gender != 'M' && gender != 'F') {
			gender = 'M';
		}
	}

	void getInformation() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "DNI: " << DNI << endl;
		cout << "Gender: " << gender << endl;
		cout << "Height: " << height << endl;
		cout << "Weight: " << weight << endl;
 	}

	void generateDNI() {
		DNI = rand() % 9999999 + 10000000;
	}

	int calculateIMC() {
		double idealWeight = weight / (height * height);

		if (idealWeight < 20) return -1;
		if (idealWeight >= 20 && idealWeight <= 25) return 0;
		if (idealWeight > 25) return 1;
	}

	//Getters
	string getName() { return name; }
	int getAge() { return age; }
	int getDNI() { return DNI; }
	char getGender() { return gender; }
	double getHeight() { return height; }
	double getWeight() { return weight; }

	//Setters
	void setName(string v) { name = v; }
	void setAge(int v) { age = v; }
	void setDNI(int v) { DNI = v; }
	void setGender(char v) { gender = v; }
	void setHeight(double v) { height = v; }
	void setWeight(double v) { weight = v; }
};