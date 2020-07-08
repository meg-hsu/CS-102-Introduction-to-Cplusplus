#include <iostream>
#include <iomanip>
//using namespace std;

enum triangle_types {
	notatriangle, scalene, isosceles, equilateral
};

double positivevalue(std::string name) {
	while (true) {
		std::cout << "Please enter a measurement for " << name << ": ";
		double value;
		std::cin >> value;
		if (value <= 0) {
			std::cout << value << " is not a valid measurement for " << name
					<< ".";
			std::cout << " Please enter a positive number.\n";
		} else {
			return value;
		}
	}
}

bool isitatriangle(double s1, double s2, double s3) {
	if (s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1) {
		return true;
	} else {
		return false;
	}
}

triangle_types triangledef(double s1, double s2, double s3) {
	if (!isitatriangle(s1, s2, s3)) {
		return notatriangle;
	} else if (s1 != s2 && s2 != s3 && s3 != s1) {
		return scalene;
	} else if ((s1 == s2 && s2 != s3) or (s1 == s3 && s3 != s2)
			or (s2 == s3 && s3 != s1)) {
		return isosceles;
	} else if (s1 == s2 && s2 == s3 && s3 == s1) {
		return equilateral;
	} else {
		std::cout << "Error";
		return notatriangle;
	}
}

void output(triangle_types output);

void triangle_type() {
	double s1, s2, s3;
	triangle_types returned;
	std::cout
			<< "This program is used to identify types of triangles given the measurements of any three sides.\n";
	s1 = positivevalue("the first side");
	s2 = positivevalue("the second side");
	s3 = positivevalue("the last side");
	returned = triangledef(s1, s2, s3);
	output(returned);
}

void output(triangle_types returned) {
	switch (returned) {
	case notatriangle:
		std::cout
				<< "With the measurements given, it can be determined that these three sides can't form any shape.";
		break;
	case scalene:
		std::cout
				<< "With the measurements given, it can be determined that these three sides form a scalene triangle.";
		break;
	case isosceles:
		std::cout
				<< "With the measurements given, it can be determined that these three sides form a isosceles triangle.";
		break;
	case equilateral:
		std::cout
				<< "With the measurements given, it can be determined that these three sides form a equilateral triangle.";
		break;
	default:
		std::cerr << "Error: unknown triangle type " << returned << std::endl;
	}
}

int main() {
	while (true) {
		double s1, s2, s3;
		triangle_types returned;
		triangle_type();

		std::cout << "\n\nWould you like to run this program again? (y/n) ";
		std::string yesorno;
		std::cin >> yesorno;
		if (yesorno == "Y" or yesorno == "y") {
			std::cout << "\n";
		}
		if (yesorno == "N" or yesorno == "n") {
			break;
		}
	}
	return 0;
}
