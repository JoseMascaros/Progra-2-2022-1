#pragma once
#include "Student.h"

class CollegeStudent : public Student {
protected:
	string collegeName;
	string degree;
	int courses;

public:
	CollegeStudent(){}
	CollegeStudent(string name, int age, int id, string studyLevel, string collegeName, string degree) : Student(name, age, id, studyLevel) {
		this->collegeName = collegeName;
		this->degree = degree;
		courses = rand() % 10 + 1;
	}

	~CollegeStudent(){}
	
	void getCollegeStudentInfo() {
		getStudentInfo();
		cout << "College name: " << collegeName << endl;
		cout << "Degree: " << degree << endl;
		cout << "Courses: " << courses << endl;
	}

};