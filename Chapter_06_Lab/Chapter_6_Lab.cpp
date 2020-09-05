// Name: Chapter_6_Lab (Converting Time)
// Author: Meg Hsu
// Due Date: 6 July 2020
// Description: This is a program that allows you to convert time in twelve and twenty four hour notation into other notations of time.

#include <iostream>
#include<iomanip>
using namespace std;

//Function Name: output12
//Purpose: The purpose of this function is to output the original time and the time that has been converted as well.
//Parameter: hours, minutes, seconds, and AM or PM
//Return: n/a

//setfill and setw are used for formatting the output in hh:mm:ss format.
void output12(int hour, int minute, int second, string am_pm) {
	if (am_pm == "am" or am_pm == "AM" or am_pm == "Am") {
		cout << "The time " << setfill('0') << setw(2) << hour
				<< ":" << setfill('0') << setw(2) << minute << ":"
				<< setfill('0') << setw(2) << second << " " << am_pm
				<< " in 12-hour format is " << setfill('0')
				<< setw(2) << hour << ":" << setfill('0')
				<< setw(2) << minute << ":" << setfill('0')
				<< setw(2) << second << " in 24-hour format.";
	}
	if (am_pm == "pm" or am_pm == "PM" or am_pm == "Pm") {
		cout << "The time " << setfill('0') << setw(2) << hour
				<< ":" << setfill('0') << setw(2) << minute << ":"
				<< setfill('0') << setw(2) << second << " " << am_pm
				<< " in 24-hour format is " << setfill('0')
				<< setw(2) << (hour + 12) << ":" << setfill('0')
				<< setw(2) << minute << ":" << setfill('0')
				<< setw(2) << second << " in 24-hour format.";
	}
}

//Function Name: output24
//Purpose: The purpose of this function is to output the original time and the time that has been converted as well.
//Parameter: hours, minutes, and seconds
//Return: n/a

void output24(int hour, int minute, int second) {
	if (hour > 12) {
		cout << "The time " << setfill('0') << setw(2) << hour
				<< ":" << setfill('0') << setw(2) << minute << ":"
				<< setfill('0') << setw(2) << second
				<< " in 24-hour format is " << setfill('0')
				<< setw(2) << (hour - 12) << ":" << setfill('0')
				<< setw(2) << minute << ":" << setfill('0')
				<< setw(2) << second << " PM in 12-hour format.";
	}
	if (hour <= 12) {
		cout << "The time " << setfill('0') << setw(2) << hour
				<< ":" << setfill('0') << setw(2) << minute << ":"
				<< setfill('0') << setw(2) << second
				<< " in 24-hour format is " << setfill('0')
				<< setw(2) << hour << ":" << setfill('0')
				<< setw(2) << minute << ":" << setfill('0')
				<< setw(2) << second << " AM in 12-hour format.";
	}
}

//Function Name: get_value
//Purpose: The purpose of this function is to ensure that the value entered (hours/minutes/seconds) are valid.
//Parameter: name of the measurements in the program, maximum amount of the measurement entered, minimum amount of the measurement entered
//Return: valid measurements

//This function takes integers called upper and lower to define which values are correct depending on the situation.
int get_value(string name, int lower, int upper) {
	while (true) {
		cout << "Please enter a measurement for " << name << ": ";
		int value;
		cin >> value;
		if (value < lower or value > upper) {
			cout << value << " is not a valid measurement for " << name
					<< ".";
			cout << " Please enter a number between " << lower << " and "
					<< upper << "\n";
		} else {
			return value;
		}
	}
}

//Function Name: ampm
//Purpose: The purpose of this function is to ensure that the information entered is valid.
//Parameter: name of the measurements in the program.
//Return: valid type of time (AM or PM)

string ampm(string name) {
	while (true) {
		cout << "Please enter either " << name << ": ";
		string value;
		cin >> value;
		if (value != "am" && value != "AM" && value != "Am" && value != "aM"
				&& value != "pm" && value != "PM" && value != "Pm"
				&& value != "pM") {
			cout << value << " is not a valid input for " << name << ".";
			cout << " Please enter either AM or PM.\n`";
		} else {
			return value;
		}
	}
}

//Function Name: twelvetwentyfour
//Purpose: The purpose of this function is to convert time from 12 to 24 hour notation.
//Parameter: n/a
//Return: n/a

void twelvetotwentyfour() {
	int twelveh_hour, twelveh_minute, twelveh_second;
	string am_pm, time;
	cout << "This option converts time from 12-hour notation to 24-hour notation.\n";
	twelveh_hour = get_value("hours", 1, 12);
	twelveh_minute = get_value("minutes", 0, 59);
	twelveh_second = get_value("seconds", 0, 59);
	cout << "The time that has been input is " << setfill('0')
			<< setw(2) << twelveh_hour << ":" << setfill('0')
			<< setw(2) << twelveh_minute << ":" << setfill('0')
			<< setw(2) << twelveh_second << ". Is it in AM or PM? ";
	am_pm = ampm("AM or PM");
	output12(twelveh_hour, twelveh_minute, twelveh_second, am_pm);
}

//Function Name: twentyfourtotwelve
//Purpose: The purpose of this function is to convert time from 24 to 12 hour notation.
//Parameter: n/a
//Return: n/a

void twentyfourtotwelve() {
	int twentyfourh_hour, twentyfourh_minute, twentyfourh_second;
	string time;
	cout << "This option converts time from 24-hour notation to 12-hour notation.\n";
	twentyfourh_hour = get_value("hours", 0, 23);
	twentyfourh_minute = get_value("minutes", 0, 59);
	twentyfourh_second = get_value("seconds", 0, 59);
	output24(twentyfourh_hour, twentyfourh_minute, twentyfourh_second);

}

//Function Name: intro
//Purpose: The purpose of this function is to display the menu.
//Parameter: n/a
//Return: n/a

void intro() {
	cout
			<< "This program is used to convert time from 12-hour notation to 24-hour notation and "
					"vice versa. \nPlease enter select which option you would like to use:\n"
					"1. Convert from 12-hour notation to 24-hour notation\n"
					"2. Convert from 24-hour notation to 12-hour notation\n"
					"3. Quit program\n\n";
}

//Function Name: main
//Purpose: The purpose of this function is to start the program.
//Parameter: n/a
//Return: Returns zero or nonzero value which indicates if the program runs smoothly or if there are any problems.

int main() {
	while (true) {
		intro();
		cout << "Which select which option you would like to use: ";
		int answer;
		cin >> answer;
		if (answer == 1) {
			twelvetotwentyfour();
		}
		if (answer == 2) {
			twentyfourtotwelve();
		}
		if (answer == 3) {
			return 0;
		}
		if (3 < answer or answer < 1) {
			cout
					<< "This is an invalid value. Please enter a number that corresponds to the options given.";
		}

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
