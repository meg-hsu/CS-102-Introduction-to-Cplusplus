/*
 * Employee.h
 *
 *  Created on: Jul 30, 2020
 *      Author: meghsu
 */

#include <iostream>
#include <string>
using namespace std;

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

class Employee

{
private:
	string name;
	int id;
	string department;
	string position;

public:

	//Constructors
	Employee(string, int, string, string);
	Employee(string, int);
	Employee();

	//Accessors
	string getName();
	int getId();
	string getDepartment();
	string getPosition();

	//Mutators
	void setName(string n);
	void setId(int i);
	void setDepartment(string d);
	void setPosition(string p);

};

#endif /* EMPLOYEE_H_ */
