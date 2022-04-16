#include "ArrSquare.h"
#include <conio.h>

int main() {
	Console::CursorVisible = false;
	srand(time(NULL));
	ArrSquare* arr = new ArrSquare();
	char key;

	while (1) {
		if (_kbhit()) {
			key = _getch();
			key = toupper(key);

			switch (key){
			case 'C': arr->changeColors(); break;
			case 'A': arr->addSquare(new Square()); break;
			case 'E': arr->deleteInPosition(0); break;
			}
		}

		//system("cls");
		arr->eraseEverything();
		arr->moveEverything();
		arr->drawEverything();
		_sleep(50);
	}

	_getch();
	return 0;
}