#include "ArrMotorcyclist.h"
#include <conio.h>

void menu() {
	cout << "1. Add a random motorcyclist" << endl;
	cout << "2. Add a manual motorcyclist" << endl;
	cout << "3. Delete last motorcyclist" << endl;
	cout << "4. List Rappi motorcyclist" << endl;
	cout << "5. List Globo motorcyclist" << endl;
	cout << "6. List all motorcyclist" << endl;
	cout << "7. Exit" << endl;
	cout << "8. Insert random motorcyclist in a position" << endl;
	cout << "9. Delete in position" << endl;
	cout << "10. Edit in position" << endl;
}

int main() {
	srand(time(NULL));
	ArrMotorcyclist* arr = new ArrMotorcyclist();
	for (int i = 0; i < 3; i++) {
		arr->addMotorcyclist();
	}
	int option;
	string firstName;
	string lastName;
	int plate;
	int kilometer;
	string business;
	Motorcyclist* m;
	int position;

	while (1){
		menu();
		cout << "Enter a number: "; cin >> option;

		switch (option)
		{
		case 1:
			arr->addMotorcyclist(); cout << "Random motorcyclist added"; break;
		case 2:
			cout << "Enter the first name: "; cin >> firstName;
			cout << "Enter the last name: "; cin >> lastName;
			cout << "Enter the plate: "; cin >> plate;
			cout << "Enter the km: "; cin >> kilometer;
			cout << "Enter the business: "; cin >> business;
			m = new Motorcyclist(firstName, lastName, plate, kilometer, business);
			arr->addMotorcyclist(m);
			cout << "Manual motocyclist added"; break;
		case 3:
			arr->deleteLastMotorcyclist();
			cout << "Last motocyclist deleted"; break;
		case 4:
			arr->getRappiMotocyclist(); break;
		case 5:
			arr->getGloboMotocyclist(); break;
		case 6:
			arr->getAllMotorcyclist(); break;
		case 7:
			exit(0); break;
		case 8:
			cout << "Enter the position: "; cin >> position;
			arr->insertMotorcyclist(position); cout << "Motorcyclist inserted";
			break;
		case 9:
			cout << "Enter the position: "; cin >> position;
			arr->deleteInPosition(position); cout << "Motorcyclist deleted";
			break;
		case 10:
			cout << "Enter the position: "; cin >> position;
			cout << "Enter the new business value: "; cin >> business;
			arr->editBusiness(position, business); cout << "Motorcyclist edited";
			break;

		}

		_getch();
		system("cls");
	}


	_getch();
	return 0;
}