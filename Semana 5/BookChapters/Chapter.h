#pragma once
#include <iostream>
#include <string>

using namespace std;

string Chapters[7] = { "Gemini Constellation", "Often Times, It's a Warning", "A Response from Willie Nelson",
"Taxes Over Pizza", "Fake It", "Like Angels", "After Snowfall" };

class Chapter {
private:
	string title;
	int numberOfPages;

public:
	Chapter() {
		title = Chapters[rand() % 7];
		numberOfPages = rand() % 100 + 1;
	}

	~Chapter(){}

	string getTitle() { return title; }
	int getNumberOfPages() { return numberOfPages; }
	void setTitle(string v) { title = v; }
	void setNumberOfPages(int v) { numberOfPages = v; }

	void getChapterInfo() {
		cout << "Title: " << title << endl;
		cout << "Number of pages: " << numberOfPages << endl << endl;
	}
};