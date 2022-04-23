#include "Controller.h"
#include <conio.h>

int main() {
	srand(time(NULL));
	Console::SetWindowSize(80, 40);
	char key;
	Controller* controller = new Controller();

	while (1) {
		Console::CursorVisible = false;

		if (controller->getHp() == 0)break;
		
		controller->eraseEverything();

		controller->collision();

		if (_kbhit()) {
			key = _getch();
			key = toupper(key);
			controller->getSquare()->move(key);
			if (key == 'B')controller->addBall();
		}
		controller->moveEverything();
		
		controller->drawEverything();
		_sleep(100);
	}

	system("cls");
	cout << "Estuvo bueno pero ya volvio el internet";

	_getch();
	return 0;
}