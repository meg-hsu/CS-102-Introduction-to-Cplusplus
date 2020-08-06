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
};

//Declare all functions here
double ValidNumericalInput(string name, string function, int lower, int upper);
void InputStudentInfoManually(StudentType students[], int length);
void initialize(ifstream &indata, StudentType students[], int length);
void InputStudentInfoFile(StudentType students[], ifstream &inputfile, int TOTAL);
char TestScoreToLetterGrade(int score);
int HighestScore(StudentType students[], int length);
void OutputHighestScore(StudentType students[], ostream &output, int highestscore, int length);
void OutputLetterGrade(StudentType students[], ostream &output, int length, string sort);
bool Sort_FName(StudentType a, StudentType b);
bool Sort_LName(StudentType a, StudentType b);
bool Sort_TestScore(StudentType a, StudentType b);
void Intro();
bool WhetherRunAgain();
int Prompt();

//Function Name: ValidInput
//Purpose: The purpose of this function is ensure that all values entered into the program are valid inputs.
//Parameter: The names of the input, the function of the input, the maximum and minimum values for the inputs.
//Return: Valid inputs.

double ValidNumericalInput(string name, string function, int lower, int upper) {
    while (true) {
        cout << "Please enter " << name << function << ": ";
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

string ValidFileInput(ifstream &inputfile, string name, string function){
    while (true) {
        cout << "\nPlease enter " << name << function << ": ";
        string name;
        cin >> name;
        inputfile.open(name.c_str());

        if (!inputfile) {
            cout << "\n" << name << " is not a valid input.\n";
            cout << "Please check to see if the file name is spelled correctly and if the contents are in the correct format.";
        } else {
            return name;
        }
    }
}

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
        students[i].testscore = ValidNumericalInput("a test s"
                "core", " for this student", 0, 100);
        students[i].lettergrade = TestScoreToLetterGrade(students[i].testscore);
    }
}

void initialize(ifstream &indata, StudentType students[], int length) {
    for (int i = 0; i < length; i++) {
        indata >> students[i].studentFName;
        indata >> students[i].studentLName;
        indata >> students[i].testscore;
    }
}

void InputStudentInfoFile(StudentType students[], ifstream &inputfile, int TOTAL) {
    string inputfilename;
    string outputfilename;

    inputfilename = ValidFileInput(inputfile, "the name of the file ", "with the student information (in first name / last name / test score format)");
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

//Function Name: PrintHighestScore
//Purpose: The purpose of this function is to print the highest score and the names of the students with said score.
//Parameter: The array of student information, the highest score in the array, and the number of students whose information being entered into the array.
//Return: N/A

void OutputHighestScore(StudentType students[], ostream &output, int highestscore, int length) {
    output << "\nThe highest test score is " << highestscore << "\n";
    output << "The student(s) who have the highest score is/are:\n";
    for (int i = 0; i < length; i++) {
        if (students[i].testscore == highestscore) {
            output
			<< students[i].studentFName << "\n";
        }
    }
}

//Function Name: OutputLetterGrade
//Purpose: The purpose of this function is to print the array with the converted letter grades. It will also print a sorted array if applicable.
//Parameter: The array of student information and the number of students whose information being entered into the array.
//Return: N/A

void OutputLetterGrade(StudentType students[], ostream &output, int length, string sort) {
	output << "\nThe following is student information with each students' respective letter grade" << sort << ": ";
    output << setw(10) << std::left << "\nLast Name" << setw(10) << std::left
            << "  First Name" << setw(10) << std::left << "  Test Score"
            << setw(10) << std::left << " Letter Grade\n";
    for (int i = 0; i < length; i++) {
        output << setw(12) << std::left << students[i].studentLName << setw(12)
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

int Prompt(){
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

        ostream& outputtype = (answer == 1) ? outputfile : cout;

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
            sort(Students, Students + TOTAL, Sort_FName);
            string sort;
            sort = ","
            		" sorted by first name (A to Z)";
            OutputLetterGrade(Students, outputtype, TOTAL, sort);
        } else if (option == 4) {
            sort(Students, Students + TOTAL, Sort_LName);
            string sort;
            sort = ", sorted by last name (A to Z)";
            OutputLetterGrade(Students, outputtype, TOTAL, sort);
        } else if (option == 5) {
            sort(Students, Students + TOTAL, Sort_TestScore);
            string sort;
            sort = ", sorted by test score (highest to lowest)";
            OutputLetterGrade(Students, outputtype, TOTAL, sort);
        } else {
            //Users of the program shouldn't be able to access this section
            cout << "Program error. Please try again.";
        }

        if (answer == 1){
        	outputfile.close();
        	cout << "\nThe information has successfully been written to the file.";
        }

    } while (WhetherRunAgain() == true);
    return 0;
}

//Student Information for Reference:
//SetData(Students[0]1 , "Duckey", "Donald", 85);
//SetData(Students[1]2 , "Goof", "Goofy", 89);
//SetData(Students[2]3, "Brave", "Balto", 93);
//SetData(Students[3]4, "Snow", "Smitn", 93);
//SetData(Students[4]5, "Alice", "Wonderful", 89);
//SetData(Students[5]6, "Samina", "Akthar", 85);
//SetData(Students[6]7, "Simba", "Green", 95);
//SetData(Students[7]8, "Donald", "Egger", 90);
//SetData(Students[8]9, "Brown", "Deer", 86);
//SetData(Students[9]10, "Johny", "Jackson", 95);
//SetData(Students[10]11, "Greg", "Gupta", 75);
//SetData(Students[11]12, "Samuel", "Happy", 80);
//SetData(Students[12]13, "Danny", "Arora", 80);
//SetData(Students[13]14, "Sleepy", "June", 70);
//SetData(Students[14]15, "Amy", "Cheng", 83);
//SetData(Students[15]16, "Shelly", "Malik", 95);
//SetData(Students[16]17, "Chelsea", "Tomek", 95);
//SetData(Students[17]18, "Angela", "Clodfelter", 95);
//SetData(Students[18]19, "Allison", "Nields", 95);
//SetData(Students[19]20, "Lance", "Norman", 88);
