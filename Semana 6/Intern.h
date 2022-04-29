#pragma once
#include "Employee.h"
#include "CollegeStudent.h"

class Intern : public Employee, public CollegeStudent {
protected:
	string projectName;
	int totalHours;
	int workedHours;

public:
	Intern(){}
	Intern(string name, int age, int salary, string seniority, int id, string studyLevel, string collegeName, string degree, string projectName) : 
		CollegeStudent(name, age, id, studyLevel, collegeName, degree),
		Employee(name, age, salary, seniority)
		{
		this->projectName = projectName;
		totalHours = rand() % 500 + 100;
		workedHours = totalHours / 2 + rand() % 200;
	}
	~Intern(){}

	void getInternInfo() {
		getCollegeStudentInfo();
		//getEmployeeInfo();
		cout << "Salary: " << salary << endl;
		cout << "Seniority: " << seniority << endl;
		cout << "Project Name: " << projectName << endl;
		cout << "Total hours: " << totalHours << endl;
		cout << "Worked hours: " << workedHours << endl;
	}
};