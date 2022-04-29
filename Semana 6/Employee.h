#pragma once
#include "Person.h"

class Employee : public Person {
protected:
	int salary;
	string seniority; 

public:
	Employee(){}
	Employee(string name, int age, int salary, string seniority) : Person(name, age) {
		this->salary = salary;
		this->seniority = seniority;
	}
	~Employee(){}

	void getEmployeeInfo() {
		getPersonInfo();
		cout << "Salary: " << salary << endl;
		cout << "Seniority: " << seniority << endl;
	}

};