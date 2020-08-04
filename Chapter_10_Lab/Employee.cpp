///*
// * Employee.cpp
// *
// *  Created on: Jul 30, 2020
// *      Author: meghsu
// */
//
#include "Employee.h"
#include <iostream>
using namespace std;

struct Employees {
	string name;
	int id;
	string department;
	string position;
};

//Constructors

//Function Name: Employee
//Purpose: Constucts the name, ID, department, and position of an employee.
//Parameter: The name, ID, department, and position of the employee.
//Return: N/A
Employee::Employee(string n, int i, string d, string p) {
	name = n;
	id = i;
	department = d;
	position = p;
}

//Function Name: Employee
//Purpose: Constucts the name and ID of an employee.
//Parameter: The name and id of the employee.
//Return: N/A
Employee::Employee(string n, int i) {
	name = n;
	id = i;
	department = "";
	position = "";
}

//Function Name: Employee
//Purpose: Default Constructor
//Parameter: N/A
//Return: N/A
Employee::Employee() {
	name = "";
	id = 0;
	department = "";
	position = "";
}

//Accessors

//Function Name: getName
//Purpose: Accesses the name of the employee and returns it as a string.
//Parameter: N/A
//Return: The name of the employee.
string Employee::getName() {
	return name;
}

//Function Name: getId
//Purpose: Accesses the ID of the employee and returns it as an integer.
//Parameter: N/A
//Return: The ID of the employee.
int Employee::getId() {
	return id;
}

//Function Name: getDepartment
//Purpose: Accesses the department of the employee and returns it as a string.
//Parameter: N/A
//Return: The department of the employee.
string Employee::getDepartment() {
	return department;
}

//Function Name: getPosition
//Purpose: Accesses the position of the employee and returns it as a string.
//Parameter: N/A
//Return: The department of the employee.
string Employee::getPosition() {
	return position;
}

//Mutators

//Function Name: setName
//Purpose: Edits the name of the employee.
//Parameter: N/A
//Return: N/A
void Employee::setName(string n) {
	name = n;
}

//Function Name: setId
//Purpose: Edits the ID of the employee.
//Parameter: N/A
//Return: N/A
void Employee::setId(int i) {
	id = i;
}

//Function Name: setDepartment
//Purpose: Edits the department of the employee.
//Parameter: N/A
//Return: N/A
void Employee::setDepartment(string d) {
	department = d;
}

//Function Name: setPosition
//Purpose: Edits the position of the employee.
//Parameter: N/A
//Return: N/A
void Employee::setPosition(string p) {
	position = p;
}

