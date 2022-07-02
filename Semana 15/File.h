#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace System;
using namespace std;

class File {
private:
	ofstream fileWrite;
	ifstream fileRead;
	string text;

	int x, y, hp, gtime;

public:
	File() {
		readData();
	}

	~File() {}

	void readData() {
		fileRead.open("configuration.txt", ios::in);

		if (fileRead.fail()) {
			fileRead.close();

			fileWrite.open("configuration.txt", ios::out); //create a new file
			fileWrite << "200" << endl;
			fileWrite << "100" << endl;
			fileWrite << "7" << endl;
			fileWrite << "60" << endl;
			fileWrite.close();

			fileRead.open("configuration.txt", ios::in);
		}

		getline(fileRead, text);
		x = stoi(text);
		getline(fileRead, text);
		y = stoi(text);
		getline(fileRead, text);
		hp = stoi(text);
		getline(fileRead, text);
		gtime = stoi(text);

		fileRead.close();
	}

	int getX() { return x; }
	int getY() { return y; }
	int getHp() { return hp; }
	int getGTime() { return gtime; }

};