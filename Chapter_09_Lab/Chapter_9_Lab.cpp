// Name: Chapter_8_and_9_Lab (Recording and Sorting Student Information in an Array)
// Author: Meg Hsu
// Due Date: 27 July 2020
// Description: This is a program that allows you to input information into an array and do various computations as well as sort the data entered.

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

struct StudentType {
	string studentFName;
	string studentLName;
	int testscore;
	char lettergrade;
	int studentID;
};

//All functions are declared below:
double ValidNumericalInput(string name, string function, int lower, int upper);
void InputStudentInfoManually(StudentType students[], int length);
void initialize(ifstream &indata, StudentType students[], int length);
void InputStudentInfoFile(StudentType students[], ifstream &inputfile,
		int TOTAL);
char TestScoreToLetterGrade(int score);
int HighestScore(StudentType students[], int length);
void OutputHighestScore(StudentType students[], ostream &output,
		int highestscore, int length);
void OutputLetterGrade(StudentType students[], ostream &output, int length,
		string sort);
void Sort_FName(StudentType students[], int len);
void Sort_LName(StudentType students[], int len);
void Sort_TestScore(StudentType students[], int len);
void Sort_StudentID(StudentType students[], int len);
void Intro();
bool WhetherRunAgain();
int Prompt();

//Function Name: ValidNumericalInput
//Purpose: The purpose of this function is ensure that all numerical values entered into the program are valid inputs.
//Parameter: The names of the input, the function of the input, the maximum and minimum values for the inputs.
//Return: Valid inputs.

double ValidNumericalInput(string name, string function, int lower, int upper) {
	while (true) {
		cout << "\nPlease enter " << name << function << ": ";
		double value;
		cin >> value;
		if (value < lower or value > upper) {
			cout << "\n" << value << " is not a valid input.\n";
			cout << "Please enter a number between " << lower << " and "
					<< upper << ".\n";
		} else {
			return value;
		}
	}
}

//Function Name: ValidFileInput
//Purpose: The purpose of this function is ensure that the file with student information used in the program has all the right information/is spelled correctly.
//Parameter: Ifstream to input the file information, the name of the file, and the function of the file.
//Return: Valid file input.

string ValidFileInput(ifstream &inputfile, string name, string function) {
	while (true) {
		cout << "\nPlease enter " << name << function << ": ";
		string name;
		cin >> name;
		inputfile.open(name.c_str());

		if (!inputfile) {
			cout << "\n" << name << " is not a valid input.\n";
			cout
					<< "Please check to see if the file name is spelled correctly and if the contents are in the correct format.";
		} else {
			return name;
		}
	}
}

//Function Name: InputStudentInfoManually
//Purpose: The purpose of this function is to take input student information into the array through a user manually typing the information in.
//Parameter: The array that the information will be entered in to and the number of students whose information being entered into the array.
//Return: N/A.

void InputStudentInfoManually(StudentType students[], int length) {
	for (int i = 0; i < length; i++) {
		cout << "\nStudent No." << i + 1 << endl;
		cout << "Please enter the student's ID: ";
		cin >> students[i].studentID;
		cout << "Please enter the student's first name: ";
		cin >> students[i].studentFName;
		cout << "Please enter the student's last name: ";
		cin >> students[i].studentLName;
		students[i].testscore = ValidNumericalInput("a test s"
				"core", " for this student", 0, 100);
		students[i].lettergrade = TestScoreToLetterGrade(students[i].testscore);
	}
}
//Function Name: initialize
//Purpose: The purpose of this function is import the data from the file to the array.
//Parameter: Ifstream to input the file information, the array the information will be entered into, and the number of students.
//Return: N/A.

void initialize(ifstream &indata, StudentType students[], int length) {
	for (int i = 0; i < length; i++) {
		indata >> students[i].studentID;
		indata >> students[i].studentFName;
		indata >> students[i].studentLName;
		indata >> students[i].testscore;
	}
}

//Function Name: InputStudentInfoFile
//Purpose: The purpose of this function is open and import data from the file that is going to be used in the program.
//Parameter: The array that the file information will be imported to, ifstream to import the data, and the number of students whose information will be used.
//Return: N/A.

void InputStudentInfoFile(StudentType students[], ifstream &inputfile,
		int TOTAL) {
	string inputfilename;
	string outputfilename;

	inputfilename =
			ValidFileInput(inputfile, "the name of the file ",
					"with the student information (in first name / last name / test score format)");
	cout << "\n";
	cout << "The file information has been successfully imported.";

	initialize(inputfile, students, TOTAL);
	for (int i = 0; i < TOTAL; i++) {
		students[i].lettergrade = TestScoreToLetterGrade(students[i].testscore);
	}

	inputfile.close();
	inputfile.clear();

}

