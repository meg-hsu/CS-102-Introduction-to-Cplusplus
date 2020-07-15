// Name: Chapter_7_Lab (Identifying Types of Triangles)
// Author: Meg Hsu
// Due Date: 13 July 2020
// Description: This is a program that allows you to convert time in twelve and twenty four hour notation into other notations of time.

#include <iostream>
#include <iomanip>
using namespace std;

enum triangle_types {
	notriangle, scalene, isosceles, equilateral
};

//Function Name: positivevalue
//Purpose: The purpose of this function is ensure that all values entered into the program are positive values.
//Parameter: The name of the sides that are used in the program.
//Return: Positive numbers

double positivevalue(string name) {
	while (true) {
		cout << "Please enter a measurement for " << name << ": ";
		double value;
		cin >> value;
		if (value <= 0) {
			cout << value << " is not a valid measurement for " << name
					<< ".";
			cout << " Please enter a positive number.\n";
		} else {
			return value;
		}
	}
}

//Function Name: isitatriangle
//Purpose: The purpose of this function is use the sides given to determine if they can make a triangle.
//Parameter: Measurements of the sides that can make up a triangle.
//Return: True/False. This function returns true if the sides given can make a triangle. If not, the function returns false.

bool isitatriangle(double s1, double s2, double s3) {
	if (s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1) {
		return true;
	} else {
		return false;
	}
}

//Function Name: triangleidentify
//Purpose: The purpose of this function is to identify what kind of triangle the given measurements make.
//Parameter: Measurements of the sides of the triangle.
//Return: enums: notriangle, scalene, isosceles, and equilateral. These correspond with the names of types of triangles as well as an option for measurements that can't make a triangle as well.

triangle_types triangleidentify(double s1, double s2, double s3) {
	if (!isitatriangle(s1, s2, s3)) {
		return notriangle;
	} else if (s1 != s2 && s2 != s3 && s3 != s1) {
		return scalene;
	} else if ((s1 == s2 && s2 != s3) or (s1 == s3 && s3 != s2)
			or (s2 == s3 && s3 != s1)) {
		return isosceles;
	} else if (s1 == s2 && s2 == s3 && s3 == s1) {
		return equilateral;
	} else {
// The user shouldn't be able to get to this point but if they do, an error message will be displayed.
		cout << "Program error, please try again.";
		return notriangle;
	}
}

//Function Name: output
//Purpose: The purpose of this function is to output the type of triangle identified.
//Parameter: enum: notriangle, scalene, isosceles, and equilateral
//Return: n/a

void output(triangle_types returned) {
	switch (returned) {
	case notriangle:
		cout
				<< "With the measurements given, it can be determined that these three measurements can't form a triangle.";
		break;
	case scalene:
		cout
				<< "With the measurements given, it can be determined that these three sides form a scalene triangle.";
		break;
	case isosceles:
		cout
				<< "With the measurements given, it can be determined that these three sides form a isosceles triangle.";
		break;
	case equilateral:
		cout
				<< "With the measurements given, it can be determined that these three sides form a equilateral triangle.";
		break;
	default:
		cerr << "Error: unknown triangle type." << returned << endl;
	}
}

//Function Name: input
//Purpose: The purpose of this function is to input the measurements of the sides of the triangles and ensure that they are valid before using them in other functions.
//Parameter: n/a
//Return: n/a

void input() {
	double s1, s2, s3;
	triangle_types returned;
	cout
			<< "This program is used to identify types of triangles given the measurements of any three sides.\n";
	s1 = positivevalue("the first side");
	s2 = positivevalue("the second side");
	s3 = positivevalue("the last side");
	returned = triangleidentify(s1, s2, s3);
	output(returned);
}

//Function Name: main
//Purpose: The purpose of this function is to start the program.
//Parameter: n/a
//Return: Returns zero or nonzero value which indicates if the program runs smoothly or if there are any problems.

int main() {
	while (true) {
		double s1, s2, s3;
		triangle_types returned;
		input();

// The following code is used to prompt the user if they would like to run the program again.
		cout << "\n\nWould you like to run this program again? (y/n) ";
		string yesorno;
		cin >> yesorno;
		if (yesorno == "Y" or yesorno == "y") {
			cout << "\n";
		}
		if (yesorno == "N" or yesorno == "n") {
			break;
		}
	}
	return 0;
}
