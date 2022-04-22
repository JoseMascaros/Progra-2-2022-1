#include <conio.h>
#include "Controller.h"

int main() {
	srand(time(NULL));
	Console::SetWindowSize(85, 35);
	char key;

	Controller* controller = new Controller();

	while (1) {
		Console::CursorVisible = false;
		Console::SetCursorPosition(1, 1); cout << "Cont: " << controller->getCont();

		//Erase
		controller->eraseEverything();

		//Collision
		controller->collision();
		
		//Move
		controller->moveEverything();
		if (_kbhit()) {
			key = _getch();
			key = toupper(key);
			controller->getSquare()->move(key);
		}
		//Draw
		controller->drawEverrything();

		_sleep(100);
	}
}