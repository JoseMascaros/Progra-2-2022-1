#include <iostream>
#include <conio.h>
#include "Person.h"

using namespace std;

int main() {
	srand(time(NULL));
	Person* p1;
	Person* p2;
	Person* p3;

	string name;
	int age;
	char gender;
	double weight;
	double height;

	cout << "Enter the name of the person: "; cin >> name;
	cout << "Enter the age of the person: "; cin >> age;
	cout << "Enter the gender of the person: "; cin >> gender;
	cout << "Enter the weight of the person: "; cin >> weight;
	cout << "Enter the height of the person: "; cin >> height;\
	cout << endl << endl;


	//Person 1
	p1 = new Person(name, age, gender, height, weight);
	p1->validateGender();
	p1->getInformation();
	switch (p1->calculateIMC())
	{
	case -1: cout << "Is below his/her ideal weight"; break;
	case 0: cout << "Is on his/her ideal weight"; break;
	case 1: cout << "Is above his/her ideal weight"; break;
	}
	cout << endl;
	cout << "Is an adult: " << p1->isAdult() << endl;
	cout << endl << endl;

	//Person 2
	p2 = new Person(name, age, gender);
	p2->setWeight(98.7);
	p2->setHeight(1.65);
	p2->validateGender();
	p2->getInformation();
	switch (p2->calculateIMC())
	{
	case -1: cout << "Is below his/her ideal weight"; break;
	case 0: cout << "Is on his/her ideal weight"; break;
	case 1: cout << "Is above his/her ideal weight"; break;
	}
	cout << endl;
	cout << "Is an adult: " << p2->isAdult() << endl;
	cout << endl << endl;


	//Person 3
	p3 = new Person();
	p3->setName("Mario");
	p3->setAge(19);
	p3->setGender('M');
	p3->setHeight(1.72);
	p3->setWeight(65.9);
	p3->validateGender();
	p3->getInformation();
	switch (p3->calculateIMC())
	{
	case -1: cout << "Is below his/her ideal weight"; break;
	case 0: cout << "Is on his/her ideal weight"; break;
	case 1: cout << "Is above his/her ideal weight"; break;
	}
	cout << endl;
	cout << "Is an adult: " << p3->isAdult() << endl;
	cout << endl << endl;




	_getch();
	return 0;
}