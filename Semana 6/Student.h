#pragma once
#include "Person.h"

class Student : public Person {
protected:
	int id;
	string studyLevel;

public:
	Student(){}
	Student(string name, int age, string studyLevel) : Person(name, age) {
		id = rand() % 8000 + 2000; //2000 - 9999
		this->studyLevel = studyLevel;
	}

	~Student(){}

	void getStudentInfo() {
		getPersonInfo();
		cout << "Id: " << id << endl;
		cout << "Study Level: " << studyLevel << endl;
	}
};