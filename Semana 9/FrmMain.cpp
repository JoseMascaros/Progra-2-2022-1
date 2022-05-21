#include "FrmMain.h"

using namespace FiguresExample;

int main() {
	FrmMain^ frm = gcnew FrmMain();
	Application::Run(frm);
	return 0;
}

//Managed -> Administradas
// ref class Rectangle
// Int16/ Int32/ Int64
// Char
// Rectangle ^r = gcnew Rectangle()

//Standart -> std
// class Person
// short age
// int age
// long age
// char 
// Person *p = new Person()