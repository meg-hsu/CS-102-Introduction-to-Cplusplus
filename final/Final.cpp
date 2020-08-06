// Name: Chapter_8_Lab (Array Calculations)
// Author: Meg Hsu
// Due Date: 20 July 2020
// Description: This is a program that allows you to do various calculations on the given array.

#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 12;
const int COLS = 2;
int data[ROWS][COLS];

//Function Name: validinput
//Purpose: The purpose of this function is ensure that all values entered into the program are valid inputs.
//Parameter: The names of the input, the function of the input, the maximum and minimum values for the inputs.
//Return: Valid inputs.

int ValidNumericalInput(string name, int lower, int upper) {
	while (true) {
		cout << "\nPlease enter " << name << ": ";
		double value;
		cin >> value;
		if (value < lower or value > upper) {
			cout << value << " is not a valid input for " << name << ".";
			cout << " \nPlease enter a number between " << lower << " and "
					<< upper << ".\n";
		} else {
			return value;
		}
	}
}

//Function Name: getTemperature
//Purpose: The purpose of this function is ensure that all temperatures entered into the program are valid temperatures.
//Parameter: The maximum and minimum values for the inputs.
//Return: Valid inputs.

double getTemperature(int lower, int upper) {
double value;
	while (true) {
	cin >> value;
	if (value < lower || value > upper){
		cout << " \nPlease enter a valid input between " << lower << " and " << upper << ".\n";
		} else {
			return value;
		}
	}
}


//Function Name: getData
//Purpose: The purpose of this function is to take input data into the array through a user manually typing the information in.
//Parameter: The array that the information will be entered in to and the number of rows and columns in the array.
//Return: N/A.

void getData(int data[][2], int rows, int columns) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			data[i][j] = getTemperature(-100, 150);
		}
	}

}

//Function Name: averageHigh
//Purpose: The purpose of this function is calculate the average of all the highest temperatures int the array.
//Parameter: The array information, the number of months.
//Return: The average of the highest temperatures in the array.

double averageHigh(int data[][COLS], int months) {
	double sum = 0;
	for (int i = 0; i < ROWS; ++i) {
		sum += data[i][1];
	}
	return (sum / months);
}

//Function Name: averageLow
//Purpose: The purpose of this function is calculate the average of all the lowest temperatures int the array.
//Parameter: The array information, the number of months.
//Return: The average of the lowest temperatures in the array.

double averageLow(int data[][COLS], int months) {
	double sum = 0;
	for (int i = 0; i < ROWS; ++i) {
		sum += data[i][0];
	}
	return (sum / months);
}

//Function Name: indexHighTemp
//Purpose: The purpose of this function is output the highest temperatures entered into the array.
//Parameter: The array information.
//Return: The highest temperatures entered into the array.

void indexHighTemp(int data[][2]) {
	int row, col;
	cout << "The highest temperatures for the year are:\n\n";
	for (row = 0; row < 12; row++) {
		cout << "Month " << (row + 1) << ": " << data[row][1] << '\n';
	}
}

//Function Name: indexLowTemp
//Purpose: The purpose of this function is output the lowest temperatures entered into the array.
//Parameter: The array information.
//Return: The lowest temperatures entered into the array.

void indexLowTemp(int data[][2]) {
	int row, col;
	cout << "The highest temperatures for the year are:\n\n";
	for (row = 0; row < 12; row++) {
		cout << "Month " << (row + 1) << ": " << data[row][0] << '\n';
	}
}

//Function Name: intro
//Purpose: The purpose of this function is to display the array and the menu.
//Parameter: n/a
//Return: n/a

void intro() {
	cout
			<< "The following computations can be executed:\n"
					"1. Finding the average of all of the highest temperatures in the year\n"
					"2. Finding the average of all of the lowest temperatures in the year\n"
					"3. Printing all of the highest temperatures\n"
					"4. Printing all of the lowest temperatures\n";
}

//Function Name: whetherrunagain
//Purpose: The purpose of this function is to ask the user if they would like to use the program again.
//Parameter: n/a
//Return: True (if the user wants to run the program again) or false (if they do not want to run the program again).

bool whetherrunagain() {
	cout << "\nWould you like to run this program again? (y/n) ";
	bool ans;
	string yesorno;
	cin >> yesorno;
	if (yesorno == "Y" or yesorno == "y") {
		ans = true;
	}
	if (yesorno == "N" or yesorno == "n") {
		ans = false;
	}
	return ans;
}

//Function Name: main
//Purpose: The purpose of this function is to start the program.
//Parameter: n/a
//Return: Returns zero or nonzero value which indicates if the program runs smoothly or if there are any problems.

int main() {
	int testArray[ROWS][COLS];
//	int testArray[ROWS][COLS] = { { -10, 38 }, { 5, 40 }, { 2, 45 }, { 25, 52 },
//			{ 30, 65 }, { 40, 80 }, { 45, 75 }, { 60, 90 }, { 50, 85 },
//			{ 46, 82 }, { 15, 70 }, { 5, 44 } };
	cout << "This function is used to do various calculations given a year of data containing lowest and highest temperatures of an area.\n";
	do {
		intro();
		int option;
		option = ValidNumericalInput(
				"which option you would like to use in this program", 1, 4);
		if (option == 1) {
			getData(testArray, 12, 2);
			cout << "The average of all of the highest temperatures is "
					<< fixed << setprecision(2) << averageHigh(testArray, 12) << " degrees.\n";
		} else if (option== 2) {
			getData(testArray, 12, 2);
			cout << "The average of all of the lowest temperatures is "
					<< fixed << setprecision(2) << averageLow(testArray, 12) << " degrees.\n";
		} else if (option == 3) {
			getData(testArray, 12, 2);
			indexHighTemp(testArray);
		} else if (option == 4) {
			getData(testArray, 12, 2);
			indexLowTemp(testArray);
		} else {
			//Users of the program shouldn't be able to access this section
			cout << "Program error. Please try again.";
		}

	} while (whetherrunagain() == true);
	return 0;
}
