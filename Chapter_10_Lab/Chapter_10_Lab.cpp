// Name: Chapter_10_Lab (Using Employee Information from a Class in an Array)
// Author: Meg Hsu
// Due Date: 3 August 2020
// Description: This is a program that takes employee information and displays said data.

#include <iostream>
#include <string>
#include <iomanip>
#include "Employee.h"
using namespace std;

//Function Name: displayEmployee
//Purpose: The purpose of this function is to display the employees' information.
//Parameter: The array with the employees' data.
//Return: N/A
void displayEmployee(Employee employeedata[]) {
	cout << left << setw(15) << "Name" << setw(10) << "ID" << setw(15)
			<< "Department" << setw(10) << "Position\n\n";

	for (int i = 0; i < 3; i++) {
		cout << setw(15) << left << employeedata[i].getName() << setw(10)
				<< std::left << employeedata[i].getId() << setw(15) << left
				<< employeedata[i].getDepartment() << setw(10) << left
				<< employeedata[i].getPosition() << "\n";
	}
}

//Function Name: main
//Purpose: The purpose of this function is to start the program.
//Parameter: n/a
//Return: Returns zero or nonzero value which indicates if the program runs smoothly or if there are any problems.
int main() {
	const int numberemployees = 3;
	Employee employeedata[numberemployees] = { Employee("John Doe", 12345,
			"Engineering", "Software Engineer"), Employee("Jack Smith", 12346,
			"IT", "System Administrator"), Employee("Robert Junior", 12347,
			"Manufacturing", "Vice President"), };

	displayEmployee(employeedata);
	return 0;
}
