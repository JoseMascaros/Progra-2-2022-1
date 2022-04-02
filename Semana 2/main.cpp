#include "Person.h"
#include <conio.h>

int main() {
	//Variables
	Person* p1;
	Person* p2;
	Person* p3;
	string name;
	int age;
	char gender;
	double weight;
	double height;

	//Incoming Data
	cout << "Enter the name: "; cin >> name;
	cout << "Enter the age: "; cin >> age;
	cout << "Enter the gender "; cin >> gender;
	cout << "Enter the weight: "; cin >> weight;
	cout << "Enter the height: "; cin >> height;

	//Person 1
	p1 = new Person(name, age, gender, weight, height);
	p1->getInformation();
	switch (p1->calculateIMC())
	{
	case -1: cout << "The person is below his/her ideal weight" << endl; break;
	case 0: cout << "The person is on his/her ideal weight" << endl; break;
	case 1: cout << "The person is above his/her ideal weight" << endl; break;
	}
	cout << "Is the person an adult: " << p1->isAdult() << endl << endl;

	//Person 2
	p2 = new Person(name, age, gender);
	p2->setWeight(70.5);
	p2->setHeight(1.81);
	p2->getInformation();
	switch (p2->calculateIMC())
	{
	case -1: cout << "The person is below his/her ideal weight" << endl; break;
	case 0: cout << "The person is on his/her ideal weight" << endl; break;
	case 1: cout << "The person is above his/her ideal weight" << endl; break;
	}
	cout << "Is the person an adult: " << p2->isAdult() << endl << endl;

	//Person 3
	p3 = new Person();
	p3->setName("Katherine");
	p3->setAge(20);
	p3->setGender('F');
	p3->setWeight(55.7);
	p3->setHeight(1.60);
	p3->getInformation();
	switch (p3->calculateIMC())
	{
	case -1: cout << "The person is below his/her ideal weight" << endl; break;
	case 0: cout << "The person is on his/her ideal weight" << endl; break;
	case 1: cout << "The person is above his/her ideal weight" << endl; break;
	}
	cout << "Is the person an adult: " << p3->isAdult() << endl << endl;

	delete p1;
	delete p2;
	delete p3;

	_getch();
	return 0;
}