// Name: Chapter_8_and_9_Lab (Recording and Sorting Student Information in an Array)
// Author: Meg Hsu
// Due Date: 27 July 2020
// Description: This is a program that allows you to input information into an array and do various computations as well as sort the data entered.

#include<iostream>
#include <iomanip>
#include<string>
#include <fstream>
#include <algorithm>
using namespace std;

struct StudentType {
	string studentFName;
	string studentLName;
	int testscore;
	char lettergrade;
};

//Function Name: ValidInput
//Purpose: The purpose of this function is ensure that all values entered into the program are valid inputs.
//Parameter: The names of the input, the function of the input, the maximum and minimum values for the inputs.
//Return: Valid inputs.

double ValidInput(string name, string function, int lower, int upper) {
	while (true) {
		cout << "Please enter " << name << function << ": ";
		double value;
		cin >> value;
		if (value < lower or value > upper) {
			cout << value << " is not a valid input.\n";
			cout << " Please enter a number between" << lower << " and "
					<< upper << ".\n";
		} else {
			return value;
		}
	}
}

//The following function is declared here because it is referenced in the following function.
char TestScoreToLetterGrade(int);

//Function Name: InputStudentInfoManually
//Purpose: The purpose of this function is to input student information into the array.
//Parameter: The array that the information will be entered in to and the number of students whose information being entered into the array.
//Return: N/A.

void InputStudentInfoManually(StudentType students[], int length) {
	for (int i = 0; i < length; i++) {
		cout << "\nStudent No." << i + 1 << endl;
		cout << "Please enter the student's first name: ";
		cin >> students[i].studentFName;
		cout << "Please enter the student's last name: ";
		cin >> students[i].studentLName;
		students[i].testscore = ValidInput("a test s"
				"core", " for this student", 0, 100);
		students[i].lettergrade = TestScoreToLetterGrade(students[i].testscore);
	}
}

void initialize(ifstream &indata, StudentType students[], int length) {
	for (int i = 0; i < length; i++) {
		//seperator by comma
		indata >> students[i].studentFName;
		indata >> students[i].studentLName;
		indata >> students[i].testscore;

//what does this do lol
//list[i].saleByQuarter[quarter] = 0.0;
//list[i].totalSale = 0.0; }
	}
}

