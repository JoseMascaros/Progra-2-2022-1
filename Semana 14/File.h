#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace System;
using namespace std;

class File {
private:
	ofstream fileWrite;
	ifstream fileRead;
	string text;

	int gameTime;
	int meteoritesSpawn;
	string* name;

public:

	File(){
		readData();
	}

	~File(){}

	void readData() {
		fileRead.open("configuration.txt", ios::in);

		getline(fileRead, text);
		meteoritesSpawn = stoi(text);
		getline(fileRead, text);
		gameTime = stoi(text);
		getline(fileRead, text);
		

		fileRead.close();
	}

	int getGameTime() { return gameTime; }
	int getMeteoritesSpawn() { return meteoritesSpawn; }

};