//Function Name: TestScoreToLetterGrade
//Purpose: The purpose of this function is to convert test scores to letter grades.
//Parameter: The test scores that need to be converted.
//Return: The letter grade (char) of the converted score.

char TestScoreToLetterGrade(int score) {
	if (score >= 90)
		return 'A';
	else if (score >= 80)
		return 'B';
	else if (score >= 70)
		return 'C';
	else if (score >= 60)
		return 'D';
	else
		return 'F';
}

//Function Name: HighestScore
//Purpose: The purpose of this function is to find the highest score in the student information given.
//Parameter: The array of student information and the number of students whose information being entered into the array.
//Return: The highest score in the array.

int HighestScore(StudentType students[], int length) {
	int highscore = students[0].testscore;
	for (int i = 1; i < length; ++i) {
		if (highscore < students[i].testscore) {
			highscore = students[i].testscore;
		}
	}
	return highscore;
}

//Function Name: OutputHighestScore
//Purpose: The purpose of this function is to print/import the highest score and the names of the students with said score.
//Parameter: The array of student information, ostream to decide whether or not the code will print to the console or import to the output file, the highest score in the array, and the number of students whose information being entered into the array.
//Return: N/A

void OutputHighestScore(StudentType students[], ostream &output,
		int highestscore, int length) {
	output
			<< "\nThe highest test score in the data entered into the program is "
			<< highestscore << ".\n";
	output << "The student(s) who have the highest score is/are:\n";
	for (int i = 0; i < length; i++) {
		if (students[i].testscore == highestscore) {
			output << students[i].studentFName << "\n";
		}
	}
}

//Function Name: OutputLetterGrade
//Purpose: The purpose of this function is to print/import the array with the converted letter grades. It will also print a sorted array if applicable.
//Parameter: The array of student information and the number of students whose information being entered into the array, ostream to output the information to the console/import the data to the output file, the number of students, and the details of the sorting information (if applicable).
//Return: N/A

void OutputLetterGrade(StudentType students[], ostream &output, int length,
		string sort) {
	output
			<< "\nThe following is student information with each students' respective letter grade"
			<< sort << ": ";
	output << setw(16) << std::left << "\nStudent ID" << setw(12) << std::left
			<< "Last Name" << setw(10) << std::left << "  First Name"
			<< setw(10) << std::left << "  Test Score" << setw(10) << std::left
			<< " Letter Grade\n";
	for (int i = 0; i < length; i++) {
		output << setw(15) << std::left << students[i].studentID << setw(14)
				<< std::left << students[i].studentLName << setw(12)
				<< std::left << students[i].studentFName << setw(11)
				<< std::left << students[i].testscore << setw(10) << std::left
				<< students[i].lettergrade << "\n";
	}
}

//Function Name: Sort_FName
//Purpose: The purpose of this function is to sort the given student data by first name.
//Parameter: The array with the information of the students, the number of students.
//Return: N/A

void Sort_FName(StudentType students[], int len) {
	int n = len;
	do {
		int newn = 0;
		for (int i = 1; i < n; ++i) {
			if (students[i - 1].studentFName > students[i].studentFName) {
				StudentType tmp = students[i];
				students[i] = students[i - 1];
				students[i - 1] = tmp;
				newn = i;
			}
		}
		n = newn;
	} while (n > 1);
}

//Function Name: Sort_LName
//Purpose: The purpose of this function is to sort the given student data by last name.
//Parameter: The array with the information of the students, the number of students.
//Return: N/A

void Sort_LName(StudentType students[], int len) {
	int n = len;
	do {
		int newn = 0;
		for (int i = 1; i < n; ++i) {
			if (students[i - 1].studentLName > students[i].studentLName) {
				StudentType tmp = students[i];
				students[i] = students[i - 1];
				students[i - 1] = tmp;
				newn = i;
			}
		}
		n = newn;
	} while (n > 1);
}

//Function Name: Sort_TestScore
//Purpose: The purpose of this function is to sort the given student data by test score.
//Parameter: The array with the information of the students, the number of students.
//Return: N/A

void Sort_TestScore(StudentType students[], int len) {
	int n = len;
	do {
		int newn = 0;
		for (int i = 1; i < n; ++i) {
			if (students[i - 1].testscore < students[i].testscore) {
				StudentType tmp = students[i];
				students[i] = students[i - 1];
				students[i - 1] = tmp;
				newn = i;
			}
		}
		n = newn;
	} while (n > 1);
}