void InputStudentInfoFile(StudentType students[], ifstream inputfile, ofstream outputfile, int TOTAL) {
	string inputfilename;
	string outputfilename;
	cout << "You chose to input information through a file.\n";
	cout
			<< "Please enter the name of the file with the student information in the following format (first name, last name, test score): ";
	cin >> inputfilename;
	cout << "\n";

	inputfile.open(inputfilename.c_str());

	if (!inputfile) {
		cout << "The file cannot be opened."; // change to loop to ask them to enter in name of file again/ask them if they would like to manually input information
		//insert function here to make it run again????
	}

	initialize(inputfile, students, TOTAL);
	inputfile.close();
	inputfile.clear();

//	cout
//			<< "Please enter the name of the file with the student information in the following format (first name, last name, test score): ";
//	cin >> outputfilename;
//	cout << "\n";
//
//	outputfile.open(outputfilename.c_str());

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

//Function Name: PrintHighestScore
//Purpose: The purpose of this function is to print the highest score and the names of the students with said score.
//Parameter: The array of student information, the highest score in the array, and the number of students whose information being entered into the array.
//Return: N/A

void OutputHighestScore(StudentType students[], int highestscore, int length) {
	cout << "\nThe highest test score is " << highestscore << "\n";
	cout << "The student(s) who have the highest score is/are\n";
	for (int i = 0; i < length; i++) {
		if (students[i].testscore == highestscore) {
			cout << students[i].studentFName << "\n";
		}
	}
}

//Function Name: OutputLetterGrade
//Purpose: The purpose of this function is to print the array with the converted letter grades. It will also print a sorted array if applicable.
//Parameter: The array of student information and the number of students whose information being entered into the array.
//Return: N/A

void OutputLetterGrade(StudentType students[], int length) {
	cout << setw(10) << std::left << "\nLast Name" << setw(10) << std::left
			<< "  First Name" << setw(10) << std::left << "  Test Score"
			<< setw(10) << std::left << " Letter Grade\n";
	for (int i = 0; i < length; i++) {
		cout << setw(12) << std::left << students[i].studentLName << setw(12)
				<< std::left << students[i].studentFName << setw(11)
				<< std::left << students[i].testscore << setw(10) << std::left
				<< students[i].lettergrade << "\n";
	}
}

//Function Name: Sort_FName
//Purpose: The purpose of this function is to sort the given student data by first name.
//Parameter: The students who are being sorted.
//Return: True or false, depending on if the students are in the correct order or not.

bool Sort_FName(StudentType a, StudentType b) {
	return a.studentFName < b.studentFName;
}

//Function Name: Sort_LName
//Purpose: The purpose of this function is to sort the given student data by last name.
//Parameter: The students who are being sorted.
//Return: True or false, depending on if the students are in the correct order or not.

bool Sort_LName(StudentType a, StudentType b) {
	return a.studentLName < b.studentLName;
}

//Function Name: Sort_TestScore
//Purpose: The purpose of this function is to sort the given student data by test score.
//Parameter: The students who are being sorted.
//Return: True or false, depending on if the test scores are in the correct order or not.

bool Sort_TestScore(StudentType a, StudentType b) {
	return a.testscore > b.testscore;
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
					"5. Sorting the student information from highest to lowest test score\n";
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

//The following function (SetData) is only used to make testing the program easier. It is not tied to any of the computations/sorting done in the program and will not be in the final version of this code.
void SetData(StudentType &student, string fname, string lname, int score) {
	student.studentFName = fname;
	student.studentLName = lname;
	student.testscore = score;
	student.lettergrade = TestScoreToLetterGrade(score);
}

int Prompt() {
	int option;
	cout
			<< "This program is used to perform various tasks given students' first names, last names, and test scores.\n";
	cout << "The program can accept information in two ways:\n"
			"1. Importing information through a text file\n"
			"2. Manually inputting students' information by hand\n";
	option = ValidInput("the option",
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
		int answer;
		answer = Prompt();

		if (answer == 1) {
			InputStudentInfoFile(Students, inputfile, outputfile, TOTAL);
		} else if (answer == 2) {
			InputStudentInfoManually(Students, TOTAL);
		}

			Intro();
		int option;
		option = ValidInput("the option",
				" you would like to select in this program", 1, 6);
		if (option == 1) {
			OutputLetterGrade(Students, TOTAL);
		} else if (option == 2) {
			int high_score;
			high_score = HighestScore(Students, TOTAL);
			OutputHighestScore(Students, high_score, TOTAL);
		} else if (option == 3) {
			sort(Students, Students + TOTAL, Sort_FName);
			cout
					<< "\nThe following student information is sorted by first name (A to Z):";
			OutputLetterGrade(Students, TOTAL);
		} else if (option == 4) {
			sort(Students, Students + TOTAL, Sort_LName);
			cout << "\nThe following student information is sorted by last"
					" name (A to Z):";
			OutputLetterGrade(Students, TOTAL);
		} else if (option == 5) {
			sort(Students, Students + TOTAL, Sort_TestScore);
			cout
					<< "\nThe following student information is sorted by test score (highest to lowest):";
			OutputLetterGrade(Students, TOTAL);
		} else {
			//Users of the program shouldn't be able to access this section
			cout << "Program error. Please try again.";
		}

	} while (WhetherRunAgain() == true);
	return 0;
}

//Student Information for Reference:
//SetData(Students[0], "Duckey", "Donald", 85);
//SetData(Students[1], "Goof", "Goofy", 89);
//SetData(Students[2], "Brave", "Balto", 93);
//SetData(Students[3], "Snow", "Smitn", 93);
//SetData(Students[4], "Alice", "Wonderful", 89);
//SetData(Students[5], "Samina", "Akthar", 85);
//SetData(Students[6], "Simba", "Green", 95);
//SetData(Students[7], "Donald", "Egger", 90);
//SetData(Students[8], "Brown", "Deer", 86);
//SetData(Students[9], "Johny", "Jackson", 95);
//SetData(Students[10], "Greg", "Gupta", 75);
//SetData(Students[11], "Samuel", "Happy", 80);
//SetData(Students[12], "Danny", "Arora", 80);
//SetData(Students[13], "Sleepy", "June", 70);
//SetData(Students[14], "Amy", "Cheng", 83);
//SetData(Students[15], "Shelly", "Malik", 95);
//SetData(Students[16], "Chelsea", "Tomek", 95);
//SetData(Students[17], "Angela", "Clodfelter", 95);
//SetData(Students[18], "Allison", "Nields", 95);
//SetData(Students[19], "Lance", "Norman", 88);
