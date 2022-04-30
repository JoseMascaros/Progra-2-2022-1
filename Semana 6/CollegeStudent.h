#pragma once
#include "Student.h"

class CollegeStudent : public Student {
protected:
	string collegeName;
	string degree;
	int courses;

public:
	CollegeStudent(){}
	CollegeStudent(string name, int age, string studyLevel, string collegeName, string degree) : 
		Student(name, age, studyLevel) {
		courses = rand() % 10 + 1;
		this->collegeName = collegeName;
		this->degree = degree;
	}
	~CollegeStudent(){}

	void getCollegeStudentInfo() {
		getStudentInfo();
		cout << "College Name: " << collegeName << endl;
		cout << "Degree: " << degree << endl;
		cout << "Courses: " << courses << endl;
	}
};