//Function Name: Sort_StudentID
//Purpose: The purpose of this function is to sort the given student data by their student ID.
//Parameter: The array with the information of the students, the number of students.
//Return: N/A

void Sort_StudentID(StudentType students[], int len) {
	int n = len;
	do {
		int newn = 0;
		for (int i = 1; i < n; ++i) {
			if (students[i - 1].studentID > students[i].studentID) {
				StudentType tmp = students[i];
				students[i] = students[i - 1];
				students[i - 1] = tmp;
				newn = i;
			}
		}
		n = newn;
	} while (n > 1);
}

//Function Name: Intro
//Purpose: The purpose of this function is to display the array and the menu.
//Parameter: N/A
//Return: N/A

void Intro() {
	cout
			<< "\nThe following functions can be executed:\n"
					"1. Converting the given test scores into letter grade form\n"
					"2. Finding and printing the highest test score(s) and the names of students with the highest test scores\n"
					"3. Sorting the student information alphabetically by first name\n"
					"4. Sorting the student information alphabetically by last name\n"
					"5. Sorting the student information from highest to lowest test score\n"
					"6. Sorting the student information from highest to lowest student ID";
}

//Function Name: WhetherRunAgain
//Purpose: The purpose of this function is to ask the user if they would like to use the program again.
//Parameter: N/A
//Return: True (if the user wants to run the program again) or false (if they do not want to run the program again).

bool WhetherRunAgain() {
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

//Function Name: Prompt
//Purpose: The purpose of this function is to start the program.
//Parameter: N/A
//Return: Returns 1 or 2 depending on which option the user would like to use to enter information in the the program.

int Prompt() {
	int option;
	cout
			<< "This program is used to perform various tasks given students' first names, last names, and test scores.\n";
	cout << "The program can accept information in two ways:\n"
			"1. Importing information through a text file\n"
			"2. Manually inputting students' information by hand\n";
	option = ValidNumericalInput("the option",
			" you would like to use to enter information", 1, 2);
	return option;
}

//Function Name: main
//Purpose: The purpose of this function is to start the program.
//Parameter: n/a
//Return: Returns zero or nonzero value which indicates if the program runs smoothly or if there are any problems.

int main() {
	StudentType Students[20];
	const int TOTAL = 20;
	do {
		ifstream inputfile;
		ofstream outputfile;

		string name;
		name = "sdataoutput";
		int answer;
		answer = Prompt();

		if (answer == 1) {
			InputStudentInfoFile(Students, inputfile, TOTAL);
			outputfile.open(name.c_str());

		} else if (answer == 2) {
			InputStudentInfoManually(Students, TOTAL);
		} else {
			//Users of the program shouldn't be able to access this section because function inside Prompt() limits answers
			cout << "Program error. Please try again.";
		}

		ostream &outputtype = (answer == 1) ? outputfile : cout;

		Intro();
		int option;
		option = ValidNumericalInput("the option",
				" you would like to select in this program", 1, 6);
		if (option == 1) {
			string sort;
			sort = "";
			OutputLetterGrade(Students, outputtype, TOTAL, sort);
		} else if (option == 2) {
			int high_score;
			high_score = HighestScore(Students, TOTAL);
			OutputHighestScore(Students, outputtype, high_score, TOTAL);
		} else if (option == 3) {
			Sort_FName(Students, TOTAL);
			string sort;
			sort = ","
					" sorted by first name (A to Z)";
			OutputLetterGrade(Students, outputtype, TOTAL, sort);
		} else if (option == 4) {
			Sort_LName(Students, TOTAL);
			string sort;
			sort = ", sorted by last name (A to Z)";
			OutputLetterGrade(Students, outputtype, TOTAL, sort);
		} else if (option == 5) {
			Sort_TestScore(Students, TOTAL);
			string sort;
			sort = ", sorted by test score (highest to lowest)";
			OutputLetterGrade(Students, outputtype, TOTAL, sort);
		} else if (option == 6) {
			Sort_StudentID(Students, TOTAL);
			string sort;
			sort = ", sorted by student ID (lowest to highest)";
			OutputLetterGrade(Students, outputtype, TOTAL, sort);
		} else {
			//Users of the program shouldn't be able to access this section
			cout << "Program error. Please try again.";
		}

		if (answer == 1) {
			outputfile.close();
			cout
					<< "\nThe information has successfully been written to the file.";
		}

	} while (WhetherRunAgain() == true);
	return 0;
}
