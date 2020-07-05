// Name: Meg Hsu
// Description: This is a program that allows you to convert time in twelve and twenty four hour notation into other notations of time.
// Course: CS 102 - Introduction to Programming C++
// Due Date: 6 July 2020

#include <iostream>
#include<iomanip>
#include <time.h>
//using namespace std;

void output12(int hour, int minute, int second, std::string am_pm) {
	if (am_pm == "am" or am_pm == "AM" or am_pm == "Am") {
		std::cout << "The time " << hour << ":" << minute << ":" << second
				<< " " << am_pm << " in twelve hour format is " << hour << ":"
				<< minute << ":" << second << " in twenty four hour format.";
	}
	if (am_pm == "pm" or am_pm == "PM" or am_pm == "Pm") {
		std::cout << "The time " << hour << ":" << minute << ":" << second
				<< " " << am_pm << " in twelve hour format is " << (hour + 12)
				<< ":" << minute << ":" << second
				<< " in twenty four hour format.";
	}
}

void output24(int hour, int minute, int second) {
	if (hour > 12) {
		std::cout << "The time " << hour << ":" << minute << ":" << second
				<< " in twenty four hour format is " << (hour - 12) << ":"
				<< minute << ":" << second << " PM in twelve four hour format.";
	}
	if (hour <= 12) {
		std::cout << "The time " << hour << ":" << minute << ":" << second
				<< " in twenty four hour format is " << (hour - 12) << ":"
				<< minute << ":" << second << " AM in twelve hour format.";
	}
}

void twelvetotwentyfour(std::string name) {
	int twelveh_hour, twelveh_minute, twelveh_second;
	std::string am_pm, time;
	std::cout
			<< "This option converts time from 12-hour notation to 24-hour notation.\n"
					"Please enter in the hour value for the time that will be converted: ";
	std::cin >> twelveh_hour;
	std::cout
			<< "Please enter in the minute value for the time that will be converted: ";
	std::cin >> twelveh_minute;
	std::cout
			<< "Please enter in the second value for the time that will be converted: ";
	std::cin >> twelveh_second;
	std::cout << "The time that has been input is " << twelveh_hour << ":"
			<< twelveh_minute << ":" << twelveh_second
			<< ". Is it in AM or PM? ";
	std::cin >> am_pm;
	output12(twelveh_hour, twelveh_minute, twelveh_second, am_pm);
}

void twentyfourtotwelve(std::string name) {
	int twentyfourh_hour, twentyfourh_minute, twentyfourh_second;
	std::string time;
	std::cout
			<< "This option converts time from 12-hour notation to 24-hour notation.\n"
					"Please enter in the hour value for the time that will be converted: ";
	std::cin >> twentyfourh_hour;
	std::cout
			<< "Please enter in the minute value for the time that will be converted: ";
	std::cin >> twentyfourh_minute;
	std::cout
			<< "Please enter in the second value for the time that will be converted: ";
	std::cin >> twentyfourh_second;
	output24(twentyfourh_hour, twentyfourh_minute, twentyfourh_second);

// << std::setfill('0') << std::setw(2)

}

void intro() {
	std::cout
			<< "This program is used to convert time from 12-hour notation to 24-hour notation and "
					"vice versa. \nPlease enter select which option you would like to use:\n"
					"1. Convert from 12-hour notation to 24-hour notation\n"
					"2. Convert from 24-hour notation to 12-hour notation\n"
					"3. Quit program\n";

//        if (answer > 3 or answer < 1) {
//            std::cout
//                    << "This is an invalid value. Please enter a number that corresponds to the options given.";
}

int main() {
	while (true) {
		intro();
		std::cout << "Which select which option you would like to use: ";
			int answer;
			std::cin >> answer;
			if (answer == 1) {
				twelvetotwentyfour("a");
			}
			if (answer == 2) {
				twentyfourtotwelve("a");
			}
			if (answer == 3) {
				return 0;
			}

		std::cout << "\nWould you like to run this program again? (y/n)";
		std::string yesorno;
		std::cin >> yesorno;
		if (yesorno == "Y" or yesorno == "y") {
		}
		if (yesorno == "N" or yesorno == "n") {
			break;
		}
	}
	return 0;
}
//    std::cout
//            << "This program is used to convert time from 12-hour notation to 24-hour notation and "
//                    "vice versa. \nPlease enter select which option you would like to use:\n"
//                    "1. Convert from 12-hour notation to 24-hour notation\n"
//                    "2. Convert from 24-hour notation to 12-hour notation\n"
//                    "3. Quit program\n";
//    std::cout << "Which select which option you would like to use: ";
//    int answer;
//    std::cin >> answer;
//    if (answer == 1) {
//        answer = twelvetotwentyfour("a");
//    }
//    if (answer == 2) {
//        answer = twentyfourtotwelve("a");
//    }
//    if (answer == 3) {
//        return 0;
//    }
//    if (answer > 3 or answer < 1) {
//        std::cout
//                << "This is an invalid value. Please enter a number that corresponds to the options given.";
//    }

