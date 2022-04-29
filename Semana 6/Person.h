#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
	string name;
	int age;

public:
	Person(){}

	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}

	~Person(){}

	string getName() { return name; }
	int getAge() { return age; }
	void setName(string v) { name = v; }
	void setAge(int v) { age = v; }

	void getPersonInfo() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
	
};