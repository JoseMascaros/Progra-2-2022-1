#include "ArrMotorcyclist.h"
#include <conio.h>

void menu() {
	cout << "1. Add random motorcyclist" << endl;
	cout << "2. Add manual motorcyclist" << endl;
	cout << "3. Insert in motorcyclist position" << endl;
	cout << "4. List all motorcyclist" << endl;
	cout << "5. List Rappi motorcyclis" << endl;
	cout << "6. List Globo motorcyclist" << endl;
	cout << "7. Update business in position" << endl;
	cout << "8. Delete last motorcyclis" << endl;
	cout << "9. Delete in motorcyclist position" << endl;
}

int main() {
	srand(time(NULL));
	int option;
	ArrMotorcyclist* arr = new ArrMotorcyclist();
	Motorcyclist* m;
	for (int i = 0; i < 3; i++) {
		arr->addMotorcyclist(new Motorcyclist());
	}
	int position;
	string firstName;
	string lastName;
	int plate;
	int kilometer;
	string business;

	while (1) {
		menu();
		cout << "Enter the option: "; cin >> option;

		switch (option)
		{
		case 1:
			m = new Motorcyclist();
			arr->addMotorcyclist(m); cout << "Random motorcyclist added"; break;
			break;
		case 2:
			cout << "Enter the first name: "; cin >> firstName;
			cout << "Enter the last name: "; cin >> lastName;
			cout << "Enter the plate: "; cin >> plate;
			cout << "Enter the kilometer: "; cin >> kilometer;
			cout << "Enter the business: "; cin >> business;
			m = new Motorcyclist(firstName, lastName, plate, kilometer, business);
			arr->addMotorcyclist(m); cout << "Manual motorcyclist added"; break;
		case 3:
			cout << "Enter the position: "; cin >> position;
			arr->insertInPosition(position, new Motorcyclist());
			cout << "Random motorcyclist added"; break;
		case 4:
			arr->getAllMotorcyclist(); break;
		case 5:
			arr->getRappiMotorcyclist(); break;
		case 6:
			arr->getGloboMotorcyclist(); break;
		case 7:
			cout << "Enter the position: "; cin >> position;
			cout << "Enter the new business value: "; cin >> business;
			arr->editBusiness(position, business);
			cout << "Business edited"; break;
		case 8:
			arr->deleteLastMotorcyclist();
			cout << "Last motorcyclist deleted"; break;
		case 9:
			cout << "Enter the position: "; cin >> position;
			arr->deleteInPosition(position);
			cout << "Motorcyclist deleted";
		}

		_getch();
		system("cls");
	}

	_getch();
	return 0;
}