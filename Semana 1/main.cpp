#include <conio.h>
#include <iostream>

using namespace std;

void generateData(int *myArray, int n) {
	for (int i = 0; i < n; i++) {
		myArray[i] = rand() % 101; // 0 - 100
	}
}

void printArray(int *myArray, int n) {
	for (int i = 0; i < n; i++) {
		cout << myArray[i] << " ";
	}
}

void findMajorNumber(int *myArray, int n) {
	int major = 0;
	int position;

	for (int i = 0; i < n; i++) {
		if (major < myArray[i]) {
			major = myArray[i];
			position = i;
		}
	}

	cout << "The major number in the array is: " << major << " and it's position: " << position << endl;
}

void findMinorNumber(int* myArray, int n) {
	int minor = 100;
	int position;

	for (int i = 0; i < n; i++) {
		if (minor > myArray[i]) {
			minor = myArray[i];
			position = i;
		}
	}

	cout << "The minor number in the array is: " << minor << " and it's position: " << position << endl;
}

void bubbleSort(int* myArray, int n) {
	int aux;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (myArray[j] < myArray[j + 1]) {
				aux = myArray[j];
				myArray[j] = myArray[j + 1];
				myArray[j + 1] = aux;
			}
		}
	}
}

void showAverageNumber(int* myArray, int n) {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += myArray[i];
	}

	cout << "The average number is: " << double(sum) / n << endl;
}

void percentageMajorMinorFifty(int* myArray, int n) {
	int majorCounter = 0;
	int minorCounter = 0;

	double majorPercentage, minorPercentage;

	for (int i = 0; i < n; i++) {
		if (myArray[i] <= 50) {
			minorCounter++;
		}
		else {
			majorCounter++;
		}
	}

	majorPercentage = double(majorCounter) / n * 100.0;
	minorPercentage = double(minorCounter) / n * 100.0;

	cout << "The percentage of numbers major fifty is: " << majorPercentage << "%" << endl;
	cout << "The percentage of numbers minor fifty is: " << minorPercentage << "%" << endl;
}

void menu() {
	cout << "1. Print values" << endl;
	cout << "2. Find major number and position" << endl;
	cout << "3. Find minor number and position" << endl;
	cout << "4. Execute bublle sort" << endl;
	cout << "5. Show average number" << endl;
	cout << "6. Show percentage (fifty)" << endl;
	cout << "7. Exit" << endl;
}


int main() {
	srand(time(NULL));
	int option;
	int n = 4;
	int* myArray = new int[n];

	generateData(myArray, n);

	while (1) {
		menu();
		cout << "Enter the option: "; cin >> option;

		switch (option)
		{
		case 1: printArray(myArray, n); break;
		case 2: findMajorNumber(myArray, n); break;
		case 3: findMinorNumber(myArray, n); break;
		case 4: bubbleSort(myArray, n); break;
		case 5: showAverageNumber(myArray, n); break;
		case 6: percentageMajorMinorFifty(myArray, n); break;
		case 7: exit(0);
		}

		_getch();
		system("cls");
	}

	_getch();
	return 0;
}