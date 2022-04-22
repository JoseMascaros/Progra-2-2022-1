#pragma once
#include "Chapter.h"
#include <vector>

class Book {
private:
	string title;
	string author;
	string editorial;
	string isbn;
	vector<Chapter*> chapters;

public:
	Book(string title, string author, string editorial, string isbn) {
		this->title = title;
		this->editorial = editorial;
		this->isbn = isbn;
		this->author = author;
	}

	~Book() {}

	string getTitle() { return title; }
	string getAuthor() { return author; }
	string getEditorial() { return editorial; }
	string getIsbn() { return isbn; }
	void setTitle(string v) { title = v; }
	void setAuthor(string v) { author = v; }
	void setEditorial(string v) { editorial = v; }
	void setIsbn(string v) { isbn = v; }

	void addChapter() {
		Chapter* c = new Chapter();
		chapters.push_back(c);
	}

	void deleteLastChapter() {
		chapters.pop_back();
	}

	void findChapter(string title) {
		for (int i = 0; i < chapters.size(); i++) {
			if (chapters[i]->getTitle() == title) {
				cout << "Is the chapter nro: " << i << endl << endl;
			}
		}
	}

	void findChapter(int nro) {
		cout << "The chapter nro " << nro << " is: " << chapters[nro]->getTitle() << endl;
	}

	void getAllChapters() {
		for (int i = 0; i < chapters.size(); i++) {
			chapters[i]->getChapterInfo();
		}
	}

	void chapterWithMostPages() {
		int max = 0;
		Chapter* c = new Chapter();

		for (int i = 0; i < chapters.size(); i++) {
			if (max < chapters[i]->getNumberOfPages()) {
				max = chapters[i]->getNumberOfPages();
				c = chapters[i];
			}
		}

		cout << "The chapter with most pages is: " << c->getTitle() << " with " << c->getNumberOfPages() << endl;
	}
};