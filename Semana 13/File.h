#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace System;
using namespace std;

class File {
private:
	ofstream fileWrite; //Write
	ifstream fileRead; //Read
	string text;

	int eAX, eAY;
	int eBX, eBY;
	int eCX, eCY;
	int time;

public:
	File() {
		readData();
	}
	~File(){}

	void readData() {
		fileRead.open("configuration.txt", ios::in);

		getline(fileRead, text);
		eAX = stoi(text);
		getline(fileRead, text);
		eAY = stoi(text);

		getline(fileRead, text);
		eBX = stoi(text);
		getline(fileRead, text);
		eBY = stoi(text);

		getline(fileRead, text);
		eCX = stoi(text);
		getline(fileRead, text);
		eCY = stoi(text);

		getline(fileRead, text);
		time = stoi(text);

		fileRead.close();
	}

	int getEAX() { return eAX; }
	int getEAY() { return eAY; }
	int getEBX() { return eBX; }
	int getEBY() { return eBY; }
	int getECX() { return eCX; }
	int getECY() { return eCY; }
	int getTime() { return time; }
};