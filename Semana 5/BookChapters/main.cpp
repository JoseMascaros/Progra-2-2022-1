#include "Book.h"
#include <conio.h>

int main() {
	srand(time(NULL));
	int nro;
	string name;
	Book* b = new Book("Harry Potter", "JK Rowling", "Navarrete", "984712xas34");
	b->addChapter();
	b->addChapter();
	b->addChapter();
	b->addChapter();
	b->addChapter();

	b->getAllChapters();

	cout << "Enter the chapter nro: "; cin >> nro;
	b->findChapter(nro);
	cout << endl << endl;
	cout << "Enter the name of the chapter: ";
	cin.ignore();
	getline(cin, name);
	b->findChapter(name);

	cout << "Deleted last 2 chapters" << endl;
	b->deleteLastChapter();
	b->deleteLastChapter();
	b->getAllChapters(); cout << endl;

	cout << "Chapter with most Pages: " << endl;
	b->chapterWithMostPages();

	_getch();
	return 0;
}