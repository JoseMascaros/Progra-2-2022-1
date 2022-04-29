#include "Intern.h"
#include <conio.h>

int main() {
	srand(time(NULL));
	Intern* n = new Intern("Rolando", 19, 2500, "SemiSenior", 897312, "College Incomplete", "UPC", "Systems Engineering", "THOR");

	n->getInternInfo();

	_getch();
	return 0;
}