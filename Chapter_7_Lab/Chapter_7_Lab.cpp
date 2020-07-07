#include <iostream>
#include <iomanip>
#include <assert.h>
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

bool nottriangle(double s1, double s2, double s3) {
	if (s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1) {
		return true;
	} else {
		return false;
	}
}

bool scalenetriangle(double s1, double s2, double s3) {
	if (s1 != s2 && s2 != s3 && s3 != s1) {
		return true;
	} else {
		return false;
	}
}

bool isoscelestriangle(double s1, double s2, double s3) {
	if (s1 == s2 or s2 == s3 or s3 == s1) {
		return true;
	} else {
		return false;
	}
}
bool equilateraltriangle(double s1, double s2, double s3) {
	if (s1 == s2 && s2 == s3 && s3 == s1) {
		return true;
	} else {
		return false;
	}
}

triangle_types triangle_type(double s1, double s2, double s3) {
	if (nottriangle(s1, s2, s3) == false) {
		return notatriangle;
	} else if (scalenetriangle(s1, s2, s3) == false) {
		return scalene;
	} else if (isoscelestriangle(s1, s2, s3) == false) {
		return isosceles;
	} else if (equilateraltriangle(s1, s2, s3) == false) {
		return equilateral;
	} else {
		std::cout << "There has been an error. Please try again";
		return 0;
	}
}

void output(double s1, double s2, double s3, triangle_types) {
	if (notatriangle) {
		std::cout << "With the measurements" << s1 << ", " << s2 << ", and "
				<< s3
				<< "given, it can be determined that these three sides can't form any shape.";
	}
	if (scalene) {
		std::cout << "With the measurements" << s1 << ", " << s2 << ", and "
				<< s3
				<< "given, it can be determined that these three sides form a scalene triangle.";
	}
	if (isosceles) {
		std::cout << "With the measurements" << s1 << ", " << s2 << ", and "
				<< s3
				<< "given, it can be determined that these three sides form a isosceles triangle.";
	}
	if (equilateral) {
		std::cout << "With the measurements" << s1 << ", " << s2 << ", and "
				<< s3
				<< "given, it can be determined that these three sides form a equilateral triangle.";
	}
}

int main() {
	while (true)
		double s1, s2, s3;
	triangle_types triangletype;
	double s1 = positivevalue("the first side of the triangle");
	double s2 = positivevalue("the second side of the triangle");
	double s3 = positivevalue("the third side of the triangle");
	triangletype = triangle_type(s1, s2, s3);
	output(s1, s2, s3, triangletype);
	return 0;
}
