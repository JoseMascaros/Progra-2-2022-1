#pragma once
#include "Person.h"

class Student : public Person {
protected:
	int id;
	string studyLevel;

public:
	Student(){}
	Student(string name, int age, int id, string studyLevel) : Person(name, age) {
		this->id = id;
		this->studyLevel = studyLevel;
	}

	void getStudentInfo() {
		getPersonInfo();
		cout << "DNI: " << id << endl;
		cout << "Study level: " << studyLevel << endl;
	}
};