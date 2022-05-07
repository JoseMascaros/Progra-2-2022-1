#include "Controller.h"
#include <conio.h>

int main() {
	srand(time(NULL));
	Console::SetWindowSize(80, 40);
	char key;
	Controller* controller = new Controller();

	while (1) {
		Console::CursorVisible = false;
		if (controller->timeOut())break;

		controller->eraseEverything();

		controller->collision();

		if (_kbhit()) {
			key = _getch();
			key = toupper(key);
			controller->getPerson()->move(key);
		}
		controller->moveEverything();

		controller->drawEverything();

		controller->spawn();
		_sleep(100);
	}

	system("cls");
	cout << "GAME OVER" << endl;
	cout << "The total points reached: " << controller->getCont();

	_getch();
	return 0;
}