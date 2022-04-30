#include "Intern.h"
#include <conio.h>

int main() {
	Intern* n = new Intern("Josue", 20, 2300, "Semi Senior", "College Incomplete", "UPC",
		"Systems Engineering", "THOR");

	n->getCollegeStudentInfo();

	_getch();
	return 0;
}