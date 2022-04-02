#pragma once
#include <iostream>
#include <string>

using namespace std;

//Access levels -> Private, Public, Protected
class Person {
private: //Atributes
	string name; // "Hola Mundo"
	int age;
	int DNI;
	char gender;
	double weight;
	double height;

public: //Methods -> Functions
	//Constructors
	Person() {
		name = "";
		age = 0;
		gender = 'M';
		generateDNI();
		weight = 0.0;
		height = 0.0;
		cout << "Constructor executed" << endl;
	}

	Person(string name, int age, char gender) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		validateGender();
		generateDNI();
		weight = 0.0;
		height = 0.0;
		cout << "Constructor executed" << endl;
	}

	Person(string name, int age, char gender, double weight, double height);

	//Destructor
	~Person(){
		cout << "Destructor executed" << endl;
	}

	//Getters
	string getName() { return name; }
	int getAge() { return age; }
	int getDNI() { return DNI; }
	char getGender() { return gender; }
	double getWeight() { return weight; }
	double getHeight() { return height; }

	//Setters
	void setName(string v) { name = v; }
	void setAge(int v) { age = v; }
	void setDNI(int v) { DNI = v; }
	void setGender(char v) { gender = v; }
	void setWeight(double v) { weight = v; }
	void setHeight(double v) { height = v; }

	//Operations
	//Implemented in Person.cpp
	bool isAdult();
	void validateGender();
	void generateDNI();
	void getInformation();
	int calculateIMC();
};