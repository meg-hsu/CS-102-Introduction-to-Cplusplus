// Name: Chapter_8_Lab (Array Calculations)
// Author: Meg Hsu
// Due Date: 20 July 2020
// Description: This is a program that allows you to do various calculations on the given array.

#include <iostream>
using namespace std;

const int ROWS = 4;
const int COLS = 5;
int data[ROWS][COLS];

//Function Name: validinput
//Purpose: The purpose of this function is ensure that all values entered into the program are valid inputs.
//Parameter: The names of the input, the function of the input, the maximum and minimum values for the inputs.
//Return: Valid inputs.

double ValidNumericalInput(string name, string function, int lower, int upper) {
	while (true) {
		cout << "\nPlease enter which " << name << " should be selected "
				<< function << ": ";
		double value;
		cin >> value;
		if (value < lower or value > upper) {
			cout << value << " is not a valid input for " << name << ".";
			cout << " Please enter a number between " << lower << " and "
					<< upper << ".\n";
		} else {
			return value;
		}
	}
}

//Function Name: getTotal
//Purpose: The purpose of this function is calculate the sum of all the numbers in the array.
//Parameter: The array information.
//Return: The sum of the values in the array.

double getTotal(int data[][COLS]) {
	double sum = 0;
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			sum += data[i][j];
		}
	}
	return sum;
}

//Function Name: getAverage
//Purpose: The purpose of this function is calculate the average of all the numbers in the array.
//Parameter: The array information.
//Return: The average of all the values in the array.

double getAverage(int data[][COLS]) {
	double average = 1.0 * getTotal(data) / (COLS * ROWS);
	return average;
}

//Function Name: getRowTotal
//Purpose: The purpose of this function is calculate the sum of all the numbers in a specified row of the array.
//Parameter: The array information.
//Return: The sum of the values in the chosen row of the array.

int getRowTotal(int data[][COLS], int rows) {
	int sum = 0;
	for (int j = 0; j < COLS; ++j) {
		sum += data[rows][j];
	}
	return sum;
}

//Function Name: getColumnTotal
//Purpose: The purpose of this function is calculate the sum of all the numbers in a specified column of the array.
//Parameter: The array information.
//Return: The sum of the values in the chosen column of the array.

int getColumnTotal(int data[][COLS], int cols) {
	int sum = 0;
	for (int i = 0; i < ROWS; ++i) {
		sum += data[i][cols];
	}
	return sum;
}

//Function Name: getHighestInRow
//Purpose: The purpose of this function is output the largest number in a specified row of the array.
//Parameter: The array information.
//Return: The largest value in the chosen row of the array.

int getHighestInRow(int data[][COLS], int rows) {
	int highest = data[rows][0];
	for (int j = 1; j < COLS; ++j) {
		if (highest < data[rows][j]) {
			highest = data[rows][j];
		}
	}
	return highest;
}

//Function Name: getLowestInRow
//Purpose: The purpose of this function is output the smallest number in a specified row of the array.
//Parameter: The array information.
//Return: The smallest value in the chosen row of the array.

int getLowestInRow(int data[][COLS], int rows) {
	int lowest = data[rows][0];
	for (int j = 1; j < COLS; ++j) {
		if (lowest > data[rows][j]) {
			lowest = data[rows][j];
		}
	}
	return lowest;
}

//Function Name: intro
//Purpose: The purpose of this function is to display the array and the menu.
//Parameter: n/a
//Return: n/a

void intro() {
	cout
			<< "This program is used to compute various calculations to the following array: \n"
					"| 1  | 2  | 3  | 4  | 5  |\n"
					"| 6  | 7  | 8  | 9  | 10 |\n"
					"| 11 | 12 | 13 | 14 | 15 |\n"
					"| 16 | 17 | 18 | 19 | 20 |\n";
	cout << "\nThe following computations can be executed:\n"
			"1. Finding the total of all the values in the array\n"
			"2. Finding the average of all the values in the array\n"
			"3. Finding the total of the values in a specified row\n"
			"4. Finding the total of the values in a specified column\n"
			"5. Finding the highest value in a specified row\n"
			"6. Finding the lowest value in a specified row\n";
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

	int testArray[ROWS][COLS] = { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 }, { 11,
			12, 13, 14, 15 }, { 16, 17, 18, 19, 20 } };

	do {
		intro();
		int option;
		option = ValidNumericalInput("option", "in this program", 1, 6);

		if (option == 1) {
			cout << "The total of all the values in the array is "
					<< getTotal(testArray) << ".\n";
		} else if (option == 2) {
			cout << "The average of all the values in the array is "
					<< getAverage(testArray) << ".\n";
		} else if (option == 3) {
			int rows;
			cout
					<< "This option allows for the summation of the values in a specified row. ";
			rows = ValidNumericalInput("rows", "to calculate the sum of", 0, ROWS);
			cout << "The total of the values in the row selected is "
					<< getRowTotal(testArray, rows) << ".\n";
		} else if (option == 4) {
			int cols;
			cols = ValidNumericalInput("columns", "to calculate the sum of", 0, COLS);
			cout << "The total of the values in the column selected is "
					<< getColumnTotal(testArray, cols) << ".\n";
		} else if (option == 5) {
			int hrows;
			hrows = ValidNumericalInput("rows", "to find the highest value of", 0, ROWS);
			cout << "The highest value in the row selected is "
					<< getHighestInRow(testArray, hrows) << ".\n";
		} else if (option == 6) {
			int lrows;
			lrows = ValidNumericalInput("rows", "to find the lowest value of", 0, ROWS);
			cout << "The lowest value in the row selected is "
					<< getLowestInRow(testArray, lrows) << ".\n";
		} else {
			//Users of the program shouldn't be able to access this section
			cout << "Program error. Please try again.";
		}

	} while (whetherrunagain() == true);
	return 0;
}
